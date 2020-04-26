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
    string c_Key;
    string c_Value;
public:
    student()
    {

    }
    student(string ckey_cons,string cval_cons)
    {
        c_Key=ckey_cons;
        c_Value=cval_cons;
    }

/*Function Name :getkey
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of key the private member*/

    void getkey()
    {
        cout<<"Enter key:";
        fflush(stdin);
        getline(cin,c_Key);
    }

/*Function Name :getvalue
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of value the private member*/

    void getvalue()
    {
        cout<<"Enter value:";
        fflush(stdin);
        getline(cin,c_Value);
    }

/*Function Name :outkey
  Parameters    :no parameter
  Return Type   :char return type
  Usage         :to return the key*/

    string outkey()
    {
        return c_Key;
    }

/*Function Name :outvalue
  Parameters    :no parameter
  Return Type   :string return type
  Usage         :to return value*/

    string outvalue()
    {
        return c_Value;
    }

    void addconfig(vector<student> &vec);
    void deleteconfig(vector<student> &vec);
    void listconfig();
};

/*Function Name :removefile
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to remove file if file is empty*/

void removefile(vector<student> &vec)
{
    if(vec.empty())
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

int searchupdate(vector<student> &vec,string cSearch_key)
{
    student s;
    int iCheck=0;
    //iterator creation to go word to word in file
    vector<student>:: iterator it;
    //inorder to write updated value opened in write mode
    for(it=vec.begin();it!=vec.end();it++)
    {
        s=*it;
        if(s.outkey()==cSearch_key)
        {
            //the value is been deleted
            vec.erase(it);
           // vec.shrink_to_fit();
            cout<<"Enter value to update"<<endl;
            s.getvalue();
            //the new value is pushed into file
            vec.push_back(s);
            iCheck=1;
            break;
        }
    }
    ofstream outfile("note.ini",ios::trunc|ios::out);
    for(it=vec.begin();it!=vec.end();it++)
    {
        s=*it;
        //the file again written with updated values
        outfile<<s.outkey()<<'='<<s.outvalue()<<endl;
    }
    outfile.close();
    return iCheck;
}

/*Function Name :addconfig
  Parameters    :one vector object parameter
  Return Type   :no return type
  Usage         :to add records in to file and store them in to a vector*/

void student::addconfig(vector<student> &vec)
{
    student s;
    vector<student>:: iterator it;
    s.getkey();
    if(searchupdate(vec,s.outkey())==1)
    {
        cout<<"updated"<<endl;
    }
    else
    {
        fstream outfile("note.ini",ios::trunc|ios::out);
        s.getvalue();
        vec.push_back(s);
        for(it=vec.begin();it!=vec.end();it++)
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

void student::deleteconfig(vector<student> &vec)
{
    string ckey_delete;
    student s;
    vector<student>:: iterator it;
    cout<<"Enter the key to delete:";
    getchar();
    getline(cin,ckey_delete);
    for(it=vec.begin();it!=vec.end();it++)
    {
        s=*it;
        if(s.outkey()==ckey_delete)
        {
            vec.erase(it);
            cout<<"Deleted"<<endl;
            break;
        }
    }
    fstream outfile("note.ini",ios::trunc|ios::out);
    for(it=vec.begin();it!=vec.end();it++)
    {
        s=*it;
        outfile<<s.outkey()<<'='<<s.outvalue()<<endl;
    }
    outfile.close();
    removefile(vec);
}

/*Function Name :listconfig
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to display the contents in the file*/

void student::listconfig()
{
    student s;
    ifstream in("note.ini",ios::in);
    string cdata;
    while(!in.eof())
    {
        getline(in,cdata);
        cout<<cdata<<endl;
    }
    in.close();
}

/*Function Name :searching
  Parameters    :one vector object parameter
  Return Type   :no return type
  Usage         :to search for a key or value and displaying*/

void searching(vector<student> &vec)
{
    student s;
    char cCheck;
    string cSearch_key;
    string cSearch_value;
    vector<student>:: iterator it;
    ifstream in("note.ini",ios::in);
    cout<<"do u want search key or value(k/v):";
    cin>>cCheck;
    if(cCheck=='k')
    {
        cout<<"Enter key u want to search:";
        getchar();
        getline(cin,cSearch_key);
        for(it=vec.begin();it!=vec.end();it++)
        {
            s=*it;
            if(cSearch_key==s.outkey())
                cout<<s.outkey()<<'='<<s.outvalue()<<endl;
        }
    }
    else if(cCheck=='v')
    {
        cout<<"Enter value u want to search:";
        getchar();
        getline(cin,cSearch_value);
        for(it=vec.begin();it!=vec.end();it++)
        {
            s=*it;
            if(cSearch_value==s.outvalue())
                cout<<s.outkey()<<'='<<s.outvalue()<<endl;
        }
    }
    else
        cout<<"Enter k or v"<<endl;
    in.close();
}
