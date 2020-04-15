/*File Name     :case5(1).cc
  Author Name   :A.G.L.Prasuna
  Created Date  :07-04-2020
  Description   :To know the order of constructors and destructors with and without virtual
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
    ~Derived()
    {
        cout<<"Derived Class Destructor is Invoked"<<endl;
    }
};

int main(int argc,char* argv[])
{
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"No input is required"<<endl;
        }
    }
    else
    {
        Derived *D=new Derived();
        Base *B=D;
        delete B;
    }
    return 0;
}
