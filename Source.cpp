#include <iostream>
using namespace std;
//!
//! ���� ��� ��������� ����������� ������
//!
//!
//! ��������� �������� ������
//!
struct data
{
	int a;
};
//!
//! ������ ��������� � ��������� ������ � ���������� �� ��������� �������
//!
struct List
{
	data d;
	List *next;
};
//!
//! ������� ������ �������� � ������
//!
void find(int *j)
{
	int position;
	cout << "Enter a position of item:";
	cin >> position;
	for (int i=0;i<*j;i++)
	{
		if (position == i)
		{
			cout << position + 5 << endl;
		}
	}
}
//!
//! ������� �������� �������� �� ������
//!
void remove(List **u,int *b)
{
	int position;
	cout << "Enter a number of item you want to remove:";
	cin >> position;
	if (*u == 0)
	{
		cout  << "The List is empty";
	}
	List *t = *u;
	for (int i = 0;i < *b;i++)
	{
		if (position == i)
		{
			t->d.a = i+5;
			delete &t->d.a;
			t->d.a = (i++)+5;
		}
		t->d.a = i+5;
		cout << t->d.a<< endl;
	}
}
//!
//! ������� ������� ����
//!
int main()
{
	int amount;
	cout << "Enter amount of items in list:";
	cin >> amount; /** ���� ���������� ��������� � ������ */
	List *u = NULL;
	cout << "List:\n";
	/**
	* ������ ������
	*/
	for (int i = 0;i < amount;i++)
	{	
		u = new List;
		u->d.a = i+5;
		cout << u->d.a << endl;
		u->next = NULL;
	}
	find(&amount);
	remove(&u,&amount);
}
