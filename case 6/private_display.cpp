/*File Name     :privatedisplay.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :15-04-2020
  Description   :To write a Display method to display int and char variables
  Requirements  :#include<iostream>,#include<string.h>*/

#include<iostream>
#include<string.h>
#include "privateclass.h"

using namespace std;

int main(int argc,char* argv[])
{
    if(argc==2)
    {
        //created a help command
        if(strcmp(argv[1],"-h")==0)
        {
            cout<<"Enter given Inputs"<<endl;
        }
    }
    else
    {
        int iR_no;
        char cName_student[20];
        Student ob;
        Student ob1(10,"prasuna");
        //copy constructor is invoked
        Student ob2=ob1;
        ob1.display();
        cout<<"After using copy constructor"<<endl;
        cout<<"After Operator Overloading"<<endl;
         //calling of increment operator overloading
        ++ob2;
        ob2.display();
        cout<<"Using Member Function"<<endl;
        cout<<"Enter Roll_No:";
        cin>>iR_no;
        cout<<"Enter Name:";
        cin>>cName_student;
        Student ob3;
        ob3.Assign_Value(iR_no,cName_student);
        ob3.display();
    }
    return 0;
}
