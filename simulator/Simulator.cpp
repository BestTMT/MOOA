#include "include/Simulator.h"
#include "include/io_utils.h"
#include "include/sharedspice.h"

#include <dlfcn.h> /* to load libraries*/
#include <unistd.h>
#include <ctype.h>
#include <fstream>

#include "NumCpp.hpp"
#include <cstdlib>

#include <fstream>
#include <iostream>
#include <cmath>


typedef void *  funptr_t;

bool no_bg = true;
bool not_yet = true;
bool will_unload = false;
bool error_ngspice = false;

int cieq(register char *p, register char *s); //method claims
int ciprefix(const char *p, const char *s);  //method claims
int getLine(char *prmpt, char *buff, size_t sz);  //method claims

/* callback functions used by ngspice */
int
ng_getchar(char* outputreturn, int ident, void* userdata); //method claims

int
ng_getstat(char* outputreturn, int ident, void* userdata);//method claims

int
ng_thread_runs(bool noruns, int ident, void* userdata);//method claims

ControlledExit ng_exit;  // //method claims by type define
SendData ng_data;   //method claims by type define
SendInitData ng_initdata;   //method claims by type define


//int vecgetnumber = 0;
//double v2dat;
//static bool has_break = false;
char comd[2048];

/* functions exported by ngspice */
// funptr_t ngSpice_Init_handle = NULL;
// funptr_t ngSpice_Command_handle = NULL;
// funptr_t ngSpice_Circ_handle = NULL;
// funptr_t ngSpice_CurPlot_handle = NULL;
// funptr_t ngSpice_AllVecs_handle = NULL;
// funptr_t ngSpice_GVI_handle = NULL;

// typedef void *  funptr_t;
// int (*ngSpice_Init_handle)(...) = NULL; // function pointer
// int (*ngSpice_Command_handle)(...) = NULL; // function pointer
// int (*ngSpice_Circ_handle) = NULL; // function pointer
// void (*ngSpice_CurPlot_handle) = NULL;  // function pointer
// void (*ngSpice_AllVecs_handle) = NULL; // function pointer
// void (*ngSpice_GVI_handle) = NULL; // function pointer
// bool (*ngSpice_running_handle)() = NULL;

void * ngdllhandle = NULL; //function pointer.  指向函数的指针

Simulator::Simulator() : m_nColor(0)
{
}
 
void Simulator::SetColor(int color)
{
    m_nColor = color;
}
 
int Simulator::GetColor(void)
{
    return m_nColor;
}



void Simulator::doSimulation(double *xreal, double *obj){
    auto start = std::chrono::system_clock::now();
    char *errmsg = NULL, *loadstring;
    int ret;
    bool status_check;

    char *curplot, *vecname;
    char ** circarray;
    char **vecarray;
    pvector_info myvec;

    string ac_schematic_demo = "/home/asus/Desktop/cplusplushub/cmakeSizing/resource/tempfiles/diffamp_ac_demo.sp";
    string ac_schematic_original_file = "/home/asus/Desktop/cplusplushub/cmakeSizing/resource/tb_template/diffamp_ac_demo.sp";
    string ac_output_file = "/home/asus/Desktop/cplusplushub/cmakeSizing/resource/tempfiles/ac_res.txt";
    
    string dc_schematic_demo = "/home/asus/Desktop/cplusplushub/cmakeSizing/resource/tempfiles/diffamp_dc_demo.sp";
    string dc_schematic_original_file = "/home/asus/Desktop/cplusplushub/cmakeSizing/resource/tb_template/diffamp_tran_demo.sp";
    string dc_output_file = "/home/asus/Desktop/cplusplushub/cmakeSizing/resource/tempfiles/tran_res.txt";
    
    string ac_source_schematic_demo = "source " +ac_schematic_demo;
    string dc_source_schematic_demo = "source " +dc_schematic_demo;
    // printf("****************************\n");
    // printf("**  ngspice shared start  **\n");
    // printf("****************************\n");
    // cout << "===================" << endl;

    ret = ngSpice_Init(ng_getchar, ng_getstat,
                               ng_exit, NULL, ng_initdata, ng_thread_runs, NULL);


    error_ngspice = false;
    will_unload = false;

    const char * ac_fn = ac_schematic_original_file.c_str();
    char *ac_fn_char = new char[strlen(ac_fn)+1];
    strcpy(ac_fn_char, ac_fn);
    string ac_schematic_content_str;
    ac_schematic_content_str = sizingrule::readFileIntoString(ac_fn_char);
    // cout <<  ac_schematic_content_str << endl;

    const char * dc_fn = dc_schematic_original_file.c_str();
    char *dc_fn_char = new char[strlen(dc_fn)+1];
    strcpy(dc_fn_char, dc_fn);
    string dc_schematic_content_str;
    dc_schematic_content_str = sizingrule::readFileIntoString(dc_fn_char);
    // cout <<  dc_schematic_content_str << endl;


    // Replace Segments
    // xreal[0]  : mn1_w  mn2_w   xreal[1]  : mn1_l  mn2_l
    // xreal[2]  : mn3_l  mn4_l
    // xreal[3]  : mp1_l  mp2_l
    // xreal[4]
    sizingrule::string_replace(ac_schematic_content_str,"{mn1_w}",std::to_string(xreal[0]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mn1_l}",std::to_string(xreal[1]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mn2_w}",std::to_string(xreal[0]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mn2_l}",std::to_string(xreal[1]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mn3_w}",std::to_string(xreal[4]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mn3_l}",std::to_string(xreal[2]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mn4_w}",std::to_string(xreal[5]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mn4_l}",std::to_string(xreal[2]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mp1_w}",std::to_string(xreal[6]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mp1_l}",std::to_string(xreal[3]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mp2_w}",std::to_string(xreal[7]) + "n");
    sizingrule::string_replace(ac_schematic_content_str,"{mp2_l}",std::to_string(xreal[3]) + "n");


    sizingrule::string_replace(dc_schematic_content_str,"{mn1_w}",std::to_string(xreal[0]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mn1_l}",std::to_string(xreal[1]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mn2_w}",std::to_string(xreal[0]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mn2_l}",std::to_string(xreal[1]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mn3_w}",std::to_string(xreal[4]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mn3_l}",std::to_string(xreal[2]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mn4_w}",std::to_string(xreal[5]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mn4_l}",std::to_string(xreal[2]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mp1_w}",std::to_string(xreal[6]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mp1_l}",std::to_string(xreal[3]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mp2_w}",std::to_string(xreal[7]) + "n");
    sizingrule::string_replace(dc_schematic_content_str,"{mp2_l}",std::to_string(xreal[3]) + "n");

    std::ofstream acschematicfile(ac_schematic_demo, std::ios::out);
    //SIMULATION FILE
    acschematicfile << std::endl;
    acschematicfile << ac_schematic_content_str;
    acschematicfile.close();
    std::ofstream dcschematicfile(dc_schematic_demo, std::ios::out);
    //SIMULATION FILE
    dcschematicfile << std::endl;
    dcschematicfile << dc_schematic_content_str;
    dcschematicfile.close();


    string comdstr = ac_source_schematic_demo;
    strcpy(comd, comdstr.c_str());
    std::ofstream acoutfile(ac_output_file, std::ios::out);
    acoutfile << std::endl;
    acoutfile.close();
    pvector_info vec_info1;
    int MaxLoop = 1;
    for (int i = 0; i<MaxLoop; i++) {
        // cout << "i ==== " << i << endl;
        status_check = ngSpice_running();
        // cout << "status_check ==== " << status_check << endl;

        ret = ngSpice_Command(comd);
        vec_info1 = ngGet_Vec_Info("v(Vout)");
        // char** temp1 = ngSpice_AllPlots();
        // char** temp2 = ngSpice_AllVecs("v(Vout)");
        for (size_t i = 0; i < vec_info1->v_length; i++)
        {
            /* code */
        }
        
        if (ret) {
            /* unload now */
            // dlclose(ngdllhandle);
            ngdllhandle = NULL;
            printf("ngspice unloaded\n\n");
            getLine("Press any key to exit: ", comd, sizeof(comd));
            break;
        }
       
    }


    string dc_comdstr = dc_source_schematic_demo;
    strcpy(comd, dc_comdstr.c_str());
    std::ofstream dcoutfile(dc_output_file, std::ios::out);
    dcoutfile << std::endl;
    dcoutfile.close();
    pvector_info vec_info2;
    for (int i = 0; i<MaxLoop; i++) {
        // cout << "i ==== " << i << endl;
        status_check = ngSpice_running();
        // cout << "status_check ==== " << status_check << endl;

        ret = ngSpice_Command(comd);
        vec_info2 = ngGet_Vec_Info("v(Vout)");
        // char** temp1 = ngSpice_AllPlots();
        // char** temp2 = ngSpice_AllVecs("v(Vout)");
        for (size_t i = 0; i < vec_info2->v_length; i++)
        {
            /* code */
        }
        
        if (ret) {
            /* unload now */
            // dlclose(ngdllhandle);
            ngdllhandle = NULL;
            printf("ngspice unloaded\n\n");
            getLine("Press any key to exit: ", comd, sizeof(comd));
            break;
        }
       
    }



    std::ifstream file(ac_output_file); // 替换为你的文件名
    std::string line;
    std::vector<std::vector<std::string>> columns;
 
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream ss(line);
            std::vector<std::string> row;
            for (int i = 0; i < 2; ++i) {
                std::string column;
                ss >> column;
                row.push_back(column);
            }
            columns.push_back(row);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
        // return 1;
    }

    // auto a = nc::random::randInt<int>({10, 10}, 0, 100);

    nc::NdArray<double> fr = nc::NdArray<double>(1, vec_info1->v_length);
    nc::NdArray<double> fr_real = nc::NdArray<double>(1, vec_info1->v_length);

    // nc::NdArray<double> fr = {1, vec_info1->v_length-1};
    // nc::NdArray<double> fr_real    = { 0.038, 0.194, 0.425, 0.626, 1.253, 2.5, 3.74 };
    // nc::NdArray<double> fr_image = { 0.05, 0.127, 0.094, 0.2122, 0.2729, 0.2665, 0.3317 };
    // auto fr_response = nc::complex (fr_real, fr_image);
    // auto res = nc::interp(x, fr, fr_real);
    // std::cout<< "Test" << std::endl;

 
    // 输出读取的前三列
    // for (const auto& row : columns) {
    for (size_t i = 0; i < columns.size(); i++)
    {
        // for (const auto& column : row) {
        //     std::cout << column << " ";
        // }
        auto row = columns.at(i);
        double temp1 = stod(row.at(0));
        fr.put(i, temp1);
        double temp2 = stod(row.at(1));
        fr_real.put(i, temp2);
    }
    // }

    //#1. calcualte the gain.
    nc::NdArray<double> x    = { 1};
    double gain_res = 20 * log10(abs(nc::interp(x, fr, fr_real).at(0)));
    cout << "The Gain is:" << gain_res << endl;

    obj[0] = abs(gain_res);

    //#2. calculate the unityGainFrequency
    /*
        freq_var : 1-D ndarray
        Frequency points in Hz
        frequencyResponse : 1-D ndarray
        Frequency response points, given as an array of complex numbers
    */

    // amplitudeResponse = np.abs(frequencyResponse)
    // firstBelowUnityIndex = np.min(np.where(amplitudeResponse < 1))
    // initialGuess = freq_var[firstBelowUnityIndex - 1]
    // iteration
    int firstBelowUnityIndex = 0;
    for (auto it = fr_real.begin(); it < fr_real.end(); ++it)
    {   
        // std::cout << *it << " ";
        if (*it< 1)
        {
            break;
        }
        firstBelowUnityIndex ++;
    }
    double initialGuess_unityGainFrequency = fr[firstBelowUnityIndex];

    obj[1] = abs(initialGuess_unityGainFrequency);

    cout << "The initialGuess_unityGainFrequency is:" << initialGuess_unityGainFrequency << endl;

    std::cout << std::endl;

    //#3. calculate the slewrate

    std::ifstream file2(dc_output_file); // 替换为你的文件名
    std::string line2;
    std::vector<std::vector<std::string>> columns2;
 
    if (file2.is_open()) {
        while (std::getline(file2, line2)) {
            std::istringstream ss(line2);
            std::vector<std::string> row;
            for (int i = 0; i < 2; i++) {
                std::string column;
                ss >> column;
                row.push_back(column);
            }
            columns2.push_back(row);
        }
        file2.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
        // return 1;
    }

    nc::NdArray<double> fr2 = nc::NdArray<double>(1, vec_info2->v_length);
    nc::NdArray<double> fr_real2 = nc::NdArray<double>(1, vec_info2->v_length);

    // 输出读取的前三列
    // for (const auto& row : columns) {
    for (size_t i = 0; i < columns2.size(); i++)
    {
        // for (const auto& column : row) {
        //     std::cout << column << " ";
        // }
        auto row = columns2.at(i);
        double temp1 = stod(row.at(0));
        fr2.put(i, temp1);
        double temp2 = stod(row.at(1));
        fr_real2.put(i, temp2);
    }
    // }

    double initialValue = nc::min(fr_real2).at(0);
    double finalValue = nc::max(fr_real2).at(0);
    double precentHigh = 0.6*(finalValue-initialValue)+initialValue;
    double precentLow = 0.1*(finalValue-initialValue)+initialValue;

    // double firstIndexPrecentHgih = np.min(np.where(wave >= precentHigh));
    // double firstIndexPrecentLow = np.min(np.where(wave <= precentLow));
    double firstIndexPrecentHgih = 0;
    for (auto it = fr_real2.begin(); it < fr_real2.end(); ++it)
    {   
        // std::cout << *it << " ";
        if (*it >= precentHigh)
        {
            break;
        }
        firstIndexPrecentHgih ++;
    }

    double firstIndexPrecentLow = 0;
    for (auto it = fr_real2.begin(); it < fr_real2.end(); ++it)
    {   
        // std::cout << *it << " ";
        if (*it <= precentLow)
        {
            break;
        }
        firstIndexPrecentLow ++;
    }

    double slewRateInVPerSecond = (precentHigh-precentLow) / (fr[firstIndexPrecentHgih]-fr[firstIndexPrecentLow]);
    obj[2] = abs(slewRateInVPerSecond);


    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    // std::cout << "1000 circuit NGSPICE simulation by C++: " << std::endl
    //           << "Start time: " << std::ctime(&start_time) 
    //           << std::endl;
 
    // std::cout << "finished computation at " << std::ctime(&end_time)
    //           << "elapsed time: " << elapsed_seconds.count() << "s"
    //           << std::endl;


    // return 0;
}




/* Callback function called from bg thread in ngspice to transfer
   any string created by printf or puts. Output to stdout in ngspice is
   preceded by token stdout, same with stderr.*/
int
ng_getchar(char* outputreturn, int ident, void* userdata)
{   
    // printf("-----------------------");
    // printf("%s\n", outputreturn);
    /* setting a flag if an error message occurred */
    if (ciprefix("stderr Error:", outputreturn))
        error_ngspice = true;
    return 0;
}

/* Callback function called from bg thread in ngspice to transfer
   simulation status (type and progress in percent). */
int
ng_getstat(char* outputreturn, int ident, void* userdata)
{
    // printf("000000000000000000000000");
    // printf("%s\n", outputreturn);
    return 0;
}

/* Callback function called from ngspice upon starting (returns true) or
  leaving (returns false) the bg thread. */
int
ng_thread_runs(bool noruns, int ident, void* userdata)
{
    no_bg = noruns;
    if (noruns)
        printf("\nbg not running\n");
    else
        printf("bg running\n\n");

    return 0;
}

/* Callback function called from bg thread in ngspice if fcn controlled_exit()
   is hit. Do not exit, but unload ngspice. */
int
ng_exit(int exitstatus, bool immediate, bool quitexit, int ident, void* userdata)
{
    /*
        if(quitexit) {
            printf("DNote: Returned from quit with exit status %d\n", exitstatus);
        }
        if(immediate) {
            printf("DNote: Unload ngspice\n");
            ((int * (*)(char*)) ngSpice_Command_handle)("quit");
            dlclose(ngdllhandle);
        }

        else {
            printf("DNote: Prepare unloading ngspice\n");
            will_unload = true;
        }
    */
    return exitstatus;

}

/* Callback function called from bg thread in ngspice once per accepted data point */
int
ng_data(pvecvaluesall vdata, int numvecs, int ident, void* userdata)
{
    /*
        int *ret;

        v2dat = vdata->vecsa[vecgetnumber]->creal;
        if (!has_break && (v2dat > 0.5)) {
        // using signal SIGTERM by sending to main thread, alterp() then is run from the main thread,
        //(not on Windows though!)
    #ifndef _MSC_VER
            if (testnumber == 4)
                pthread_kill(mainthread, SIGTERM);
    #endif
            has_break = true;
        // leave bg thread for a while to allow halting it from main
    #if defined(__MINGW32__) || defined(_MSC_VER)
            Sleep (100);
    #else
            usleep (100000);
    #endif
    //        ret = ((int * (*)(char*)) ngSpice_Command_handle)("bg_halt");
        }
    */
    return 0;
}


/* Callback function called from bg thread in ngspice once upon intialization
   of the simulation vectors)*/
int
ng_initdata(pvecinfoall intdata, int ident, void* userdata)
{
    /*
        int i;
        int vn = intdata->veccount;
        for (i = 0; i < vn; i++) {
            printf("Vector: %s\n", intdata->vecs[i]->vecname);
            // find the location of V(2)
            if (cieq(intdata->vecs[i]->vecname, "V(2)"))
                vecgetnumber = i;
        }
    */
    return 0;
}

/* Unify LINUX and Windows dynamic library handling:
   Add functions dlopen, dlsym, dlerror, dlclose to Windows by
   tranlating to Windows API functions.
*/
// #if defined(__MINGW32__) ||  defined(_MSC_VER)

// void *dlopen(const char *name,int type)
// {
//     return LoadLibrary((LPCSTR)name);
// }

// funptr_t dlsym(void *hDll, const char *funcname)
// {
//     return GetProcAddress(hDll, funcname);
// }

// char *dlerror(void)
// {
//     LPVOID lpMsgBuf;
//     char * testerr;
//     DWORD dw = GetLastError();

//     FormatMessage(
//         FORMAT_MESSAGE_ALLOCATE_BUFFER |
//         FORMAT_MESSAGE_FROM_SYSTEM |
//         FORMAT_MESSAGE_IGNORE_INSERTS,
//         NULL,
//         dw,
//         MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
//         (LPTSTR) &lpMsgBuf,
//         0,
//         NULL
//     );
//     testerr = (char*)lpMsgBuf;
//     strcpy(errstr,lpMsgBuf);
//     LocalFree(lpMsgBuf);
//     if (ciprefix("Der Vorgang wurde erfolgreich beendet.", errstr))
//         return NULL;
//     else
//         return errstr;
// }

// int dlclose (void *lhandle)
// {
//     return (int)FreeLibrary(lhandle);
// }
// #endif

/* Case insensitive str eq.
   Like strcasecmp( ) XXX */
int
cieq(register char *p, register char *s)
{
    while (*p) {
        if ((isupper(*p) ? tolower(*p) : *p) !=
                (isupper(*s) ? tolower(*s) : *s))
            return(false);
        p++;
        s++;
    }
    return (*s ? false : true);
}

/* Case insensitive prefix. */
int
ciprefix(const char *p, const char *s)
{
    while (*p) {
        if ((isupper(*p) ? tolower(*p) : *p) !=
                (isupper(*s) ? tolower(*s) : *s))
            return(false);
        p++;
        s++;
    }
    return (true);
}

/* read a line from console input
   source:
   https://stackoverflow.com/questions/4023895/how-to-read-string-entered-by-user-in-c
   */
#define OK       0
#define NO_INPUT 1
#define TOO_LONG 2
int
getLine(char *prmpt, char *buff, size_t sz)
{
    int ch, extra;

    // Get line with buffer overrun protection.
    if (prmpt != NULL) {
        // printf("%s", prmpt);
        fflush(stdout);
    }
    if (fgets(buff, sz, stdin) == NULL)
        return NO_INPUT;

    // If it was too long, there'll be no newline. In that case, we flush
    // to end of line so that excess doesn't affect the next call.
    if (buff[strlen(buff) - 1] != '\n') {
        extra = 0;
        while (((ch = getchar()) != '\n') && (ch != EOF))
            extra = 1;
        return (extra == 1) ? TOO_LONG : OK;
    }

    // Otherwise remove newline and give string back to caller.
    buff[strlen(buff) - 1] = '\0';
    return OK;
}
