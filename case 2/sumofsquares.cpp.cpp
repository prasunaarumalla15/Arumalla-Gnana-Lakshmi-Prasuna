/*File Name     :case2.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :06-04-2020
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
    int iStart=1,iAdd=0;
    while(iStart<=iNum)
    {
        iAdd+=(iStart*iStart);  //adding sum of squares
        iStart++;
    }
    return iAdd;
}

int main(int argc,char* argv[])
{
    int iCount,iSum;
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"can give any number as input and up to that number we can get sum of squares "<<endl;
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
