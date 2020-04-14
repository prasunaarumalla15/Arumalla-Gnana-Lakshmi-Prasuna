/*File Name     :access.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :14-04-2020
  Description   :To know the purpose and difference between public,private and protected access specifiers
  Requirements  :#include<iostream>,#include<stdio.h>,#include<string.h>*/

#include "access.h"
#include <iostream>
#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

int main(int argc,char* argv[])
{
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"Enter the given inputs"<<endl;
        }
    }
    else
    {
        int iNumber;
        cout<<"Enter no.of Employees:";
        cin>>iNumber;
        vector<Worker*> std;
        vector<Worker*>::iterator it;
        Worker *W;      //abstract object
        char cChoice;
        int iCount;
        for(iCount=0;iCount<iNumber;iCount++)
        {
            cout<<"Enter Salaried/Daily Worker(s/d):";
            cin>>cChoice;
            if(cChoice=='s')
            {
                W=new Salaried();   //creating memory
                W->get();    //calling functions
                W->calWages();
                std.push_back(W);   //storing in vector container
            }
            else if(cChoice=='d')
            {
                W=new Daily();
                W->get();    //calling functions
                W->calWages();
                std.push_back(W);
            }
            else
            {
                cout<<"enter correct format(s/d)"<<endl;
            }
        }
        cout<<endl;
        cout<<"ID\tName\tType"<<endl;
        for(it=std.begin();it!=std.end();++it)
        {
            W=*it;
            W->display();   //displaying details
        }
    }
    return 0;
}
