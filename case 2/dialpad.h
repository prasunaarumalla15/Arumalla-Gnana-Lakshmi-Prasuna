/*File Name     :dialpad.h
  Author Name   :A.G.L.Prasuna
  Created Date  :15-05-2020
  Description   :The header file to find the no.of combinations that can be obtained from the number entered
  Requirements  :#include<iostream>,#include<map>*/

#ifndef dialpad_h
#define dialpad_h

#include <iostream>
#include<map>

using namespace std;

/*The class contains a string variable initialized to zero and two member functions
one to store associate string in number and other to find combinations with that string*/

class DialPad
{
    string sOut_pad;
    bool Combinations(map<int,string>,string,string);
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
};
#endif
