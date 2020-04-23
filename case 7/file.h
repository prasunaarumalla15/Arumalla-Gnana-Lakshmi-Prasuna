/*File Name     :file.h
  Author Name   :A.G.L.Prasuna
  Created Date  :23-04-2020
  Description   :To perform the list of operations specified
  Requirements  :#include<iostream>,#include<fstream>,#include<vector>,#include<stdio.h>,#include<string.h>*/

#include<iostream>
//including the container
#include<vector>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<cstdio>

using namespace std;

class student
{
    char c_Key[50];
    char c_Value[50];
public:
    char c_equal;
    student()
    {

    }
    student(char *ckey,char *cval)
    {
        strcpy(c_Key,ckey);
        strcpy(c_Value,cval);
    }
    char outequal()
    {
        return '=';
    }

/*Function Name :getkey
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of key the private member*/

    void getkey()
    {
        cout<<"Enter key:";
        getchar();
        cin.get(c_Key,50,'\n');
    }

/*Function Name :getvalue
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of value the private member*/

    void getvalue()
    {
        cout<<"Enter value:";
        getchar();
        cin.get(c_Value,50,'\n');
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
    void addconfig(vector<student> &std);
    void deleteconfig(vector<student> &std);
    void listconfig();
};

/*Function Name :removefile
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to remove file if file is empty*/

void removefile(vector<student> &std)
{
    if(std.empty())
    {
        cout<<"file is removed since the file is empty"<<endl;
        //to remove file
        remove("note.ini");
    }
}

/*Function Name :searchupdate
  Parameters    :two parameter(vector object and char)
  Return Type   :int return type
  Usage         :to update the duplicate values*/

int searchupdate(vector<student> &std,char* cSearch)
{
    student s;
    int iCheck=0;
    //iterator creation to go word to word in file
    vector<student>:: iterator it;
    //inorder to write updated value opened in write mode

    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(strcmp(s.outkey(),cSearch)==0)
        {
            //the value is been deleted
            std.erase(it);
            std.shrink_to_fit();
            cout<<"Enter value to update"<<endl;
            s.getvalue();
            //the new value is pushed into file
            std.push_back(s);
            iCheck=1;
            break;
        }
    }
    ofstream outfile("note.ini",ios::trunc|ios::out);
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        //the file again written with updated values
        outfile<<s.outkey()<<'='<<s.outvalue()<<endl;
    }
    outfile.close();
    return iCheck;
}

/*Function Name :addtofile
  Parameters    :one vector object parameter
  Return Type   :no return type
  Usage         :to add records in to file and store them in to a vector*/

void student::addconfig(vector<student> &std)
{
    student s;
    vector<student>:: iterator it;
    s.getkey();

    if(searchupdate(std,s.outkey())==1)
    {
        cout<<"updated"<<endl;
    }
    else
    {
        fstream outfile("note.ini",ios::trunc|ios::out);
        s.getvalue();
        std.push_back(s);
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            outfile<<s.outkey()<<'='<<s.outvalue()<<endl;
        }
    outfile.close();
    }

}

/*Function Name :deleteconfig
  Parameters    :one vector object parameter
  Return Type   :no return type
  Usage         :to delete a record from file*/

void student::deleteconfig(vector<student> &std)
{
    char ckey[50];
    student s;
    vector<student>:: iterator it;

    cout<<"Enter the key to delete:";
    getchar();
    cin.get(ckey,50,'\n');
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(strcmp(s.outkey(),ckey)==0)
        {
            std.erase(it);
            cout<<"Deleted"<<endl;
            break;
        }
    }
      fstream outfile("note.ini",ios::trunc|ios::out);
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        outfile<<s.outkey()<<s.outequal()<<s.outvalue()<<endl;
    }
    outfile.close();
    removefile(std);
}

/*Function Name :listconfig
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to display the contents in the file*/

void student::listconfig()
{
    student s;
    ifstream in("note.ini",ios::in);
    char cdata[100];
    while(!in.eof())
    {
        in.getline(cdata,100,'\n');
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
    char cSearch_key[50];
    char cSearch_value[50];
    vector<student>:: iterator it;
    ifstream in("note.ini",ios::in);
    cout<<"do u want search key or value(k/v):";
    cin>>cCheck;
    if(cCheck=='k')
    {
        cout<<"Enter key u want to search:";
        getchar();
        cin.get(cSearch_key,50,'\n');
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            if(strcmp(cSearch_key,s.outkey())==0)
                cout<<s.outkey()<<s.outequal()<<s.outvalue()<<endl;
        }
    }
    else if(cCheck=='v')
    {
        cout<<"Enter value u want to search:";
        getchar();
        cin.get(cSearch_value,50,'\n');
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            if(strcmp(cSearch_value,s.outvalue())==0)
                cout<<s.outkey()<<s.outequal()<<s.outvalue()<<endl;
        }
    }
    else
        cout<<"Enter k or v"<<endl;
}
