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

typedef struct date
{
  string day;
  string month;
  string year;

  date()
  {
    day.clear();
    month.clear();
    year.clear();
  }

}DATE;

int read_doc(string f_name);
int write_doc(string f_name);
void date_format(string &buffer, DATE &dt);

int main()
{
  //read_doc("io.conf");
  write_doc("io.conf");

  cout << "End program"<<endl;
  return 0;
}
int read_doc(string f_name)
{
  cout << "Reading io.conf ..."<<endl;
    /*Declare local varialbe to store the file descriptor*/
  fstream fs;
  /*Open file with read & write mode*/
  fs.open(f_name.c_str(),ios::in);
  
  /*Check file accessible*/
  if(fs.fail())
  {
      perror("Open file fail");
      return -1;
  }
      
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
  fs.close();
  return 1;
}

int write_doc(string f_name)
{
  /*Declare local varialbe to store the file descriptor*/
  fstream fs;

  string date_buffer;
  string ver_buffer;
  Document mydoc;
  DATE dt;
  /*Open file with read & write mode*/
  fs.open(f_name.c_str(),ios::in);
  
  /*Check file accessible*/
  if(fs.fail())
  {
      perror("Open file fail");
      return -1;
  }
  
  IStreamWrapper isw(fs);
  mydoc.ParseStream(isw);
  
  if (mydoc.HasMember("version"))
  {
      cin.clear();
      ver_buffer.clear();
      cout << "Write new version: ";
      getline(cin,ver_buffer,'\n');
      mydoc["version"].SetString(ver_buffer.c_str(),ver_buffer.length());
  }
  else
  {
    cout << "Object \"version\" does not exist"<<endl;
  }

  if(mydoc.HasMember("date"))
  {
    cin.clear();
    date_buffer.clear();
    cout << "Write new date: ";
    getline(cin,date_buffer,'\n');
    date_format(date_buffer,dt);
    mydoc["date"]["day"].SetString(dt.day.c_str(),dt.day.length());
    mydoc["date"]["month"].SetString(dt.month.c_str(),dt.month.length());
    mydoc["date"]["year"].SetString(dt.year.c_str(),dt.year.length());

  }
  else
  {
    cout << "Object \"date\" does not exist"<<endl;
  }
  
  fs.close();

  fs.open(f_name.c_str(),ios::out);

  OStreamWrapper osw(fs);
  Writer<OStreamWrapper> writer(osw);
  mydoc.Accept(writer);
  fs.sync();
  fs.close();

  return 1;
}
void date_format(string &buffer, DATE &dt)
{
  regex rg("^(\[0-9]{2})/(\[0-9]{2})/(\[0-9]{4})");
	smatch match;
  if (regex_search(buffer, match, rg) == true)
	{
    buffer = match.str(0);
    dt.day = match.str(1);
    dt.month = match.str(2);
    dt.year = match.str(3);
	}
	else
	{
		cout << "String is not valid recommend: dd/mm/yyyy" << endl;
	}
}
