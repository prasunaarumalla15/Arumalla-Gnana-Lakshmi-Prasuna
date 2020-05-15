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
    EncryptDecrypt encryptdecrypt;
    if(argc==1)
    {
        cout<<"use "<<argv[0]<<" -h command"<<endl;
    }
    //created a help command
    else if(argc==2 && strcmp(argv[1],"-h")==0)
    {
        cout<<argv[0]<<" -d/-e -f [filename] -k [secret key]"<<endl;
        cout<<"\t OR"<<endl;
        cout<<argv[0]<<" -d/-e -k [secret key] -f [filename]"<<endl;
    }
    else if(argc==6)
    {
        if(strcmp(argv[1],"-d")==0)
        {
            //In decryption sending the pass code
            if(strcmp(argv[2],"-f")==0 && strcmp(argv[4],"-k")==0)
            {
                if(strcmp(argv[3],"encrypted.txt")==0)
                {
                    if(encryptdecrypt.Decryption(argv[5],argv[3])==1)
                    //checking whether the return type is 1 or 0 from function
                        cout<<"Decryption is Success"<<endl;
                    else
                        cout<<"Decryption is Failure"<<endl;
                }
                else
                    cout<<"There is no such encrypted file"<<endl;
            }
            else if(strcmp(argv[4],"-f")==0 && strcmp(argv[2],"-k")==0)
            {
                if(strcmp(argv[5],"encrypted.txt")==0)
                {
                    if(encryptdecrypt.Decryption(argv[3],argv[5])==1)
                        cout<<"Decryption is Success"<<endl;
                    else
                        cout<<"Decryption is Failure"<<endl;
                }
                else
                    cout<<"There is no such encrypted file"<<endl;
            }
            else
                cout<<"Use "<<argv[0]<<" -h command"<<endl;
        }
        else if(strcmp(argv[1],"-e")==0)
        {
            if(strcmp(argv[2],"-f")==0 && strcmp(argv[4],"-k")==0)
            {
                if(strcmp(argv[3],"encrypted.txt")==0)
                    cout<<"That is already encrypted file,enter normal text file"<<endl;
                else
                {
                    if(encryptdecrypt.Encryption(argv[3],argv[5])==1)
                        cout<<"Encryption is Success"<<endl;
                    else
                        cout<<"Encryption is Failure"<<endl;
                }
            }
            else if(strcmp(argv[4],"-f")==0 && strcmp(argv[2],"-k")==0)
            {
                if(strcmp(argv[5],"encrypted.txt")==0)
                    cout<<"That is already encrypted file,enter normal text file"<<endl;
                else
                {
                    if(encryptdecrypt.Encryption(argv[5],argv[3])==1)
                        cout<<"Encryption is Success"<<endl;
                    else
                        cout<<"Encryption is Failure"<<endl;
                }
            }
            else
                cout<<"Use "<<argv[0]<<" -h command"<<endl;
        }
        else
            cout<<"Use "<<argv[0]<<" -h command"<<endl;
    }
    else
        cout<<"Use "<<argv[0]<<" -h command"<<endl;
    return 0;
}
