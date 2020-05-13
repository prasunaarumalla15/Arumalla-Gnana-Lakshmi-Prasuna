/*File Name     :dialpad.cpp
  Author Name   :A.G.L.Prasuna
  Created Date  :13-05-2020
  Description   :To find the no.of combinations that can be obtained from the number entered
  Requirements  :#include<iostream>,#include<map>,#include<string.h>,#include<sstream>*/

#include "dialpad.h"
#include <iostream>
#include<string.h>
#include<sstream>
#include<map>

using namespace std;


/*Function Name :Combinations
  Parameters    :three parameters(map object,input string and output string)
  Return Type   :no return type
  Usage         :to display the number of combinations that can obtained for given input*/

void DialPad::Combinations(map<int,string> Dial,string sInput_pad,string sOut)
{
    stringstream ss(sInput_pad);
    int iInput;
    ss>>iInput;
    if(iInput==0)
    {
        cout<<'"'<<sOut<<'"'<<" ";
    }
    string sChar_Dialpad=Dial[iInput%10];
    for(int iStart=0;iStart<sChar_Dialpad.size();iStart++)
    {
        //after completion of sChar_Dialpad.size(),the input comes to first one again
        int iNext=(iInput/10);
        Combinations(Dial,to_string(iNext),sChar_Dialpad[iStart]+sOut);
    }
}

/*Function Name :Inputstring
  Parameters    :one parameter(string)
  Return Type   :no return type
  Usage         :to store the associative strings of numbers into map and calling combination function*/

void DialPad::Inputstring(string sInput)
{
    map<int,string> phone_dialpad;
    phone_dialpad.insert({2,"abc"});
    phone_dialpad.insert({3,"def"});
    phone_dialpad.insert({4,"ghi"});
    phone_dialpad.insert({5,"jkl"});
    phone_dialpad.insert({6,"mno"});
    phone_dialpad.insert({7,"pqrs"});
    phone_dialpad.insert({8,"tuv"});
    phone_dialpad.insert({9,"wxyz"});
    string sOut_pad={};
    //an empty string to store the output
    Combinations(phone_dialpad,sInput,sOut_pad);
}
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
            cout<<"Enter string Between 2-9"<<endl;
            //checking whether the string contains 0's or 1's
        else
        {
            cout<<"[";
            dialpad.Inputstring(sNumber);
            cout<<"]"<<endl;
        }
    }
    return 0;
}
