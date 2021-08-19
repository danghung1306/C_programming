#include <iostream>
#include <regex>
#include <string>

using namespace std;

class date_format
{
private:
    string buffer;
    regex rg;
    smatch match;

public:
    void set_buffer(string buffer);
};