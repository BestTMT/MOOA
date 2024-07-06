import function as ng_func


ac_file_name = "C:\\Users\\ericwang\\PycharmProjects\\eda_dev\\ngspice\\tb_template\\ac1.txt"

freq_var_list = []
frequency_Response_list = []

file = open(ac_file_name, mode='r')
for line in file:
    line = line.split()

    freq_var_list.append(line[0])
    c_n = complex(float(line[1]),float(line[2]))
    frequency_Response_list.append(c_n)
file.close()

dg_gain = ng_func.dcGain_dB(freq_var_list, frequency_Response_list)

print("dg_gain:" + str(dg_gain))

#Case2 stars


freq_var_list = []
frequency_Response_list = []

file = open(ac_file_name, mode='r')
for line in file:
    line = line.split()

    freq_var_list.append(line[0])
    c_n = float(line[1])
    frequency_Response_list.append(c_n)
file.close()

dg_gain = ng_func.dcGain_dB(freq_var_list, frequency_Response_list)

print("dg_gain:" + str(dg_gain))
#Case2 Ends



tran_file_name = "C:\\Users\\ericwang\\PycharmProjects\\eda_dev\\ngspice\\tb_template\\tran1.txt"

time_var_list = []
wave_list = []

file = open(tran_file_name, mode='r')
for line in file:
    line = line.split()
    time_var_list.append(float(line[0]))
    wave_list.append(float(line[1]))
file.close()

slewRate = ng_func.slewRate(time_var_list, wave_list)

print("slewRate:" + str(slewRate))