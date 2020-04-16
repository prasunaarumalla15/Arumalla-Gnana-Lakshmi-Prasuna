/*File Name     :privateprotected_inheritance.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :16-04-2020
  Description   :To know how to have private and protected inheritance
  Requirements  :#include<iostream>,#include<stdio.h>,#include<string.h>*/

#include <iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class Student{
private:
    char cMail[50];
    char cName[50];
    public:
/*Function Name :get
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the details*/
    void get()
    {
        getchar();
        cout<<"Enter Name of Student:";
        cin.get(cName,50,'\n');
        cout<<"Enter Mail of Student:";
        getchar();
        cin.get(cMail,50,'\n');
    }
/*Function Name :display
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to display the contents*/
    void display()
    {
        cout<<"Name:"<<cName<<endl;
        cout<<"Mail:"<<cMail<<endl;
    }
};

class Teacher:protected Student
{
   public:
       void get1()
       {
           cout<<"I am a Teacher"<<endl;
           get();
           //calling base class functions
           display();
       }
};

class Stranger:private Student
{
   public:
       void get2()
       {
           cout<<"I am a Stranger"<<endl;
           get();
           display();
       }
};

//int main with command line arguments as parameters
int main(int argc,char* argv[])
{
    //created a help command
    if(argc==2 && strcmp(argv[1],"-h")==0)
    {
        cout<<"Enter given Inputs"<<endl;
    }
    else
    {
        Teacher ob;
        cout<<"Protected Inheritance"<<endl;
        ob.get1();
        Stranger ob1;
        cout<<"Private Inheritance"<<endl;
        ob1.get2();
    }
    return 0;
}
