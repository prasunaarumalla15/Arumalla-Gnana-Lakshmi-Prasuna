/*File Name     :case4.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :06-04-2020
  Description   :To know the purpose and difference between public,private and protected access specifiers
  Requirements  :#include<iostream>,#include<stdio.h>,#include<string.h>*/

#include <iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

class Worker
{
private:        //no one can access it and input is given through member function of that class
    char cEmp_Name[20];
    float fEmp_Salary;
protected:      //limited members can access it
    int iEmp_ID;
public:         //everyone can access it
    virtual void calWages()=0;      //pure virtual function,abstract class
    int iDays;
    float fWages;

/*Function Name :get()
  Parameters    :no parameters
  Return Type   :no return type
  Usage         : To take the details of employee*/

    void get()
    {
        cout<<"Enter ID of Employee:";
        cin>>iEmp_ID;
        cout<<"Enter Name of Employee:";
        getchar();
        cin.get(cEmp_Name,100,'\n');    //can accept space also
    }

/*Function Name :setsal
  Parameters    :two input parameter int and float
  Return Type   :no return type
  Usage         : To calculate salary of daily worker*/

    void setsal(int iDays,float fWages)
    {
        fEmp_Salary=iDays*fWages;
    }

/*Function Name :setsal1
  Parameters    :three input parameter int,float and int
  Return Type   :no return type
  Usage         : To calculate salary of salaried worker*/

    void setsal1(int iDays,float fWages,int iHours)
    {
        float fEmp_Salary;
        fEmp_Salary=iDays*iHours*fWages;
    }
    virtual void display()
    {
        cout<<iEmp_ID<<"\t"<<cEmp_Name<<"\t";
    }
};

class Salaried:public Worker    //class is inherited in public
{
private:
    float fWages;
protected:
    int iHours=40;
public:

/*Function Name :calWages()
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :To attain required details to calculate salary*/

    void calWages()
    {
        int iHours=40;
        cout<<"Enter no.of days:";
        cin>>iDays;
        cout<<"Enter wages per 40 hours:";
        cin>>fWages;
        setsal1(iDays,fWages,iHours);
    }
    void display()
    {
        Worker::display();
        cout<<"salary"<<endl;
    }
};

class Daily:public Worker
{
private:
    float fWages;
public:
    void calWages()
    {
        cout<<"Enter no.of days:";
        cin>>iDays;
        cout<<"Enter wage per day:";
        cin>>fWages;
        setsal(iDays,fWages);
    }
    void display()
    {
        Worker::display();
        cout<<"daily"<<endl;
    }
};

int main(int argc,char* argv[])
{
    Worker *W[5];       //abstract object
    char cChoice;
    int iNumber;
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"Enter the given inputs"<<endl;
        }
    }
    else
    {
        cout<<"Enter no.of Employees:";
        cin>>iNumber;
        for(int iCount=0;iCount<iNumber;iCount++)
        {
            cout<<"Enter Salaried/Daily Worker(s/d):";
            cin>>cChoice;
            if(cChoice=='s')
            {
                W[iCount]=new Salaried();   //creating memory
                W[iCount]->get();       //calling functions
                W[iCount]->calWages();
            }
            else if(cChoice=='d')
            {
                W[iCount]=new Daily();
                W[iCount]->get();
                W[iCount]->calWages();
            }
            else
            {
                cout<<"enter correct format(s/d)"<<endl;
            }
        }
        cout<<endl;
        cout<<"ID\tName\tType"<<endl;
        for(int iCount=0;iCount<iNumber;iCount++)
        {
            W[iCount]->display();   //displaying details
        }
    }
    return 0;
}
