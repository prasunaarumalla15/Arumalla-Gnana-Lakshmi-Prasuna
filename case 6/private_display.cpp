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
        Student* ob=new Student();
        ob->display();
        Student* ob1=new Student(10,"prasuna");
        ob1->display();
        //copy constructor is invoked
        Student *ob2=new Student(*ob1);
        cout<<"After using copy constructor"<<endl;
        ob2->display();
        cout<<"Enter Roll_No:";
        cin>>iR_no;
        cout<<"Enter Name less than 20 characters:";
        cin>>cName_student;
        ob1->Assign_Value(iR_no,cName_student);
        cout<<"After performing copy and assingning different values"<<endl;
        ob2->display();
        ob1->display();
        cout<<"Assignment Operator is Invoked"<<endl;
        ob1=ob2;
        ob2->~Student();
        ob1->display();
        ob2=ob;
        cout<<"After performing assingnment operation"<<endl;
        ob2->display();
        ob1->display();
    }
    return 0;
}
