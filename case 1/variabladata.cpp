/*File Name     :variabledata.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :13-04-2020
  Description   :To display the output in the given format
  Requirements  :#include<iostream>,#include<string.h>,#include<math.h>*/

#include <iostream>
#include<string.h>
#include<sstream>
#include<math.h>

using namespace std;

/*Function Name :find_datatype
  Parameters    :one char* parameter
  Return Type   :no return type
  Usage         :to distinguish between datatypes*/

void find_datatype(char* sArg)
{
    int iNum=0;
    float fTemp=0;
    //precision for integer checking
    float fVal=1e-12;
    //to convert string to int,floats or doubles
    stringstream num(sArg);
    //extracting num to fTemp
    if(num>>fTemp)
    {
        //typecasting to int
        iNum=(int)fTemp;
        //checking if any decimal value
        if(fabs(fTemp-iNum)/fTemp>fVal)
            cout<<"Float"<<'\t'<<sArg<<'\t'<<sizeof(sArg)<<endl;
        else
            cout<<"Int"<<'\t'<<sArg<<'\t'<<sizeof(iNum)<<endl;
    }
    else
    {
        //checking whether it is character
        if(strlen(sArg)==1)
            cout<<"Char"<<'\t'<<sArg<<'\t'<<strlen(sArg)<<endl;
        else
            cout<<"String"<<'\t'<<sArg<<'\t'<<strlen(sArg)<<endl;
    }
}

//int main with command line arguments as parameters
int main(int argc,char* argv[])
{
    int iCount;
    //created a help command
    if(argc==2 && strcmp(argv[1],"-h")==0)
    {
        cout<<argv[0]<<" "<<"datatype 1 datatype 2 .... datatypeN"<<endl;
    }
    else if(argc==1)
    {
        cout<<"use "<<argv[0]<<" -h command"<<endl;
    }
    else
    {
        cout<<"Input:";
        //to display the input
        for(iCount=0;iCount<argc;iCount++)
            cout<<argv[iCount]<<" ";
        cout<<endl;
        cout<<"Output:"<<endl;
        cout<<"Type\tValue\tSize of"<<endl;
        //passing each argument to function
        for(iCount=1;iCount<argc;iCount++)
        {
            find_datatype(argv[iCount]);
        }
    }
        return 0;
}


