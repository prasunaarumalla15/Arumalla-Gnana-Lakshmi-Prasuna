/*File Name     :encryptDecrypt_main.cpp
  Author Name   :A.G.L.Prasuna
  Created Date  :26-05-2020
  Description   :The main function file to encrypt and decrypt the data in the file
  Requirements  :#include<iostream>,#include<string.h>*/

#include "encryptDecrypt.h"
#include <iostream>
#include<string.h>

using namespace std;

int main(int argc,char* argv[])
{
    EncryptDecrypt encryptdecrypt;
    string sType_method,sFile_Command_Argument,sKey_Command_Argument;
    if(argc==1)
        cout<<"use "<<argv[0]<<" -h command"<<endl;
    if(argc==2 && strcmp(argv[1],"-h")==0)
    {
        cout<<"usage: "<<endl;
        cout<<argv[0]<<" -d -f [encrypted filename] -k [secret key]"<<endl;
        cout<<"\t OR"<<endl;
        cout<<argv[0]<<" -e -k [secret key] -f [normal filename]"<<endl;
    }
    //help command
    if(argc>2)
    {
        sType_method=argv[1];
        for(int iArg=0;iArg<argc;iArg++)
        {
            if(strcmp(argv[iArg],"-f")==0)
            {
                sFile_Command_Argument=argv[iArg+1];
            }
            if(strcmp(argv[iArg],"-k")==0)
            {
                sKey_Command_Argument=argv[iArg+1];
            }
        }
        if(sType_method=="-d")
        {
            if(encryptdecrypt.Decryption(sKey_Command_Argument,sFile_Command_Argument)==1)
            //checking whether the return type is 1 or 0 from function
                cout<<"Decryption is Success"<<endl;
            else
                cout<<"Decryption is Failure"<<endl;
        }
        else if(sType_method=="-e" && sFile_Command_Argument!="encrypted.txt")
        {
            if(encryptdecrypt.Encryption(sFile_Command_Argument,sKey_Command_Argument)==1)
                cout<<"Encryption is Success"<<endl;
            else
                cout<<"Encryption is Failure"<<endl;
        }
        else
        cout<<"use "<<argv[0]<<" -h command"<<endl;
    }
    return 0;
}
