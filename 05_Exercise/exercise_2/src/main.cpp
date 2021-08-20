#include <cstdlib>
#include <iostream>
#include <thread>
#include <mutex>
#include <unistd.h>


using namespace std;

mutex myMutex;
unsigned int counter;

void myTask_1();
void myTask_2();
void myTask_3();

int main()
{
	counter = 0;
	thread* thr1 = new thread(myTask_1);
	thread* thr2 = new thread(myTask_2);
	thread* thr3 = new thread(myTask_3);

	thr1->join();
	thr2->join();
	thr3->join();
	system("pause");
	return 0;
}

void myTask_1()
{
	while(1)
	{
		sleep(1);
		myMutex.lock();
		counter = counter + 10;
		cout << "Task 1: " << counter << endl;
		myMutex.unlock();
	}
}

void myTask_2()
{
	while(1)
	{
		sleep(3);
		myMutex.lock();
		counter = counter - 5;
		cout << "Task 2: " << counter << endl;
		myMutex.unlock();
	}
}

void myTask_3()
{
	while(1)
	{
		sleep(2);
		myMutex.lock();
		cout << "Task 3: " << counter << endl;
		myMutex.unlock();
	}
}