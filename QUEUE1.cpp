// QUEUE1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//!
//! Эта программа реализует очередь
//!
const int N = 5000; /** размер очереди */
/**
* Структура очереди, включает в себя 2 элемента
*/
struct Queue
{
	int data[N];    /** массив данных */
	int last;       /** указатель на начало */
};
//!
//! Функция создания очереди
//!
void Creation(Queue *Q)
{ 
	Q->last = 0; 
}
//!
//! Функция проверки очереди на пустоту
//!
bool Full(Queue *Q)
{
	if (Q->last == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//!
//! Функция добавления элемента в очередь
//!
void Add(Queue *Q)
{
	if (Q->last == N)
	{ 
		cout<<"\nОчередь заполнена\n\n"; 
		return; 
	}
	int value;
	cout << "\nЗначение > "; 
	cin >> value;
	Q->data[Q->last++] = value;
	cout << endl << "Элемент добавлен в очередь\n\n";
}
//!
//! Функция удаления элемента из очереди
//!
void Delete(Queue *Q)
{
	for (int i=0; i<Q->last; i++)/** смещение элементов */
	{
		Q->data[i] = Q->data[i+1]; 
		Q->last--;
	}
}
//!
//! Функция получения начального элемента очереди
//!
int Top(Queue *Q)
{ 
	return Q->data[0]; 
}
//!
//! Функция печати очереди
//!
void print(Queue *Q)
{
	for (int i=0;i<Q->last;i++)
	{
		printf("%d,%s",Q->data[i]," ");
	}
}
//!
//! Главная функция кода
//!
void main()
{
	setlocale(LC_ALL,"Rus");
	Queue Q;
	Creation(&Q);
	char number;
	do
	{
		cout << "\n1. Добавить элемент"<<endl;
		cout << "2. Удалить элемент"<<endl;
		cout << "3. Вывести верхний элемент"<<endl;
		cout << "4. Напечатать очередь"<<endl;
		cout << "0. Выйти\n\n";
		cout << "Номер команды > "; 
		cin >> number;
		switch (number)
		{
			case '1': Add(&Q);
			break;
			//-----------------------------------------------
			case '2':
			if (Full(&Q)) cout<<endl<<"Очередь пуста\n\n";
			else
			{
				Delete(&Q);
				cout<<endl<<"Элемент удален из очереди\n\n";
			} break;
			//-----------------------------------------------
			case '3':
			if (Full(&Q)) cout<<endl<<"Очередь пуста\n\n";
			else cout<<"\nНачальный элемент: "<<Top(&Q)<<"\n\n";
			break;
			//-----------------------------------------------
			case '4':
				print(&Q); break;
			case '0': break;
			default: cout<<endl<<"Команда не определена\n\n";
			break;
		}
	} while(number != '0');
	system("pause");
}

