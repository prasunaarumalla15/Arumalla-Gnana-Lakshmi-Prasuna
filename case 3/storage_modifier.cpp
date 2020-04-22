/*File Name     :storagemodifier.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :06-04-2020
  Description   :To know the uses of modifiers,variable scope and storage classes
  Requirements  :#include<iostream>,#include<string.h*/

#include "extern.h"
#include<iostream>
#include<string.h>
using namespace std;

//unsigned global variable initially holds 96
unsigned iNum=96;
//signed int initially holds 100
signed int iNum1=100;
//extern variable initialized to 0
int iExtern_Num2;

/*Function Name :test_function_storage
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to know the accessibility of storage classes*/

void test_function_storage()
{
    //long double modifier
    long double fCount;
    cout<<"Enter the double value:";
    cin>>fCount;
     //register variable, always starts freshly,stored in cpu registers,very fast
    register int iRegister_Number;
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

//To understand how auto takes automatic return type based on compiler
auto fun()->void
{
    cout<<"Usage of Auto"<<endl;
    cout<<"Welcome to HCL"<<endl;
}


/*Function Name :type_modifiers
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to know the accessibility of different modifiers with variable scope*/

void type_modifiers()
{
    //if it was not given with correct sign it gives garbage value
    unsigned iNum;
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
    //size is always same for integer variables
    cout<<"Global Variable in function = "<<iNum<<" "<<"Size:"<<sizeof(iNum)<<endl;
    cout<<"Second Global Variable in function = "<<iNum1<<" "<<"Size:"<<sizeof(iNum1)<<endl;
    cout<<"global variable outside the function when having inside function also"<<endl;
     //displaying global variables use scope resolution
    cout<<::iNum<<'\t'<<::iNum1<<endl;
    cout<<endl;
}

int main(int argc,char* argv[])
{
    extern int iExtern_Num2;
    if(argc==2)
    {
        //created a help command
        if(strcmp(argv[1],"-h")==0)
        {
            cout<<"Input given inputs"<<endl;
        }
    }
    else
    {
        fun();
        staticFun();
        nonStaticFun();
        cout<<"default value of the extern variable:"<<iExtern_Num2<<endl;
        test_function_storage();
        type_modifiers();
        staticFun();
        nonStaticFun();
        cout<<"change the value of extern variable:";
        cin>>iExtern_Num2;
        cout<<"value of the extern variable after changing:"<<iExtern_Num2<<endl;
        staticFun();
        nonStaticFun();
        cout<<endl;
        cout<<"Usage of Mutable"<<endl;
        const square s( 4, 7 );
        cout<<"Before using mutable with constant"<<endl;
        s.print();
        s.val();
        cout << "After using mutable with constant" << endl;
        s.print();
    }
    return 0;
}
