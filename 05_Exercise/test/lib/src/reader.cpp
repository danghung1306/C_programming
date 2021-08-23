#include "reader.h"

/*=========================== PARENT READER==================================*/
void reader::Input()
{
	/*Clear temp data stdin file descriptor before get data*/
	cin.ignore();
	cout << "\nInput your Full Name: ";
	getline(cin, fullName, '\n');
	cout << "\nDate create card(dd/mm/yyyy): ";
	getline(cin, dateCreate, '\n');
	cout << "\nDuration(month): ";
	cin >> duration;
}

/*Method export reader information*/
void reader::Output()
{
	cout << "\nFull Name Reader : " << fullName;
	cout << "\nDate create card : " << dateCreate;
	cout << "\nDuration(month)  : " << duration;
}

/*Method checker child reader or adults reader*/
bool reader::getChecker()
{
	return checker;
}

void reader::setChecker(bool p_checker)
{
	checker = p_checker;
}

/*Contructor Reader*/
reader::reader()
{
}
/*Detructor Reader*/
reader::~reader()
{
}

/*=========================================END PARENT CLASS====================*/
