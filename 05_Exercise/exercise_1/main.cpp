#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <regex>

#include "U:/rapidjson/include/rapidjson/writer.h"
#include "U:/rapidjson/include/rapidjson/document.h"
#include "U:/rapidjson/include/rapidjson/stringbuffer.h"
#include "U:/rapidjson/include/rapidjson/istreamwrapper.h"
#include "U:/rapidjson/include/rapidjson/ostreamwrapper.h"

using namespace rapidjson;

using namespace std;

void read_doc(fstream &fs);
void write_doc(fstream &fs);
void date_format(string &buffer);

int main()
{
  /*Declare local varialbe to store the file descriptor*/
  fstream fs;
  /*Open file with read & write mode*/
  fs.open("io.conf",ios::in | ios::out);
  
  /*Check file accessible*/
  if(fs.fail())
  {
      perror("Open file fail");
      return -1;
  }
  else
  {
     //dread_doc(fs);
     write_doc(fs);
  }

  fs.close();
  cout << "End program"<<endl;
  return 0;
}
void read_doc(fstream &fs)
{
  cout << "Reading io.conf ..."<<endl;
      
  IStreamWrapper isw(fs);
  Document mydoc;
  mydoc.ParseStream(isw);
  
  if(mydoc.HasMember("name"))
  {
    cout << "Name: " << mydoc["name"].GetString()<< endl;
  }
  else
  {
    cout << "Object \"name\" does not exist!"<<endl;
  }
  
  if(mydoc.HasMember("version"))
  {
    cout << "Version: " << mydoc["version"].GetString() << endl;
  }
  else
  {
    cout << "Object \"version\" does not exist" << endl;
  }

  if(mydoc.HasMember("date"))
  {
  cout << "Date: "<< mydoc["date"]["day"].GetString()<< "/" << mydoc["date"]["month"].GetString()<<\
                      "/" << mydoc["date"]["year"].GetString()<<endl;
  }
  else
  {
    cout << "Object \"date\" does not exist"<< endl;
  }
}

void write_doc(fstream &fs)
{
  string buffer;
  IStreamWrapper isw(fs);
  Document mydoc;
  mydoc.ParseStream(isw);
  
  if (mydoc.HasMember("version"))
  {
      cin.clear();
      cout << "Write new version: ";
      getline(cin,buffer,'\n');
      mydoc["version"].SetString(buffer.c_str(),buffer.length());
      buffer.clear();
  }
  else
  {
    cout << "Object \"version\" does not exist"<<endl;
  }

  if(mydoc.HasMember("date"))
  {
    cin.clear();
    cout << "Write new date: ";
    getline(cin,buffer,'\n');
    date_format(buffer);
    //cout << buffer <<endl;

  }
  else
  {
    cout << "Object \"date\" does not exist"<<endl;
  }
}
void date_format(string &buffer)
{
  cout << buffer<<endl;
  regex rg("(\[0-9]{2})/(\[0-9]{2})/(\[0-9]{4})");
	smatch match;
  if (regex_search(buffer, match, rg) == true)
	{
		cout << "Match size = " << match.size() << endl;
    buffer.clear();
    cout << "Match: "<< match.str(0)<< endl;
    buffer = match.str(0);
    for(int i = 0;i<match.size();i++)
    {
      cout << match.str(i)<<endl;
    }
	}
	else
	{
		cout << "string is not valid" << endl;
	}
}
