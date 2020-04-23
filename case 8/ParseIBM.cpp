/*File Name     :ParseIBM.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :23-04-2020
  Description   :To display the output from the file in given format
  Requirements  :#include<iostream>,#include<string.h>,#include<regex>,#include<fstream>*/

#include "ParseIBM.h"
#include <iostream>
#include <fstream>
#include <string.h>
//regular expression to access different formats very fastly
#include<regex>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc==2 && strcmp(argv[1],"-h")==0)
    {
        cout<<argv[0]<<" filename.txt"<<endl;
    }
    else if(argc==1)
    {
        cout<<"Use "<<argv[0]<<" -h command";
    }
    else
    {
        ParseIBMString ob;
        ob.getIBM(argv[1]);
    }
    return 0;
}
