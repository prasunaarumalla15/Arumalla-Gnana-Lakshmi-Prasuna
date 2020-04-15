/*File Name     :privatedisplay.cc
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
        iRoll_no=new int;       //allocating memory
        *iRoll_no=0;
        *cName='\0';
    }
    Student(int i_no,char *cname)
    {
        cout<<"Parameterized Constructor is Invoked"<<endl;
        iRoll_no=new int;          //allocating memory
        *iRoll_no=i_no;
        strcpy(cName,cname);
    }
    Student(const Student& ob)      //copy constructor
    {
        iRoll_no=new int;
        strcpy(cName,ob.cName);     //copying variables
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

    void operator ++()  //increment operator overloading
    {
        ++(*iRoll_no);
    }
    ~Student()      //destructor
    {
        cout<<"Deallocating Memory"<<endl;
        delete iRoll_no;
    }
};

int main(int argc,char* argv[])
{
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
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
        Student ob2=ob1;        //copy constructor is invoked
        ob1.display();
        cout<<"After using copy constructor"<<endl;
        cout<<"After Operator Overloading"<<endl;
        ++ob2;     //calling of increment operator overloading
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
