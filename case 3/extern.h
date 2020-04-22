/*File Name     :extern.h
  Author Name   :A.G.L.Prasuna
  Created Date  :22-04-2020
  Description   :To know the usage of extern and mutable storage classes
  Requirements  :#include<iostream>*/

extern int iExtern_Num2;

#include <iostream>
using namespace std;

class square
{
    //mutable variable
	mutable int iVar1;
	int iVar2;
public:
    square(int iNum1,int iNum2)
    {
        iVar1=iNum1;
        iVar2=iNum2;
    }
    //values getting inside function are constant
    void val() const
    {
        iVar1=iVar1*iVar1;
    }
    void print() const
    {
        cout <<"Variable 1 : "<<iVar1<<endl;
        cout <<"Variable 2 : "<<iVar2<<endl;
    }
};

