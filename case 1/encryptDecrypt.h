/*File Name     :encryptDecrypt.h
  Author Name   :A.G.L.Prasuna
  Created Date  :08-05-2020
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
    int iCount;
    int iLength;
    int iStart;
    int iNumber;
    char cAlpha_numeric;
    char outAlphaNum();
    string Encryptmethod(char*);
    string Decryptmethod(string);
    bool Encryption(char*,char*);
    bool Decryption(char*,char*);
public:
    EncryptDecrypt()
    {
        iCount=0;
        iLength=0;
        iStart=0;
        iNumber=0;
        cAlpha_numeric='0';
    }
    ~EncryptDecrypt()
    {
        cout<<"deallocating memory";
    }
    string checkingEncrypt_Decrypt(int,char**);
};

#endif
