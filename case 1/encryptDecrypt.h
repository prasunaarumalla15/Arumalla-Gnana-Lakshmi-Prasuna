/*File Name     :encryptDecrypt.h
  Author Name   :A.G.L.Prasuna
  Created Date  :26-05-2020
  Description   :To encrypt and decrypt the data in the file
  Requirements  :#include<iostream>,#include<fstream>,#include<algorithm>,#include<string.h>,#include<sstream>*/


#ifndef encryptDecrypt_h
//checking the file is defined or not
#define encryptDecrypt_h
//defining the header file

#include <iostream>

using namespace std;

/*EncryptDecrypt class contains int and char variables initialized to 0
using default constructor and a list of members functions to perform
encryption and decryption of data in a file*/

class EncryptDecrypt
{
    int iStart;
    string Encryptmethod(string);
    string Decryptmethod(string);
    string Alphanum(string);
public:
    EncryptDecrypt()
    {
        iStart=0;
    }
    ~EncryptDecrypt()
    {
        cout<<"deallocating memory";
    }
    bool Encryption(string,string);
    bool Decryption(string,string);
};

#endif
