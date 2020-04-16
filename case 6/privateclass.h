/*File Name     :privateclass.h
  Author Name   :A.G.L.Prasuna
  Created Date  :15-04-2020
  Description   :To write a Display method to display int and char variables
  Requirements  :#include<iostream>,#include<string.h>*/

#include<iostream>
#include<string.h>

using namespace std;

class Student{
private:
    int *iRoll_no;
    char cName[20];
public:
    Student()
    {
        cout<<"Constructor is Invoked"<<endl;
        //allocating memory
        iRoll_no=new int;
        *iRoll_no=0;
        *cName='\0';
    }
    Student(int i_no,char *cname)
    {
        cout<<"Parameterized Constructor is Invoked"<<endl;
        iRoll_no=new int;
        *iRoll_no=i_no;
        strcpy(cName,cname);
    }
    //copy constructor
    Student(const Student& ob)
    {
        iRoll_no=new int;
        strcpy(cName,ob.cName);
        //copying variables
        *iRoll_no=*ob.iRoll_no;
    }

/*Function Name :Assign_Value
  Parameters    :int*,char
  Return Type   :no return type
  Usage         :to assign value to private variables*/

    void Assign_Value(int ino,char cname[])
    {
        iRoll_no=new int;
        *iRoll_no=ino;
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

     //increment operator overloading
    void operator ++()
    {
        ++(*iRoll_no);
    }
    //destructor
    ~Student()
    {
        cout<<"Deallocating Memory"<<endl;
        delete iRoll_no;
    }
};
