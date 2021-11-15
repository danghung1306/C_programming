#include "libForm.h"

/*==================================LIBRARY CLASS============================*/

void libForm::Input()
{
	int selection;
	while (true)
	{
		system("cls");
		cout << "\n\n\t\t ============ WELLCOME LIBRARY DPHUNG ============";
		cout << "\n\t 1. Child Reader";
		cout << "\n\t 2. Adults Reader";
		cout << "\n\t 0. Exit & Print the list of all reader";
		cout << "\n\n\t\t ============     END    ============";

		cout << "\nPlease Input your selection: ";
		cin >> selection;

		reader* x;
		if (selection == 1)
		{
			/*Create object to described child reader information*/
			x = new child_reader;
			cout << "\n\n\t\t INPUT CHILD READER INFORMATION\n";
			x->Input();
			/*Set this object is child reader*/
			x->setChecker(true);
			/*Add reader into reader list*/
			list_reader.push_back(x);

		}
		else if (selection == 2)
		{
			x = new adults_reader;
			cout << "\n\n\t\t INPUT ADULTS READER INFORMATION\n";
			x->Input();
			x->setChecker(false);
			list_reader.push_back(x);
		}
		else if (selection == 0)
		{
			break;
		}
		else
		{
			cout << "\nSelection is invalid. Please re-check";
			system("pause");
		}
	}
}

void libForm::Output()
{
	cout << "\n\n\t\t ===== LIST OF READER =====\n";

	for (int i = 0; i < list_reader.size(); i++)
	{
		if (list_reader[i]->getChecker() == true)
		{
			cout << "\n\n\t\t NUMBER OF CHILD READER:  " << i + 1;
			list_reader[i]->Output();
		}
		else
		{
			cout << "\n\n\t\t NUMBER OF ADULTS READER:  " << i + 1;
			list_reader[i]->Output();
		}
	}
}

int libForm::sumOfMoney()
{
	int sum = 0;
	for (int i = 0; i < list_reader.size(); i++)
	{
		sum = sum + list_reader[i]->moneyCreateCard();
	}
	return sum;
}


libForm::libForm()
{
}


libForm::~libForm()
{
}

/*==================================END LIBRARY CLASS========================*/
