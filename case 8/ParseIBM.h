/*File Name     :ParseIBM.h
  Author Name   :A.G.L.Prasuna
  Created Date  :23-04-2020
  Description   :To display the output from the file in given format
  Requirements  :#include<iostream>,#include<string.h>,#include<regex>,#include<fstream>*/

#include <iostream>
#include <fstream>
#include <string.h>
//regular expression to access different formats very fastly
#include<regex>

using namespace std;

class ParseIBMString
{
private:
    int ipos;
    int ipos1;
    int ipos2;
    int ifound;
public:
    bool getIBM(string filename);
    string fileType(string filename, string filepath);
    bool HasIBM(string str, string searchString);
    string Copyright(string str);
    string isMacro(string str);
    string url(string str);
    string ServerName(string str);
    string registry(string str);
    string os(string str);
    string comment(string str);
    string debug(string str);
    string washType(string str);
    string FileName(const string& str);
    string dirnameOf(const string& fname);
};
