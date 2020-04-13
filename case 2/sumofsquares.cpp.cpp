/*File Name     :case2.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :13-04-2020
  Description   :To find sum of squares
  Requirements  :#include<iostream>,#include<string.h>*/

#include <iostream>
#include<string.h>

using namespace std;

/*Function Name :SumofSquares
  Parameters    :one int parameter
  Return Type   :int
  Usage         :To calculate square of numbers*/

int SumofSquares(int iNum)
{
    return (iNum*(iNum+1)*(2*iNum+1))/6;    //formula to calculate squares of n terms
}

int main(int argc,char* argv[])
{
    int iCount,iSum;
    if(argc==2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"Input:Integer"<<endl;
        }
    }
    else
    {
        cout<<"Input:";
        cin>>iCount;
        iSum=SumofSquares(iCount);
        cout<<"Output:"<<iSum;
    }
    return 0;
}
