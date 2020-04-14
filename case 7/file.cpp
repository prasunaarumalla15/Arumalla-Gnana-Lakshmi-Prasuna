/*File Name     :file.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :14-04-2020
  Description   :To perform the list of operations specified
  Requirements  :#include<iostream>,#include<fstream>,#include<vector>,#include<stdio.h>,#include<string.h>*/

#include<iostream>
#include<vector>    //including the container
#include<fstream>
#include<stdio.h>
#include<string.h>

using namespace std;

class student{
    char c_Key;
    char s_Value[100];
public:

/*Function Name :getkey
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of key the private member*/

    void getkey()
    {
        cout<<"Enter key:";
        cin>>c_Key;
    }

/*Function Name :getvalue
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to get the input of value the private member*/

    void getvalue()
    {
        cout<<"Enter value:";
        getchar();
        cin.get(s_Value,100,'\n');
    }

/*Function Name :outkey
  Parameters    :no parameter
  Return Type   :char return type
  Usage         :to return the key*/

    char outkey()
    {
        return c_Key;
    }

/*Function Name :outvalue
  Parameters    :no parameter
  Return Type   :string return type
  Usage         :to return value*/

    char* outvalue()
    {
        return s_Value;
    }
    void display()
    {
        cout<<c_Key<<"\t"<<s_Value<<endl;
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
    ifstream in("notes.ini",ios::in);
    while(1)
    {
        in.read((char*)&s,sizeof(s));   //reading the contents in file
        iCount++;
        if(in.eof())break;
    }
    if(iCount==0)
    {
        cout<<"file is removed"<<endl;
        remove("notes.ini");        //to remove file
    }
}

/*Function Name :searchupdate
  Parameters    :two parameter(vector object and char)
  Return Type   :int return type
  Usage         :to update the duplicate values*/

int searchupdate(vector<student> &std,char cOption)
{
    student s;
    vector<student>:: iterator it;  //iterator creation to go word to word in file
    ofstream outfile("notes.ini",ios::out);  //inorder to write updated value opened in write mode
    for(it=std.begin();it!=std.end();it++)  //iterating to contents stored in vector
    {
        s=*it;
        if(s.outkey()==cOption)
        {
            std.erase(it);  //the value is been deleted
            cout<<"Enter value to update"<<endl;
            s.getvalue();
            std.push_back(s);
            for(it=std.begin();it!=std.end();it++)
                outfile.write((char*)&(*it),sizeof(s));     //the file again written with updated values
            outfile.close();
            return 1;
        }
    }
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
        ofstream outfile("notes.ini",ios::out);
        s.getkey();
        if(searchupdate(std,s.outkey())==1) //checking for if the key is already present in the file or not
            cout<<"updated"<<endl;
        else
        {
            s.getvalue();
            std.push_back(s);   //all new entries has been pushed backed
            for(it=std.begin();it!=std.end();it++)
            outfile.write((char*)&(*it),sizeof(s));
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
    char ckey;
    student s;
    vector<student>:: iterator it;
    ofstream outfile("notes.ini",ios::out);
    cout<<"Enter the key to delete:";
    cin>>ckey;
    for(it=std.begin();it!=std.end();it++)
    {
        s=*it;
        if(s.outkey()==ckey)
        {
            std.erase(it);
            cout<<"Deleted"<<endl;
        }
    }
    removefile();
    for(it=std.begin();it!=std.end();it++)
        outfile.write((char*)&(*it),sizeof(s));
    outfile.close();
}

/*Function Name :showfromfile
  Parameters    :no parameter
  Return Type   :no return type
  Usage         :to display the contents in the file*/

void showfromfile()
{
    student s;
    ifstream in("notes.ini",ios::in);
    while(1)
    {
        in.read((char*)&s,sizeof(s));   //reading the contents in file
        if(in.eof())break;  //checking for end of the file
            s.display();
    }
    in.close();
}

/*Function Name :searching
  Parameters    :one vector object parameter
  Return Type   :no return type
  Usage         :to search for a key or value and displaying*/

void searching(vector<student> &std)
{
    student s;
    char cCheck;
    char cSearch_key;
    char cSearch_value[5];
    vector<student>:: iterator it;
    ifstream in("notes.ini",ios::in);
    cout<<"do u want search key or value(k/v):";
    cin>>cCheck;
    if(cCheck=='k')
    {
        cout<<"Enter key u want to search:";
        cin>>cSearch_key;
        for(it=std.begin();it!=std.end();it++)
        {
            s=*it;
            if(cSearch_key==s.outkey())
                cout<<s.outkey()<<"\t"<<s.outvalue()<<endl;
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
                cout<<s.outkey()<<"\t"<<s.outvalue()<<endl;
        }
    }
    else
        cout<<"Enter k or v"<<endl;
}

int main(int argc,char* argv[])
{
    if(argc==2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"select add or delete or display option"<<endl;
        }
    }
    else
    {
        vector<student> std;
        vector<student>:: iterator it;
        student s;
        char cOpt;
        while(1)
        {
            cout<<"Select your option 1.add 2.delete 3.display 4.search"<<endl;
            cin>>cOpt;
            switch(cOpt)
            {
                case '1':
                        addtofile(std);
                        break;
                case '2':
                        deletefromfile(std);
                        break;
                case '3':
                        showfromfile();
                        break;
                case '4':
                        searching(std);
                        break;
                default:
                        return 0;
            }
        }
    }
    return 0;
}
