#include "child_reader.h"

/*=============================CHILD CLASS=====================================*/

/* Method input for child reader information*/
void child_reader::Input()
{
	reader::Input();
	cin.ignore();
	cout << "\nInput your parent: ";
	getline(cin, parent);
}

/*Method export child reader information*/
void child_reader::Output()
{
	reader::Output();
	cout << "\nParent           : " << parent;
	cout << "\nMoney Create Card: " << moneyCreateCard() <<" VND"<< endl;
}

/*Method charge money for child reader*/
int child_reader::moneyCreateCard()
{
	return duration * 5000;
}

child_reader::child_reader() {}

child_reader::~child_reader() {}

/*==============================END CHILD CLASS================================*/
