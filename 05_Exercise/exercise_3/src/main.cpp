#include "libForm.h"


int main()
{
	libForm* x = new libForm;
	x->Input();
	x->Output();
	cout << "\n\t COST OF CREATE LIBRARY CARD FOR ALL READER: " \
		<< x->sumOfMoney() << " VND"<<endl;

	delete x;
	system("pause");
	return 0;
}