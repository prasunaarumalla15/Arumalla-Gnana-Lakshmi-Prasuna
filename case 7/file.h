/*File Name     :file.h
  Author Name   :A.G.L.Prasuna
  Created Date  :16-04-2020
  Description   :To perform the list of operations specified
  Requirements  :#include<iostream>,#include<fstream>,#include<vector>,#include<stdio.h>,#include<string.h>*/

#include<iostream>
//including the container
#include<vector>
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

class student{
    char c_Key[500];
    char c_Value[100];
public:

/*Function Name :getkey
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of key the private member*/

    void getkey()
    {
        cout<<"Enter key:";
        getchar();
        cin.get(c_Key,500,'\n');
    }

/*Function Name :getvalue
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of value the private member*/

    void getvalue()
    {
        cout<<"Enter value:";
        getchar();
        cin.get(c_Value,100,'\n');
    }

/*Function Name :outkey
  Parameters    :no parameter
  Return Type   :char return type
  Usage         :to return the key*/

    char* outkey()
    {
        return c_Key;
    }

/*Function Name :outvalue
  Parameters    :no parameter
  Return Type   :string return type
  Usage         :to return value*/

    char* outvalue()
    {
        return c_Value;
    }
    void display()
    {
        cout<<c_Key<<"\t"<<c_Value<<endl;
    }
};

/*Function Name :removefile
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to remove file if file is empty*/

void removefile()
{
    student s;
    int iCount;
    ifstream in("note.ini",ios::in);
    while(1)
    {
        //reading the contents in file
        in.read((char*)&s,sizeof(s));
        iCount++;
        //checking for end of file
        if(in.eof())break;
    }
    if(iCount==0)
    {
        cout<<"file is removed"<<endl;
        //to remove file
        remove("note.ini");
    }
}

/*Function Name :searchupdate
  Parameters    :two parameter(vector object and char)
  Return Type   :int return type
  Usage         :to update the duplicate values*/

int searchupdate(vector<student> &std,char* cOption)
{
    student s;
    //iterator creation to go word to word in file
    vector<student>:: iterator it;
    //inorder to write updated value opened in write mode
    ofstream outfile("note.ini",ios::trunc|ios::out);
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(strcmp(s.outkey(),cOption)==0)
        {
            //the value is been deleted
            std.erase(it);
            cout<<"Enter value to update"<<endl;
            s.getvalue();
            //the new value is pushed into file
            std.push_back(s);
            return 1;
        }
    }
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        //the file again written with updated values
        outfile<<s.outkey()<<"="<<s.outvalue()<<endl;
    }
    outfile.close();
}

/*Function Name :addtofile
  Parameters    :one vector object parameter
  Return Type   :no return type
  Usage         :to add records in to file and store them in to a vector*/

void addtofile(vector<student> &std)
{
    student s;
    vector<student>:: iterator it;
    char cOption='y';
    while(cOption=='y')
    {
        ofstream outfile("note.ini",ios::trunc|ios::out);
        s.getkey();
        if(searchupdate(std,s.outkey())==1)
            //checking for if the key is already present in the file or not
            cout<<"updated"<<endl;
        else
        {
            s.getvalue();
            std.push_back(s);
            for(it=std.begin();it!=std.end();it++)
            {
                s=*it;
                outfile<<s.outkey()<<"="<<s.outvalue()<<endl;
            }
        }
        cout<<"Do you want to append student data(y/n)?";
        cin>>cOption;
        outfile.close();
    }
}

/*Function Name :deletefromfile
  Parameters    :one vector object parameter
  Return Type   :no return type
  Usage         :to delete a record from file*/

void deletefromfile(vector<student> &std)
{
    char ckey[500];
    student s;
    vector<student>:: iterator it;
    ofstream outfile("note.ini",ios::trunc|ios::out);
    cout<<"Enter the key to delete:";
    getchar();
    cin.get(ckey,500,'\n');
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(strcmp(s.outkey(),ckey)==0)
        {
            std.erase(it);
            cout<<"Deleted"<<endl;
        }
    }
    removefile();
    for(it=std.begin();it!=std.end();it++)
    {
            s=*it;
            outfile<<s.outkey()<<"="<<s.outvalue()<<"\n";
    }
    outfile.close();
}

/*Function Name :showfromfile
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to display the contents in the file*/

void showfromfile()
{
    student s;
    ifstream in("note.ini",ios::in);
    char cdata[500];
    while(!in.eof())
    {
        in.getline(cdata,500);
        cout<<cdata<<endl;
    }
}

/*Function Name :searching
  Parameters    :one vector object parameter
  Return Type   :no return type
  Usage         :to search for a key or value and displaying*/

void searching(vector<student> &std)
{
    student s;
    char cCheck;
    char cSearch_key[500];
    char cSearch_value[100];
    vector<student>:: iterator it;
    ifstream in("note.ini",ios::in);
    cout<<"do u want search key or value(k/v):";
    cin>>cCheck;
    if(cCheck=='k')
    {
        cout<<"Enter key u want to search:";
        getchar();
        cin.get(cSearch_key,500,'\n');
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            if(strcmp(cSearch_key,s.outkey())==0)
                cout<<s.outkey()<<"="<<s.outvalue()<<endl;
        }
    }
    else if(cCheck=='v')
    {
        cout<<"Enter value u want to search:";
        getchar();
        cin.get(cSearch_value,100,'\n');
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            if(strcmp(cSearch_value,s.outvalue())==0)
                cout<<s.outkey()<<"="<<s.outvalue()<<endl;
        }
    }
    else
        cout<<"Enter k or v"<<endl;
}
