/*File Name     :dialpad_main.cpp
  Author Name   :A.G.L.Prasuna
  Created Date  :15-05-2020
  Description   :The main function to find the no.of combinations that can be obtained from the number entered
  Requirements  :#include<iostream>,#include<string.h>*/

#include "dialpad.h"
#include <iostream>
#include<string.h>

using namespace std;

int main(int argc,char* argv[])
{
    if(argc==2 && strcmp(argv[1],"-h")==0)
    {
        //created help command
        cout<<"Enter Input"<<endl;
    }
    else
    {
        string sNumber;
        cout<<"Input:";
        cin>>sNumber;
        DialPad dialpad;
        if(sNumber.find('1') != string::npos || sNumber.find('0') != string::npos)
        {
            cout<<"Enter string Between 2-9"<<endl;
            //checking whether the string contains 0's or 1's
            cout<<"Failure"<<endl;
        }
        else
        {
            dialpad.Inputstring(sNumber);
        }
    }
    return 0;
}
