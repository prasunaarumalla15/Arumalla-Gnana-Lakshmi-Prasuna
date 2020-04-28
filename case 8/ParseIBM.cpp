/*File Name     :ParseIBM.cc
  Author Name   :A.G.L.Prasuna
  Created Date  :23-04-2020
  Description   :To display the output from the file in given format
  Requirements  :#include<iostream>,#include<string.h>,#include<regex>,#include<fstream>*/

#include "ParseIBM.h"
#include <iostream>
#include <fstream>
#include <string.h>
//regular expression to access different formats very fastly
#include<regex>

using namespace std;

/*Function Name :HasIBM
  Parameters    :Two string Parameters
  Return Type   :bool return type
  Usage         :to find search string in the given string and return true or false based on that*/

bool ParseIBMString::HasIBM(string str, string searchString)
{
    //converting str to upper and storing it back in str
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	transform(searchString.begin(), searchString.end(), searchString.begin(), ::toupper);
	//npos is a static member constant value(-1) of type size_t,usually used to indicate failure
	if (str.find(searchString) != std::string::npos)
	{
		return true;
	}
	return false;
}

/*Function Name :Copyright
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to compare the string with confidential and copyright along with HasIBM function*/

string ParseIBMString::Copyright(string str)
{
    //calling HasIBM function
	if (HasIBM(str, "Confidential"))
	{
		return "Copyright";
	}
	if (HasIBM(str, "Copyright") && HasIBM(str, "Corp"))
	{
		return "Copyright";
	}
	return "";
}

/*Function Name :isMacro
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to compare the strings with #define by calling HasIBM function*/

string ParseIBMString::isMacro(string str)
{
	if (HasIBM(str, "#define"))
	{
		if (HasIBM(str, ".ibm."))
            return "MacroWith.com";
		else if(HasIBM(str, "KEY"))
            return "MacroWithRegistry";
		else
            return "Macro";
	}
	return "";
}

/*Function Name :url
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to compare input string with http or https by calling HasIBM function*/

string ParseIBMString::url(string str)
{
	if (HasIBM(str, "http:") || HasIBM(str, "https:"))
	{
		return "URL";
	}
	return "";
}

/*Function Name :ServerName
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to compare the input string with O=IBM and CN= by calling HasIBM function*/

string ParseIBMString::ServerName(string str)
{
	if (HasIBM(str, "O=IBM") && HasIBM(str, "CN=") )
	{
		return "ServerName";
	}
	return "";
}

/*Function Name :registry
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to compare the input string with HKLM by calling HasIBM function*/

string ParseIBMString::registry(string str)
{
	if (HasIBM(str, "HKLM"))
	{
		return "Registry";
	}
	return "";
}

/*Function Name :os
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to compare the input string with IBMRT,IBMPC,ibmOS390,IBMCP,ibmAS400,OS2,IBMC by calling HasIBM function*/

string ParseIBMString::os(string str)
{
	if (HasIBM(str, "IBMRT") || HasIBM(str, "IBMPC") ||
		HasIBM(str, "ibmOS390") || HasIBM(str, "IBMCP") || HasIBM(str, "ibmAS400")
		|| HasIBM(str, "OS2") || HasIBM(str, "IBMC"))
	{
		return "OS Specific";
	}
	return "";
}

/*Function Name :comment
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to compare the pattern with input string using regex*/

string ParseIBMString::comment(string str)
{
	string pattern="(/\\*([^*]|[\r\n]|(\\*+([^*/]|[\r\n])))*\\*+/)|(//.*)";
    //storing the pattern in r with extended search
	regex r(pattern, regex_constants::egrep);
	string s1="//";
	string s2="/*";
	string s3=" * ";
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	//iterating and comparing each char of str with r to the end of the str
	for (sregex_iterator it(str.begin(), str.end(), r), end;it != end;++it)
	{
		ipos = str.find(s1);
		ipos1 = str.find("IBM");
		ipos2 = str.find(s2);
		if (ipos == 0 || (ipos > 0 && ipos1 > ipos))
		{
			return "CommentedLine";
		}
		else if( ipos2 >= 0)
		{
			return "CommentedLine";
		}
	}
	ipos = str.find(s2);
	ipos1 = str.find("IBM");
	if (ipos == 0 || (ipos > 0 && ipos1 > ipos))
	{
		return "CommentedLine";
	}
	ipos = str.find(s3);
	if (ipos == 0)
	{
		return "CommentedLine";
	}
	return "";
}

/*Function Name :debug
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to find str1 in the given input str*/

string ParseIBMString::debug(string str)
{
	string str1="xprintf";
	ipos = str.find(str1);
	if (ipos >= 0)
	{
		return "Debug";
	}
	return "";
}
/*Function Name :washType
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :calling Copyright,isMacro,os,registry,ServerName,url,comment,debug function and appending output to string type*/

string ParseIBMString::washType(string str)
{
	string type;
	//append to store output from the end to type
	type.append(Copyright(str));
	type.append(isMacro(str));
	type.append(os(str));
	type.append(registry(str));
	type.append(ServerName(str));
	type.append(url(str));
	type.append(comment(str));
	type.append(debug(str));
	return type;
}

/*Function Name :FileName
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to find the last of the str is "/\\" or not*/

string ParseIBMString::FileName(const string& str)
{
	ifound = str.find_last_of("/\\");
	string path = str.substr(ifound + 1); // check that is OK
	return path;
}

/*Function Name :dirnameOf
  Parameters    :one string parameter
  Return Type   :string return type
  Usage         :to find the last of the str is "\\/" or not*/

string ParseIBMString::dirnameOf(const string& fname)
{
	ipos = fname.find_last_of("\\/");
	return (std::string::npos == ipos)? "": fname.substr(0, ipos);
}

/*Function Name :fileType
  Parameters    :two string parameter
  Return Type   :string return type
  Usage         :to determine the filetype based on filename and filepath*/

string ParseIBMString::fileType(string filename, string filepath)
{
	string filetype;
	if (HasIBM(filename, "IBM"))
	{
		filetype = "FileNameHasIBM";
	}
	if (HasIBM(filepath, "IBM"))
	{
		filetype = "PathNameHasIBM";
	}
	if (HasIBM(filename, "IBM") && HasIBM(filepath, "IBM"))
	{
		filetype = "File&PathNameHasIBM";
	}
	//comparing the end of filename is .rc or .dlg
	if (filename.substr(filename.length() - 3) == ".rc" || filename.substr(filename.length() - 4) == ".dlg")
	{
		filetype = "UI";
	}
	if (filename.substr(filename.length() - 4) == ".def")
	{
		filetype = "External API";
	}
	if (filename.substr(filename.length() - 3) == ".sh")
	{
		filetype = "Script";
	}
	return filetype;
}

/*Function Name :getIBM
  Parameters    :one string parameter
  Return Type   :bool return type
  Usage         :to write the output into another file by calling all above functions*/

bool ParseIBMString::getIBM(string filename)
{
    ifstream infile(filename);
    ofstream myfile;
    string newFile = filename;
    string sToReplace=".txt";
    ipos = newFile.find(sToReplace);
	//the new file created is replaced from .txt to _updated.txt
	newFile.replace(ipos,sToReplace.length(),"_updated.txt");
	myfile.open(newFile);
	if (infile.is_open())
    {
        string sline;
        string sfilename;
        string sLineNumber;
        string sfilepath;
        string sexistingFormat;
        string sfiletype;
        string stype;
		regex r("[0-9]:+");
        printf("\nFileName File Path LineNumber Existing Format\n");
        while(!infile.eof())
        {
            getline(infile,sline);
            cmatch results;
            //to search char by char for r(0-9) in a line
			if (regex_search(sline.c_str(),results, r))
            {
                string delimiter = ":";
                ipos = 0;
                ipos = sline.find(delimiter);
                sLineNumber = sline.substr(0, ipos);
                //erasing line upto delimiter
                sline.erase(0, ipos + delimiter.length());
                sexistingFormat = sline;
                stype = washType(sline);
                cout<<sfiletype.c_str()<<'^'<<sfilename.c_str()<<'^'<<sfilepath.c_str()<<'^'<<sLineNumber.c_str()<<'^'<<sexistingFormat.c_str()<<endl;
                //writing the output to myfile the output file
                myfile << sfiletype.c_str() << "^" << sfilename.c_str()
                << "^" << sfilepath.c_str() << "^" << sLineNumber.c_str() << "^"
                << sexistingFormat.c_str() << "^" << stype.c_str() << endl;
            }
            else
            {
                sfiletype = "---";
                sfilename = FileName(sline.c_str());
                sfilepath = dirnameOf(sline.c_str());
                if (sfilepath.empty())
                {
                    sfilepath = "*****";
                }
                else
                {
                    sfiletype = fileType(sfilename,sfilepath);
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc==2 && strcmp(argv[1],"-h")==0)
    {
        cout<<argv[0]<<" filename.txt"<<endl;
    }
    else if(argc==1)
    {
        cout<<"Use "<<argv[0]<<" -h command";
    }
    else
    {
        ParseIBMString ob;
        ob.getIBM(argv[1]);
    }
    return 0;
}
