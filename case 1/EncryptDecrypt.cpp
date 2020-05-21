/*File Name     :EncryptDecrypt.cpp
  Author Name   :A.G.L.Prasuna
  Created Date  :15-05-2020
  Description   :The function definitions to encrypt and decrypt the data in the file
  Requirements  :#include<iostream>,#include<fstream>,#include<algorithm>,#include<string.h>,#include<sstream>*/

#include "encryptDecrypt.h"
#include <iostream>
#include<string.h>
#include<fstream>
#include<sstream>
#include<algorithm>
using namespace std;

/*Function Name :Encryptmethod
  Parameters    :one parameter(char*)
  Return Type   :string return type
  Usage         :to encrypt numbers and alphabets in a character array*/

string EncryptDecrypt::Encryptmethod(char* cCode)
{
    iCount=strlen(cCode);
    char cKey[iCount+1]={'0'};
    for(iStart=0;iStart<iCount;iStart++)
    {
        if(cCode[iStart]>=48 && cCode[iStart]<=57)
            cKey[iStart]=cCode[iStart]-1;
        else if(cCode[iStart]>=97 && cCode[iStart]<=122)
            cKey[iStart]=toupper(cCode[iStart]);
        else if(cCode[iStart]>=65 && cCode[iStart]<=90)
            cKey[iStart]=tolower(cCode[iStart]);
        else
            cKey[iStart]=cCode[iStart]^'a';
            //XOR operation of input with 'a'
    }
    return cKey;
}

/*Function Name :Decryptmethod
  Parameters    :one parameter(string)
  Return Type   :string return type
  Usage         :to decrypt the integer and alphabets of input*/

string EncryptDecrypt::Decryptmethod(string sCode)
{
    iLength=sCode.length();
    char cKey_code[iLength+1]={'0'},cPass_code[iLength+1]={'0'};
    strcpy(cKey_code,sCode.c_str());
    //copying string to character array
    for(iStart=0;iStart<strlen(cKey_code);iStart++)
    {
        if(cKey_code[iStart]>=48 && cKey_code[iStart]<=57)
            cPass_code[iStart]=cKey_code[iStart]+1;
        else if(cKey_code[iStart]>=97 && cKey_code[iStart]<=122)
            cPass_code[iStart]=toupper(cKey_code[iStart]);
        else if(cKey_code[iStart]>=65 && cKey_code[iStart]<=90)
            cPass_code[iStart]=tolower(cKey_code[iStart]);
        else if(cKey_code[iStart]==47)
            cPass_code[iStart]=48;
        else
            cPass_code[iStart]=cKey_code[iStart]^'a';
    }
    return cPass_code;
}

/*Function Name :outAlphaNum
  Parameters    :no parameter
  Return Type   :char return type
  Usage         :to get the character from the file in first line and to return that char*/

char EncryptDecrypt::outAlphaNum()
{
    ifstream infile("alphanum.txt");
    if(infile)
    {
        string sAlpha_num;
        char cOutalphanum;
        getline(infile,sAlpha_num,'=');
        infile>>cOutalphanum;
        //extracting that character
        infile.close();
        return cOutalphanum;
    }
    else
        cout<<"Error in opening alphanum.txt"<<endl;
}

/*Function Name :Encryption
  Parameters    :two parameter(char*,char*)
  Return Type   :bool return type
  Usage         :to write the character to replace the space into file
                 and enter key and data in inout file to encrypt file in encrypt format*/

bool EncryptDecrypt::Encryption(char* cfile,char* cInput_key)
{
    ifstream infile(cfile);
    if(infile)
    {
        ofstream outfile_alpha("alphanum.txt");
        if(outfile_alpha)
        {
            cout<<"Enter the alpha numeric character that u want to replace with space:";
            cin>>cAlpha_numeric;
            outfile_alpha<<"alphanum "<<'='<<' '<<cAlpha_numeric;
            outfile_alpha.close();
        }
        else
        {
            cout<<"Error in creating alphanum file"<<endl;
            return 0;
        }
        ofstream outfile("encrypted.txt");
        if(outfile)
        {
            outfile<<"PassCode "<<'='<<' '<<Encryptmethod(cInput_key)<<endl;
            //writing the pass code into the encrypted file
            string sLine,sWord_file;
            while(!infile.eof())
            {
                getline(infile,sLine);
                stringstream ss(sLine);
                while(ss>>sWord_file)
                {
                    iNumber+=sWord_file.length()+1;
                    //checking for no.of words in a file
                    reverse(sWord_file.begin(),sWord_file.end());
                    outfile<<sWord_file;
                    if(iNumber<sLine.length())
                        outfile<<cAlpha_numeric;
                        //checking if the word is end of line
                }
                iNumber=0;
                outfile<<endl;
            }
            outfile.close();
            infile.close();
            remove(cfile);
            return 1;
        }
        else
        {
            cout<<"Error in creating Encrypted file"<<endl;
            return 0;
        }
    }
    else
    {
        cout<<"file doesn't exists"<<endl;
        return 0;
    }
}

/*Function Name :Decryption
  Parameters    :one parameter(char*)
  Return Type   :bool return type
  Usage         :to extract the pass code from the file and to compare that with input pass code
                 to reverse each word of encrypted file without alphanumeric*/

bool EncryptDecrypt::Decryption(char* cCode_key,char* cInput_file)
{
    ifstream infile(cInput_file);
    if(infile)
    {
        string sLines,skey;
        getline(infile,sLines);
        stringstream ss(sLines);
        while(ss>>sLines)
        {
            if(iStart==2)
            {
                skey=sLines;
                //sending the pass code to skey
                break;
            }
            iStart++;
        }
        if(strcmp(Decryptmethod(skey).c_str(),cCode_key)==0)
        {
            char cOutAlphanum_decrypt=outAlphaNum();
            ofstream outfile("Decrypt.txt");
            if(outfile)
            {
                while(!infile.eof())
                {
                    getline(infile,sLines);
                    replace(sLines.begin(),sLines.end(),cOutAlphanum_decrypt,' ');
                    //replacing the alphanumeric with space
                    stringstream ss(sLines);
                    while(ss>>sLines)
                    {
                        reverse(sLines.begin(),sLines.end());
                        //reversing each word
                        outfile<<sLines<<' ';
                    }
                    outfile<<endl;
                    if(infile.eof())break;
                }
                outfile.close();
                return 1;
            }
            else
            {
                cout<<"Unable to create Decryt file"<<endl;
                return 0;
            }
        }
        else
        {
            cout<<"The pass code doesn't match"<<endl;
            return 0;
        }
    }
    else
    {
        cout<<"Unable to open Encrypt file"<<endl;
        return 0;
    }
}

/*Function Name :checkingEncrypt_Decrypt
  Parameters    :two parameter(int,char**)
  Return Type   :string return type
  Usage         :to compare input command line arguments with -f,-k,-d and -e to perform necessary function*/

string EncryptDecrypt::checkingEncrypt_Decrypt(int argc,char* argv[])
{
    for(int iArg=0;iArg<argc;iArg++)
    {
        if(strcmp(argv[iArg],"-f")==0)
        {
            if(strcmp(argv[4],"-k")==0)
            {
                if(strcmp(argv[1],"-d")==0)
                {
                    if(Decryption(argv[5],argv[3])==1)
                    //checking whether the return type is 1 or 0 from function
                        return "Decryption is Success";
                    else
                        return "Decryption is Failure";
                }
                else if(strcmp(argv[1],"-e")==0)
                {
                    if(strcmp(argv[3],"encrypted.txt")==0)
                        return "That is already encrypted file,enter normal text file";
                    else
                    {
                        if(Encryption(argv[3],argv[5])==1)
                            return "Encryption is Success";
                        else
                            return "Encryption is Failure";
                    }
                }
            }
        }
        else if(strcmp(argv[iArg],"-k")==0)
        {
            if(strcmp(argv[4],"-f")==0)
            {
                if(strcmp(argv[1],"-d")==0)
                {
                    if(Decryption(argv[3],argv[5])==1)
                        return "Decryption is Success";
                    else
                        return "Decryption is Failure";
                }
                else if(strcmp(argv[1],"-e")==0)
                {
                    if(strcmp(argv[5],"encrypted.txt")==0)
                        return "That is already encrypted file,enter normal text file";
                    else
                    {
                        if(Encryption(argv[5],argv[3])==1)
                            return "Encryption is Success";
                        else
                            return "Encryption is Failure";
                    }
                }
            }
        }
    }
}
