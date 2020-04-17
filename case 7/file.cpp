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
        vector<student> std;
        vector<student>:: iterator it;
        char cOpt;
        while(1)
        {
            cout<<"Select your option 1.add 2.delete 3.display 4.search"<<endl;
            cin>>cOpt;
            switch(cOpt)
            {
                case '1':
                        addtofile(std);
                        break;
                case '2':
                        deletefromfile(std);
                        break;
                case '3':
                        showfromfile();
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
