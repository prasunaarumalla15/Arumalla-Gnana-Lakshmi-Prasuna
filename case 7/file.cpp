/*File Name     :case7.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :09-04-2020
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
    string s_Value;
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
        getline(cin,s_Value);
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

    string outvalue()
    {
        return s_Value;
    }
    void display()
    {
        cout<<c_Key<<"\t"<<s_Value<<endl;
    }
};

/*Function Name :searchupdate
  Parameters    :two parameter(vector object and char)
  Return Type   :int return type
  Usage         :to update the duplicate values*/

int searchupdate(vector<student> &std,char cOption)
{
    student s;
    vector<student>:: iterator it;  //iterator creation to go word to word in file
    ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);  //inorder to write updated value opened in write mode
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
        ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);
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
    ofstream outfile("notes.ini",ios::trunc|ios::out|ios::binary);
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
    ifstream in("notes.ini",ios::in|ios::binary);
    while(1)
    {
        in.read((char*)&s,sizeof(s));   //reading the contents in file
        if(in.eof())break;  //checking for end of the file
            s.display();
    }
    in.close();
}

int main(int argc,char* argv[])
{
    if(argc>=2)
    {
        if(strcmp(argv[1],"-h")==0)     //created a help command
        {
            cout<<"used to do certain file operations like add,update,delete and display using vector. Just select the option"<<" ";
            cout<<"Enter key a char and value as a string"<<endl;
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
            cout<<"Select your option 1.add 2.delete 3.display"<<endl;
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
                default:
                        return 0;
            }
        }
    }
    return 0;
}
