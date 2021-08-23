#pragma once
#include"child_reader.h"
#include"adults_reader.h"
#include<vector>

class libForm
{
private:

	vector<reader*> list_reader;

public:

	void Input();
	void Output();
	int sumOfMoney();

	libForm();
	~libForm();
};

