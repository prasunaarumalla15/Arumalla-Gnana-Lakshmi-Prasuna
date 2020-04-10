/*File Name     :case6.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :07-04-2020
  Description   :To write a Display method to display int and char variables
  Requirements  :#include<iostream>*/

#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

class Student{
private:
    int *iRoll_no;
    char cName[20];
public:
    Student()
    {
        cout<<"Constructor is Invoked"<<endl;
    }
    Student(int *i_no,char *cname)
    {
        cout<<"Parameterized Constructor is Invoked"<<endl;
        iRoll_no=i_no;
        strcpy(cName,cname);
    }

/*Function Name :Assign_Value
  Parameters    :int*,char
  Return Type   :no return type
  Usage         :to assign value to private variables*/

    void Assign_Value(int *ino,char cname[])
    {
        iRoll_no=ino;
        strcpy(cName,cname);
    }

/*Function Name :display
  Parameters    :no parameters
  Return Type   :no return type
  Usage         :to display private variables*/

    void display()
    {
        cout<<"RollNo:"<<*iRoll_no<<endl<<"Name:"<<cName<<endl;
        cout<<endl;
    }

    void operator ++()  //increment operator overloading
    {
        ++(*iRoll_no);
    }
    ~Student()
    {
        cout<<"Destructor is Invoked"<<endl;
    }
};

int main(int argc,char* argv[])
{
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"used to display private variable int* and char[20], enter one int and char variables"<<endl;
        }
    }
    else
    {
        Student obj;
        int iVal;
        char cNm[20];
        cout<<"Enter RollNo of Student:";
        cin>>iVal;
        cout<<"Enter Name of Student:";
        getchar();
        cin.get(cNm,100,'\n');
        cout<<endl<<"Using Parameterized Constructor"<<endl;
        Student obj2(&iVal,cNm);    //parameterized constructor
        obj2.display();
        cout<<"After Operator Overloading"<<endl;
        ++obj2;     //calling of increment operator overloading
        cout<<"Using Member Function"<<endl;
        obj.Assign_Value(&iVal,cNm);    //calling of member function
        obj.display();
    }
    return 0;
}
