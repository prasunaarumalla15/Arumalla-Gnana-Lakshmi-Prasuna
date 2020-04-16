/*File Name     :privateinitialize.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :15-04-2020
  Description   :To know different ways to initialize private members of a class
  Requirements  :#include<iostream>,#include<string.h>*/

#include<iostream>
#include<string.h>

using namespace std;

class Test{
private:
    int iNum;
    char cLetter;
public:
    Test():iNum{5},cLetter{'d'}{}
    Test(int inum,char cletter):iNum{inum},cLetter{cletter}{}
    /*Test()
    {
        iNum=100;
        cLetter='d';
    }
    Test(int inum,char cletter)
    {
        iNum=inum;
        cLetter=cletter;
    }*/

/*Function Name :display()
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to display the private members*/

    void display()
    {
        cout<<"Number:"<<iNum<<endl;
        cout<<"Char:"<<cLetter<<endl;
        cout<<endl;
    }
};

int main(int argc,char* argv[])
{
    //created a help command
    if(argc==2)
    {
        if(strcmp(argv[1],"-h")==0)
        {
            cout<<"NO Input"<<endl;
        }
    }
    else
    {
        Test ob;
        Test ob1(10,'f');
        cout<<"using Initialization List"<<endl;
        ob.display();
        ob1.display();
    }
    return 0;
}
