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

/*Declare struct to stored date & time data type*/
typedef struct date
{
  string day;
  string month;
  string year;
}DATE;

/*Declare prototype funtion to read/write data of rapidjson*/
int read_doc(string f_name);
int write_doc(string f_name);

/*Declare prototype function to parser date/time*/
bool date_format(string &buffer, DATE &dt);
bool ver_format(string &buffer);

int main()
{
  read_doc("io.conf");
  write_doc("io.conf");

  cout << "Updated!"<<endl;
  return 0;
}

/*Implement function to read document*/
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

  /*Declare rapidjson wrap input stream*/
  IStreamWrapper isw(fs);
  /*Declare document stype to store json data*/
  Document mydoc;
  /*ParseStream json to json wrapper*/
  mydoc.ParseStream(isw);
  
  /*Check member exist*/
  if(mydoc.HasMember("name"))
  {
    cout << "Name: " << mydoc["name"].GetString()<< endl;
  }
  else
  {
    cout << "Object \"name\" does not exist!"<<endl;
  }

    /*Check member exist*/
  if(mydoc.HasMember("version"))
  {
    cout << "Version: " << mydoc["version"].GetString() << endl;
  }
  else
  {
    cout << "Object \"version\" does not exist" << endl;
  }

  /*Check member exist*/
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

/*Implement function to wite document*/
int write_doc(string f_name)
{
  /*Declare local varialbe to store the file descriptor*/
  fstream fs;

  /*Declare local varialbe to store buffer*/
  string date_buffer;
  string ver_buffer;
  /*Declare document stype to store json data*/
  Document mydoc;
  
  DATE dt;
  /*Open file with read mode*/
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
      cout << "\nWrite new version: ";
      getline(cin,ver_buffer,'\n');
      if(ver_format(ver_buffer))
      {
        mydoc["version"].SetString(ver_buffer.c_str(),ver_buffer.length());
      }
      else
      {
        /*do nothing*/
      }
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
    if(date_format(date_buffer,dt))
    {
      mydoc["date"]["day"].SetString(dt.day.c_str(),dt.day.length());
      mydoc["date"]["month"].SetString(dt.month.c_str(),dt.month.length());
      mydoc["date"]["year"].SetString(dt.year.c_str(),dt.year.length());
    }
    else
    {
      /*do nothing*/
    }
  }
  else
  {
    cout << "Object \"date\" does not exist"<<endl;
  }
  
  fs.close();
  
  /*Open file with read mode*/
  fs.open(f_name.c_str(),ios::out);
  OStreamWrapper osw(fs);
  Writer<OStreamWrapper> writer(osw);
  /*Write data to document*/
  mydoc.Accept(writer);
  /*Synchronization to make sure the data have been writen to file*/
  fs.sync();
  /*Close file descriptor after implement*/
  fs.close();

  return 1;
}
bool date_format(string &buffer, DATE &dt)
{
  regex rg("^(\[0-9]{2})/(\[0-9]{2})/(\[0-9]{4})");
  smatch match;
  if (regex_search(buffer, match, rg) == true)
  {
    buffer = match.str(0);
    dt.day = match.str(1);
    dt.month = match.str(2);
    dt.year = match.str(3);
    
    return true;
  }
  else
  {
    cout << "Date is not valid recommend: dd/mm/yyyy" << endl;
    return false;
  }
}

bool ver_format(string &buffer)
{
  regex rg("^(\[0-9]{1}).(\[0-9]{1}).(\[0-9]{1})");
  smatch match;
  if (regex_search(buffer, match, rg) == true)
  {
    buffer = match.str(0);
    return true;
  }
  else
  {
    cout << "Version is not valid recommend: x.y.z" << endl;
    return false;
  }
}