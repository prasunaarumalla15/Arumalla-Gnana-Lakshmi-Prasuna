/*File Name     :EncryptDecrypt.cpp
  Author Name   :A.G.L.Prasuna
  Created Date  :26-05-2020
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
  Parameters    :one parameter(string)
  Return Type   :string return type
  Usage         :to encrypt numbers and alphabets in a character array*/

string EncryptDecrypt::Encryptmethod(string sCode)
{
    int iCount=0;
    iCount=sCode.length();
    char cKey[iCount+1]={'0'};
    for(iStart=0;iStart<iCount;iStart++)
    {
        if(sCode[iStart]>=48 && sCode[iStart]<=57)
            cKey[iStart]=sCode[iStart]-1;
        else if(sCode[iStart]>=97 && sCode[iStart]<=122)
            cKey[iStart]=toupper(sCode[iStart]);
        else if(sCode[iStart]>=65 && sCode[iStart]<=90)
            cKey[iStart]=tolower(sCode[iStart]);
        else
            cKey[iStart]=sCode[iStart];
    }
    return cKey;
}

/*Function Name :Decryptsmethod
  Parameters    :one parameter(string)
  Return Type   :string return type
  Usage         :to decrypt the integer and alphabets of input*/

string EncryptDecrypt::Decryptmethod(string sCode)
{
    int iLength=0;
    iLength=sCode.length();
    char cPass_code[iLength+1]={'0'};
    for(iStart=0;iStart<iLength;iStart++)
    {
        if(sCode[iStart]>=48 && sCode[iStart]<=57)
            cPass_code[iStart]=sCode[iStart]+1;
        else if(sCode[iStart]>=97 && sCode[iStart]<=122)
            cPass_code[iStart]=toupper(sCode[iStart]);
        else if(sCode[iStart]>=65 && sCode[iStart]<=90)
            cPass_code[iStart]=tolower(sCode[iStart]);
        else if(sCode[iStart]==47)
            cPass_code[iStart]=48;
        else
            cPass_code[iStart]=sCode[iStart];
    }
    return cPass_code;
}

/*Function Name :Alphanum
  Parameters    :one parameter(string)
  Return Type   :string return type
  Usage         :to decrypt the integer and alphabets of input*/

string EncryptDecrypt::Alphanum(string sfile)
{
    ifstream infile(sfile);
    string sLine_file,sTotal_data;
    char cSpace_Replacer;
    if(infile)
    {
        while(!infile.eof())
        {
            getline(infile,sLine_file);
            sTotal_data=sLine_file;
        }
        infile.close();
    }
    if(sTotal_data.find('*')==string::npos)
    //searching for '*' in data in file
        return "*";
    else
        return "#$*!++-==^&###*&^";
}

/*Function Name :Encryption
  Parameters    :two parameter(string,string)
  Return Type   :bool return type
  Usage         :to write the character to replace the space into file
                 and enter key and data in inout file to encrypt file in encrypt format*/

bool EncryptDecrypt::Encryption(string sfile,string sInput_key)
{
    string sTotal_data;
    string sAlphaNumeric=Alphanum(sfile);
    ifstream infile(sfile);
    if(infile)
    {
        int iNumber=0;
        ofstream outfile("encrypted.txt");
        if(outfile)
        {
            outfile<<"PassCode "<<'='<<' '<<Encryptmethod(sInput_key)<<endl;
            //writing the pass code into the encrypted file
            outfile<<sAlphaNumeric<<endl;
            string sLine,sWord_file;
            while(!infile.eof())
            {
                getline(infile,sLine);
                stringstream StreamWord(sLine);
                while(StreamWord>>sWord_file)
                {
                    iNumber+=sWord_file.length()+1;
                    //checking for no.of words in a file
                    reverse(sWord_file.begin(),sWord_file.end());
                    outfile<<sWord_file;
                    if(iNumber<sLine.length())
                        outfile<<sAlphaNumeric;
                        //checking if the word is end of line
                }
                iNumber=0;
                outfile<<endl;
            }
            outfile.close();
            infile.close();
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
  Parameters    :two parameter(string,string)
  Return Type   :bool return type
  Usage         :to extract the pass code from the file and to compare that with input pass code
                 to reverse each word of encrypted file without alphanumeric*/

bool EncryptDecrypt::Decryption(string sCode_key,string sInput_file)
{
    ifstream infile(sInput_file);
    if(infile)
    {
        string sLines,skey,sOut_Decrypt_line,sDelimiter;
        size_t Position=0;
        getline(infile,sLines);
        stringstream StreamWords(sLines);
        while(StreamWords>>sLines)
        {
            if(iStart==2)
            {
                skey=sLines;
                //sending the pass code to skey
                break;
            }
            iStart++;
        }
        if(Decryptmethod(skey)==sCode_key)
        {
            getline(infile,sLines);
            sDelimiter=sLines;
            //the delimiter in file
            ofstream outfile("Decrypt_file.txt");
            if(outfile)
            {
                while(getline(infile,sLines))
                {
                    while((Position = sLines.find(sDelimiter)) != string::npos)
                    {
                        sOut_Decrypt_line=sLines.substr(0,Position);
                        reverse(sOut_Decrypt_line.begin(),sOut_Decrypt_line.end());
                        //reversing each word
                        outfile<<sOut_Decrypt_line<<' ';
                        sLines.erase(0,Position+sDelimiter.length());
                    }
                    reverse(sLines.begin(),sLines.end());
                    outfile<<sLines<<endl;
                    if(infile.eof())break;
                }
                outfile.close();
                infile.close();
                return 1;
            }
            else
            {
                cout<<"Unable to create Decrypt file"<<endl;
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
