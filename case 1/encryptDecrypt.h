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
#include<string.h>
#include<fstream>
#include<sstream>
#include<algorithm>
//to use replace and reverse functions
using namespace std;

class EncryptDecrypt
{
    int iCount;
    int iLength;
    int iStart;
public:
    void Encryption(string);
    void Decryption(char*);
    void ReverseOrder(string,int);
    char outAlphaNum();
    void decryptreverse(string);
    string Encryptmethod(char*);
    string Decryptmethod(string);
    void decryptfile();
};

#endif
