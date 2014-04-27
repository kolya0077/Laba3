#include <iostream>
using namespace std;
//!
//! Этот код реализует односвязный список
//!
//!
//! Структура элемента списка
//!
struct data
{
	int a;
};
//!
//! Вторая структура с элементом списка и указателем на следующий элемент
//!
struct List
{
	data d;
	List *next;
};
//!
//! Функция поиска элемента в списке
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
//! Функция удаления элемента из списка
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
//! Главная функция кода
//!
int main()
{
	int amount;
	cout << "Enter amount of items in list:";
	cin >> amount; /** Ввод количества элементов в списке */
	List *u = NULL;
	cout << "List:\n";
	/**
	* Печать списка
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
