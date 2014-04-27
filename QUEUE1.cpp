// QUEUE1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
//!
//! ��� ��������� ��������� �������
//!
const int N = 5000; /** ������ ������� */
/**
* ��������� �������, �������� � ���� 2 ��������
*/
struct Queue
{
	int data[N];    /** ������ ������ */
	int last;       /** ��������� �� ������ */
};
//!
//! ������� �������� �������
//!
void Creation(Queue *Q)
{ 
	Q->last = 0; 
}
//!
//! ������� �������� ������� �� �������
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
//! ������� ���������� �������� � �������
//!
void Add(Queue *Q)
{
	if (Q->last == N)
	{ 
		cout<<"\n������� ���������\n\n"; 
		return; 
	}
	int value;
	cout << "\n�������� > "; 
	cin >> value;
	Q->data[Q->last++] = value;
	cout << endl << "������� �������� � �������\n\n";
}
//!
//! ������� �������� �������� �� �������
//!
void Delete(Queue *Q)
{
	for (int i=0; i<Q->last; i++)/** �������� ��������� */
	{
		Q->data[i] = Q->data[i+1]; 
		Q->last--;
	}
}
//!
//! ������� ��������� ���������� �������� �������
//!
int Top(Queue *Q)
{ 
	return Q->data[0]; 
}
//!
//! ������� ������ �������
//!
void print(Queue *Q)
{
	for (int i=0;i<Q->last;i++)
	{
		printf("%d,%s",Q->data[i]," ");
	}
}
//!
//! ������� ������� ����
//!
void main()
{
	setlocale(LC_ALL,"Rus");
	Queue Q;
	Creation(&Q);
	char number;
	do
	{
		cout << "\n1. �������� �������"<<endl;
		cout << "2. ������� �������"<<endl;
		cout << "3. ������� ������� �������"<<endl;
		cout << "4. ���������� �������"<<endl;
		cout << "0. �����\n\n";
		cout << "����� ������� > "; 
		cin >> number;
		switch (number)
		{
			case '1': Add(&Q);
			break;
			//-----------------------------------------------
			case '2':
			if (Full(&Q)) cout<<endl<<"������� �����\n\n";
			else
			{
				Delete(&Q);
				cout<<endl<<"������� ������ �� �������\n\n";
			} break;
			//-----------------------------------------------
			case '3':
			if (Full(&Q)) cout<<endl<<"������� �����\n\n";
			else cout<<"\n��������� �������: "<<Top(&Q)<<"\n\n";
			break;
			//-----------------------------------------------
			case '4':
				print(&Q); break;
			case '0': break;
			default: cout<<endl<<"������� �� ����������\n\n";
			break;
		}
	} while(number != '0');
	system("pause");
}

