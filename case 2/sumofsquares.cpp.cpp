/*File Name     :sos.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :15-04-2020
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
    int iStart=1;
    int iSquare=0;
    while(iStart<=iNum)
    {
        iSquare+=iStart*iStart; //calculating sum of squares
        iStart++;
    }
    return iSquare;
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
        if(iCount>0)
        {
            iSum=SumofSquares(iCount);
            cout<<"Output:"<<iSum;
        }
        else
            cout<<"Enter Positive Integer greater than zero"<<endl;
    }
    return 0;
}
