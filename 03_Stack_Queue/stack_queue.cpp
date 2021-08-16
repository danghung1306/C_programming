#include <iostream>
#include <stack>

using namespace std;

typedef struct node 
{
	struct node* pNext;
	int data;
}NODE;

typedef struct stack
{
	NODE* pHead;
	NODE* pTail;
}STACK;

void init_stack(STACK& st)
{
	st.pHead = NULL;
	st.pTail = NULL;
}

bool isempty_stack(STACK st)
{
	if (st.pHead == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
NODE* createNode(int x)
{
	NODE* p = new NODE;
	if (p == NULL)
	{
		perror("Khong Du bo nho cap phat");
		exit(1);
	}
	else
	{
		p->data = x;
		p->pNext = NULL;

		return p;
	}
}

void push(STACK &st, int x)
{
	NODE* p = createNode(x); //1 contro gan = 1 function thi ham tajo cung phai la contro
	if (isempty_stack(st))
	{
		st.pHead = p;
		st.pTail = p;
	}
	else
	{
		p->pNext = st.pHead; //chen vao dau stack.
		st.pHead = p;//cap nhat lai pHead cua stack
	}
}

int pop(STACK& st)
{
	if (isempty_stack(st))
	{
		perror("Stack empty-> exit program");
		exit(1);
	}
	else
	{
		NODE* p = st.pHead;
		st.pHead = st.pHead->pNext;
		return p->data;
		delete(p);
	}
}
void nhap_stack(STACK& st, int n)
{
	for (int i = 0; i < n;i++)
	{
		push(st, i);
	}
}

void xuat(STACK st)
{
	if (isempty_stack(st))
	{
		perror("Stack is empty\n");
	}
	else
	{
		NODE* p = st.pHead;
		while (p != NULL)
		{
			cout << p->data << "\t";
			p = p->pNext;
		}
	}
}

int pop_queue(STACK& q)
{
	if (isempty_stack(q))
	{
		perror("Stack is empty-> Exit progream");
		exit(1);
	}
	else
	{
		NODE* p = q.pHead;
		q.pHead = q.pHead->pNext;
		return p->data;
		delete(p);
	}
}

void push_queue(STACK& q, int x)
{
	NODE* p = createNode(x);
	if (isempty_stack(q))
	{
		q.pHead = p;
		q.pHead = p;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;

	}
}
int main()
{
	STACK st1;
	init_stack(st1);
	nhap_stack(st1, 5);
	push(st1, 1306);
	xuat(st1);
	cout << endl;
	pop(st1);
	xuat(st1);
	cout << endl;
	push_queue(st1,13);
	cout << "Sau khi push_queue: "<<endl;
	xuat(st1);
	cout << "\nPop queue" << endl;
	(void)pop_queue(st1);
	xuat(st1);
	cout << endl;
	system("pause");
	return 0;
}

