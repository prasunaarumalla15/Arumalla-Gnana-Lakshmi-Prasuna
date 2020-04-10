/*File Name     :parse.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :06-04-2020
  Description   :To display the output in the given format
  Requirements  :#include<iostream>,#include<string.h>,#include<math.h>*/

#include <iostream>
#include<string.h>
#include<math.h>

using namespace std;

/*Function Name :find_datatype
  Parameters    :one char* parameter
  Return Type   :no return type
  Usage         :to distinguish between datatypes*/

void find_datatype(char* sArg)
{
    int iNum;
    float fTemp;
    float fVal=1e-12;  //precision for integer checking
    if(sscanf(sArg,"%f",&fTemp)==1)   //converting the string to double and storing in temp
    {
        iNum=(int)fTemp;    //typecasting to int
        if(fabs(fTemp-iNum)/fTemp>fVal) //checking if any decimal value
            cout<<"Float"<<'\t'<<sArg<<'\t'<<sizeof(sArg)<<endl;
        else
            cout<<"Int"<<'\t'<<sArg<<'\t'<<sizeof(iNum)<<endl;
    }
    else
    {
        auto aNum=atoi(sArg);   //converting string to integer
        if(aNum==0) //if not integer
        {
            if(strlen(sArg)==1) //checking whether it is character
                cout<<"Char"<<'\t'<<sArg<<'\t'<<strlen(sArg)<<endl;
            else
                cout<<"String"<<'\t'<<sArg<<'\t'<<strlen(sArg)<<endl;
        }
    }
}

int main(int argc,char* argv[]) //int main with command line arguments as parameters
{
    int iCount;
    if(strcmp(argv[1],"-h")==0)     //created a help command
    {
        cout<<"Can pass any no.of arguments in command line of type string,char,int and float types"<<endl;
    }
    else
    {
        cout<<"Input:";
        for(iCount=0;iCount<argc;iCount++)  //to display the input
            cout<<argv[iCount]<<" ";
        cout<<endl;
        cout<<"Output:"<<endl;
        cout<<"Type\tValue\tSize of"<<endl;
        for(iCount=1;iCount<argc;iCount++)
        {
            find_datatype(argv[iCount]);    //passing each argument to function
        }
        return 0;
    }
}

