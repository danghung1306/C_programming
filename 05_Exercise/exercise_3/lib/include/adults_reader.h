#pragma once
#include"reader.h"

class adults_reader : public reader
{
private:
	string idNumber;
public:

	void Input();
	void Output();
	int moneyCreateCard();

	adults_reader();
	~adults_reader();
};
