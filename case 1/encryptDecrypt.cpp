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
    return cOutalphanum;
}

/*Function Name :ReverseOrder
  Parameters    :two parameter(string and int)
  Return Type   :no return type
  Usage         :to reverse each word in a file and writing that to encrypted file*/

void EncryptDecrypt::ReverseOrder(string sData,int iCount)
{
    ofstream outfile("encrypted.txt",ios::app);
    stringstream ss(sData);
    int iNumber=0;
    while(ss>>sData)
    {
        iNumber++;
        //checking for no.of words in a file
        reverse(sData.begin(),sData.end());
        outfile<<sData;
        if(iNumber<iCount)
            outfile<<outAlphaNum();
        //checking if the word is end of line
    }
    outfile<<endl;
    outfile.close();
}

/*Function Name :Encryption
  Parameters    :one parameter(string)
  Return Type   :no return type
  Usage         :to write the character to replace the space in file and sending each line of input file to ReverseOrder*/

void EncryptDecrypt::Encryption(string file)
{
    ifstream infile(file,ios::in);
    if(infile.is_open())
    {
        ofstream outfile("alphanum.txt",ios::out);
        char cAlpha_numeric;
        cout<<"Enter the alpha numeric character that u want to replace with space:";
        cin>>cAlpha_numeric;
        outfile<<"alphanum "<<'='<<' '<<cAlpha_numeric;
        outfile.close();
        string sLine,sWord_file;
        int iCount;
        while(!infile.eof())
        {
            iCount=0;
            getline(infile,sLine);
            stringstream ss(sLine);
            while(ss>>sWord_file)
                iCount++;
            //checking for no.of words in a line
            ReverseOrder(sLine,iCount);
        }
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

/*Function Name :decryptfile
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to replace the alphanumeric char with space and sending each word of encrypted file decryptreverse*/

void EncryptDecrypt::decryptfile()
{
    ifstream infile("encrypted.txt",ios::in);
    string sOut_line;
    getline(infile,sOut_line);
    //neglecting the key line in encrypt file
    while(!infile.eof())
    {
        getline(infile,sOut_line);
        replace(sOut_line.begin(),sOut_line.end(),outAlphaNum(),' ');
        //replacing the alphanumeric with space
        decryptreverse(sOut_line);
        if(infile.eof())break;
    }
    infile.close();
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
    iStart=0;
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
    infile.close();
    if(strcmp(Decryptmethod(skey).c_str(),cCode_key)==0)
        decryptfile();
    else
        cout<<"The pass code doesn't match"<<endl;
}


int main(int argc,char* argv[])
{
    EncryptDecrypt encryptdecrypt;
    string sfile="encrypted.txt";
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
    else
    {
        if(strcmp(argv[1],"-d")==0)
        {
            //In decryption sending the pass code based on -f position
            if(strcmp(argv[2],"-f")==0)
            {
                if(strcmp(argv[3],sfile.c_str())==0)
                    encryptdecrypt.Decryption(argv[5]);
                else
                    cout<<"There is no such encrypted file"<<endl;
            }
            else if(strcmp(argv[4],"-f")==0)
            {
                if(strcmp(argv[5],sfile.c_str())==0)
                    encryptdecrypt.Decryption(argv[3]);
                else
                    cout<<"There is no such encrypted file"<<endl;
            }
        }
        else if(strcmp(argv[1],"-e")==0)
        {
            ofstream outfile("encrypted.txt",ios::out);
            if(strcmp(argv[2],"-f")==0)
            {
                outfile<<"PassCode "<<'='<<' '<<encryptdecrypt.Encryptmethod(argv[5])<<endl;
                //writing the pass code into the encrypted file
                encryptdecrypt.Encryption(argv[3]);
            }
            else if(strcmp(argv[4],"-f")==0)
            {
                outfile<<"PassCode "<<'='<<' '<<encryptdecrypt.Encryptmethod(argv[3])<<endl;
                encryptdecrypt.Encryption(argv[5]);
            }
            outfile.close();
        }
        else
            cout<<"enter correct format"<<endl;
    }
    return 0;
}
