#pragma once
#include<iostream>
using namespace std;
#include<string>

class reader
{
protected:
	string fullName;
	string dateCreate;
	int duration;
	bool checker;// true : CHILD, false: ADULTS

public:

	virtual void Input();
	virtual void Output();
	virtual int moneyCreateCard() = 0;
	bool getChecker();
	void setChecker(bool p_checker);

	reader();
	~reader();
};
