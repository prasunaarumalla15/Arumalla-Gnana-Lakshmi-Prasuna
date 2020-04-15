/*File Name     :case5.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :15-04-2020
  Description   :To know different ways to initialize private members of a class
  Requirements  :#include<iostream>,#include<string.h>*/

#include<iostream>
#include<string.h>

using namespace std;

class Test{
private:
    int iNum1;
    float iNum2;
public:
    Test():iNum1{5},iNum2{52.32}{}
    Test(int iX,int iY):iNum1{iX},iNum2{iY}{}

/*Function Name :get()
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to take the input of private members*/

    void get()
    {
        cout<<"Using Member Function"<<endl;
        cout<<"Enter Number 1 any int:";
        cin>>iNum1;
        cout<<"Enter Number 2 any float:";
        cin>>iNum2;
    }

/*Function Name :display()
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to display the private members*/

    void display()
    {
        cout<<"Number 1:"<<iNum1<<endl;
        cout<<"Number 2:"<<iNum2<<endl;
        cout<<endl;
    }
    friend void getinput(Test T);
};

/*Function Name :getinput
  Parameters    :Test class object
  Return Type   :no return type
  Usage         :to take the input of private members*/

void getinput(Test T)
{
    cout<<"Using Friend Function"<<endl;
    cout<<"Enter Number 1 any int:";
    cin>>T.iNum1;
    cout<<"Enter Number 2 any float:";
    cin>>T.iNum2;
    cout<<"Number 1:"<<T.iNum1<<endl<<"Number 2:"<<T.iNum2<<endl;
    cout<<endl;
}

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
        Test ob;
        Test ob1(20,10.235);    //parameterized constructor
        cout<<"using Initialization List"<<endl;
        ob.display();
        ob1.display();
        Test ob2;
        ob2.get();
        ob2.display();
        Test T;
        getinput(T);
    }
    return 0;
}
