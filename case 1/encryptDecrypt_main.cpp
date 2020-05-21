/*File Name     :encryptDecrypt_main.cpp
  Author Name   :A.G.L.Prasuna
  Created Date  :15-05-2020
  Description   :The main function file to encrypt and decrypt the data in the file
  Requirements  :#include<iostream>,#include<string.h>*/

#include "encryptDecrypt.h"
#include <iostream>
#include<string.h>

using namespace std;

int main(int argc,char* argv[])
{
    string sOutResult_EncryptDecrypt;
    EncryptDecrypt encryptdecrypt;
    if(argc==1)
        cout<<"use "<<argv[0]<<" -h command"<<endl;
    if(argc==2 && strcmp(argv[1],"-h")==0)
    {
        cout<<"usage: "<<endl;
        cout<<argv[0]<<" -d/-e -f [filename] -k [secret key]"<<endl;
        cout<<"\t OR"<<endl;
        cout<<argv[0]<<" -d/-e -k [secret key] -f [filename]"<<endl;
    }
    //help command
    if(argc==6)
    {
        sOutResult_EncryptDecrypt=encryptdecrypt.checkingEncrypt_Decrypt(argc,argv);
        //function to find out encryption or decryption to call
        cout<<sOutResult_EncryptDecrypt<<endl;
    }
    else
        cout<<"use "<<argv[0]<<" -h command"<<endl;
    return 0;
}
