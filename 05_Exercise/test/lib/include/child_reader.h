#pragma once
#include "reader.h"

class child_reader : public reader
{
private:
	string parent;

public:

	void Input();
	void Output();
	int moneyCreateCard();

	child_reader();
	~child_reader();
};


//========== DOCGIATREEM.CPP ==========
