/*File Name     :storagemodifier.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :06-04-2020
  Description   :To know the uses of modifiers,variable scope and storage classes
  Requirements  :#include<iostream>,#include<string.h*/

#include<iostream>
#include<string.h>
using namespace std;

unsigned iNum=96;    //unsigned global variable initially holds 96
signed int iNum1=100; //signed int initially holds 100
int iX; //initialized to '0'

/*Function Name :test_function_storage
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to know the accessibility of storage classes*/

void test_function_storage()
{
    long double fCount;         //long double modifier
    cout<<"Enter the double value:";
    cin>>fCount;
    static int iStatic_Number=5;    //static variable, initially holds 0,it initialize only once
    register int iRegister_Number;    //register variable, always starts freshly
    cout<<"Enter the Register variable:";
    cin>>iRegister_Number;
    cout<<endl;
    cout<<"Global Variables:"<<endl;
    cout<<"Global   = "<<iNum<<" "<<"Size:"<<sizeof(iNum)<<endl;
    cout<<"Second Global Variable = "<<iNum1<<" "<<"Size:"<<sizeof(iNum1)<<endl;
    cout<<endl;
    cout<<"Storage classes"<<endl;
    cout<<"Register = "<<iRegister_Number<<" "<<"Size:"<<sizeof(iRegister_Number)<<endl;
    cout<<"Double Value:"<<fCount<<" "<<"Size of Double:"<<sizeof(fCount)<<endl;
    cout<<endl;
}

/*Function Name :staticFun
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to know the importance of static*/

void staticFun()
{
    cout << "For static variables: ";
    static int count = 0;
    count++;
    cout<<count<<endl;
}

/*Function Name :nonStaticFun
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to know the difference of static and non static variables*/

void nonStaticFun()
{
    cout << "For Non-Static variables: ";
    int count = 0;
    count++;
    cout<<count<<endl;
}

/*Function Name :fun
  Parameters    :no parameter
  Return Type   :auto return type
  Usage         :to know the usage of auto keyword*/

auto fun()      //To understand how auto takes automatic return type based on compiler
{
    cout<<"Welcome to HCL"<<endl;
}


/*Function Name :type_modifiers
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to know the accessibility of different modifiers with variable scope*/

void type_modifiers()
{
    unsigned iNum;  //if it was not given with correct sign it gives garbage value
    cout<<"Enter a unsigned Number:";
    cin>>iNum;
    signed int iNum1;
    cout<<"Enter signed number:";
    cin>>iNum1;
    short int iNum2;
    iNum2=iNum;
    cout<<"short int:"<<iNum2<<'\t'<<"size of short int:"<<sizeof(iNum2)<<endl;
    cout<<endl;
    cout<<"Local variables"<<endl;
    cout<<"Global Variable in function = "<<iNum<<" "<<"Size:"<<sizeof(iNum)<<endl;//size is always same for integer variables
    cout<<"Second Global Variable in function = "<<iNum1<<" "<<"Size:"<<sizeof(iNum1)<<endl;
    cout<<"global variable outside the function when having inside function also"<<endl;
    cout<<::iNum<<'\t'<<::iNum1<<endl;  //displaying global variables
    cout<<endl;
}

int main(int argc,char* argv[])
{
    extern int iX;
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"Input given inputs"<<endl;
        }
    }
    else
    {
        fun();
        staticFun();
        nonStaticFun();
        cout<<"value of the variable which is globally declared:"<<iX<<endl;
        test_function_storage();
        type_modifiers();
        staticFun();
        nonStaticFun();
        cout<<"change the value of extern variable:";
        cin>>iX;
        cout<<"value of the extern variable after changing:"<<iX<<endl;
        staticFun();
        nonStaticFun();
    }
    return 0;
}
