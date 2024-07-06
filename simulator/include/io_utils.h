#ifndef IO_UTILS_H

#define IO_UTILS_H
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <stdlib.h>
using namespace std;

namespace sizingrule {
  //从文件读入到string里
  string readFileIntoString(char * filename)
  {
      ifstream ifile(filename);
      //将文件读入到ostringstream对象buf中
      ostringstream buf;
      char ch;
      while(buf&&ifile.get(ch))
      buf.put(ch);
      //返回与流对象buf关联的字符串
      return buf.str();
  }

  void string_replace(string&s1,const string&s2,const string&s3)
  {
    string::size_type pos=0;
    string::size_type a=s2.size();
    string::size_type b=s3.size();
    while((pos=s1.find(s2,pos))!=string::npos)
    {
      s1.replace(pos,a,s3);
      pos+=b;
    }
  }

}


#endif /* IO_UTILS_H */
