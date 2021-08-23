#include "adults_reader.h"
/*==============================ADULTS CLASS===================================*/

void adults_reader::Input()
{
	reader::Input();
	cin.ignore();
	cout << "\nInput your ID:  ";
	getline(cin, idNumber);
}

void adults_reader::Output()
{
	reader::Output();
	cout << "\nID               : " << idNumber;
	cout << "\nMoney Create Card: " << moneyCreateCard() <<" VND"<< endl;
}

int adults_reader::moneyCreateCard()
{
	return duration * 10000;
}

adults_reader::adults_reader() {}



adults_reader::~adults_reader() {}
/*====================================END ADULTS CLASS=======================*/

