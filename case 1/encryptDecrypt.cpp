/*File Name     :encryptDecrypt.cpp
  Author Name   :A.G.L.Prasuna
  Created Date  :08-05-2020
  Description   :To encrypt and decrypt the data in the file
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
    ifstream infile("alphanum.txt",ios::in);
    string sAlpha_num;
    char cOutalphanum;
    getline(infile,sAlpha_num,'=');
    infile>>cOutalphanum;
    //extracting that character
    infile.close();
    return cOutalphanum;
}

/*Function Name :Encryption
  Parameters    :two parameter(char*,char*)
  Return Type   :no return type
  Usage         :to write the character to replace the space into file
                 and enter key and data in inout file to encrypt file in encrypt format*/

void EncryptDecrypt::Encryption(char* cfile,char* cInput_key)
{
    ifstream infile(cfile,ios::in);
    if(infile.is_open())
    {
        ofstream outfile_alpha("alphanum.txt",ios::out);
        cout<<"Enter the alpha numeric character that u want to replace with space:";
        cin>>cAlpha_numeric;
        outfile_alpha<<"alphanum "<<'='<<' '<<cAlpha_numeric;
        outfile_alpha.close();
        ofstream outfile("encrypted.txt",ios::out);
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
                    outfile<<outAlphaNum();
                //checking if the word is end of line
            }
            iNumber=0;
            outfile<<endl;
        }
        outfile.close();
        infile.close();
    }
    else
        cout<<"file doesn't exists"<<endl;
}

/*Function Name :decryptreverse
  Parameters    :one parameter(string)
  Return Type   :no return type
  Usage         :to reverse each word of encrypted file without alphanumeric*/

void EncryptDecrypt::decryptreverse(string sDecrypt_Line)
{
    stringstream ss(sDecrypt_Line);
    while(ss>>sDecrypt_Line)
    {
        reverse(sDecrypt_Line.begin(),sDecrypt_Line.end());
        //reversing each word
        cout<<sDecrypt_Line<<' ';
    }
    cout<<endl;
}

/*Function Name :Decryption
  Parameters    :one parameter(char*)
  Return Type   :no return type
  Usage         :to extract the pass code from the file and to compare that with input pass code*/

void EncryptDecrypt::Decryption(char* cCode_key)
{
    ifstream infile("encrypted.txt",ios::in);
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
        while(!infile.eof())
        {
            getline(infile,sLines);
            replace(sLines.begin(),sLines.end(),outAlphaNum(),' ');
            //replacing the alphanumeric with space
            decryptreverse(sLines);
            if(infile.eof())break;
        }
        infile.close();
    }
    else
        cout<<"The pass code doesn't match"<<endl;
}


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
                    encryptdecrypt.Decryption(argv[5]);
                else
                    cout<<"There is no such encrypted file"<<endl;
            }
            else if(strcmp(argv[4],"-f")==0 && strcmp(argv[2],"-k")==0)
            {
                if(strcmp(argv[5],"encrypted.txt")==0)
                    encryptdecrypt.Decryption(argv[3]);
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
                 encryptdecrypt.Encryption(argv[3],argv[5]);
            }
            else if(strcmp(argv[4],"-f")==0 && strcmp(argv[2],"-k")==0)
            {
               encryptdecrypt.Encryption(argv[5],argv[3]);
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
