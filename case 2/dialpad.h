/*File Name     :dialpad.h
  Author Name   :A.G.L.Prasuna
  Created Date  :13-05-2020
  Description   :To find the no.of combinations that can be obtained from the number entered
  Requirements  :#include<iostream>,#include<map>,#include<string.h>,#include<sstream>*/

#ifndef dialpad_h
#define dialpad_h

#include <iostream>
#include<string.h>
#include<sstream>
#include<map>

using namespace std;

/*The class contains a string variable initialized to zero and two member functions
one to store associate string in number and other to find combinations with that string*/

class DialPad
{
    string sOut_pad;
public:
    DialPad()
    {
        sOut_pad={};
    }
    ~DialPad()
    {
        cout<<"Deallocating memory"<<endl;
    }
    void Inputstring(string);
    void Combinations(map<int,string>,string,string);
};
#endif
