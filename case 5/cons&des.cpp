/*File Name     :case5(1).cc
  Author Name   :A.G.L.Prasuna
  Created Date  :07-04-2020
  Description   :To know the order of constructors and destructors with and with virtual
  Requirements  :#include<iostream>,#include<string.h>*/

#include <iostream>
#include<string.h>

using namespace std;

class Test
{
public:
    Test()
    {
        cout<<"Test Class Constructor is Invoked"<<endl;
    }
    ~Test()
    {
        cout<<"Test Class Destructor is Invoked"<<endl;
    }

};

class Base
{
public:
    Test ob;    //Test class object in another class
    Base()
    {
        cout<<"Base Class Constructor is Invoked"<<endl;
    }
    ~Base()
    {
        cout<<"Base Class Destructor is Invoked"<<endl;
    }
    /*virtual ~Base()
    {
        cout<<"Base Class Destructor is Invoked"<<endl;
    }*/
};

class Derived:public Base
{
public:
    Derived()
    {
        cout<<"Derived Class Constructor is Invoked"<<endl;
    }
    virtual ~Derived()
    {
        cout<<"Derived Class Destructor is Invoked"<<endl;
    }
};

class Derived1:public Base,Derived
{
public:
    Derived1()
    {
        cout<<"Derived1 Class Constructor is Invoked"<<endl;
    }
    ~Derived1()
    {
        cout<<"Derived1 Class Destructor is Invoked"<<endl;
    }
};

int main(int argc,char* argv[])
{
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"Used to know the order of constructors and destructors, no need to give any input"<<endl;
        }
    }
    else
        Derived1 D;
    return 0;
}
