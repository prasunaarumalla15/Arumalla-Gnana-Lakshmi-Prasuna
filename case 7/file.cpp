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
        else
        {
            cout<<"use "<<argv[0]<<" -h command"<<endl;
        }
    }
    else
    {
        student ob;
        vector<student> vec;
        vector<student>:: iterator it;
        string sfile_key,sfile_val;
        fstream in("note.ini",ios::out|ios::in);
        if(in)
        {
            while(!in.eof())
            {
                getline(in,sfile_key,'=');
                getline(in,sfile_val);
                //sending key and value to parameterized constructor
                student ob(sfile_key,sfile_val);
                if(in.eof()) break;
                if(!(sfile_key.empty()))
                vec.push_back(ob);
            }
        }
        in.close();
        //removing file if file is empty
        removefile(vec);
        char cOpt;
        while(1)
        {
            cout<<"Select your option 1.addconfig 2.deleteconfig 3.listconfig 4.search"<<endl;
            cin>>cOpt;
            switch(cOpt)
            {
                case '1':
                        ob.addconfig(vec);
                        break;
                case '2':
                        ob.deleteconfig(vec);
                        break;
                case '3':
                        ob.listconfig();
                        break;
                case '4':
                        searching(vec);
                        break;
                default:
                        return 0;
            }
        }
    }
    return 0;
}
