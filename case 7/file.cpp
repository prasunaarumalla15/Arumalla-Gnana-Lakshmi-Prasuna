/*File Name     :file_note.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :23-04-2020
  Description   :To perform the list of operations specified
  Requirements  :#include<iostream>,#include<fstream>,#include<vector>,#include<stdio.h>,#include<string.h>*/

#include "file.h"
#include<iostream>
//including the container
#include<vector>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;
int main(int argc,char* argv[])
{
    if(argc==2)
    {
        if(strcmp(argv[1],"-h")==0)
        {
            cout<<"select required option"<<endl;
        }
    }
    else
    {
        student s;
        vector<student> std;
        vector<student>:: iterator it;
        char ckey[50],cval[50];
        char cSpace;
        fstream in("note.ini",ios::out|ios::in);
        if(in)
        {
            while(!in.eof())
            {
                in.get(ckey,50,'=');
                fflush(stdin);
                in>>s.c_equal;
                in.get(cval,50,'\n');
                in>>cSpace;
                student s(ckey,cval);
                std.push_back(s);
                if(in.eof()) break;
            }
        }
        in.close();
        removefile(std);
        char cOpt;
        while(1)
        {
            cout<<"Select your option 1.addconfig 2.deleteconfig 3.listconfig 4.search"<<endl;
            cin>>cOpt;
            switch(cOpt)
            {
                case '1':
                        s.addconfig(std);
                        break;
                case '2':
                        s.deleteconfig(std);
                        break;
                case '3':
                        s.listconfig();
                        break;
                case '4':
                        searching(std);
                        break;
                default:
                        return 0;
            }
        }
    }
    return 0;
}
