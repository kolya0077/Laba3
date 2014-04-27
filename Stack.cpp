// Stack.cpp : Defines the entry point for the console application.
//
//!
//! ��� ��������� ��������� ����
//!
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
//!
//! ��������� �����
//!
struct List
{
    int x; /** �������������� ������� */
    List *Next,*Head; /** ������ ����� � ��������� �� ��������� ������� */
};
//!
//! ������� ���������� �������� � ����
//!
void Add(int x, List **MyList) /** ��������� ������� ����� � ��������� �� ����, ��� ���� �������, ��� ����������� ��������� ����� ��� �� ���� ���������� */
{
    List *temp = new List; /** �������� ������ ��� ������ �������� */
    temp->x = x; /** ���������� � ���� x ����������� � ������� ������� x */
    temp->Next = (*MyList)->Head; /** ���������, ��� ��������� ������� ��� ���������� */
    (*MyList)->Head = temp; /** �������� ������ �� ������� ������ */	
}
//!
//! ������� ����������� �����
//!
void Show(List *MyList)
{
	List *temp = MyList->Head; /** ��������� ��������� � ��������� ���, ��� ��� ������� � ������ ����� */
    /** � ������� ����� �������� �� ����� ����� */
    while (temp!=NULL)  /** ������� ��� ������� � ������ ����� */
    {
        printf("%d,%s",temp->x, " "); /** ������� �� ����� ������� ����� */
        temp = temp->Next; /** ��������� � ���������� �������� */
    }
}
//!
//! ������� �������� �������� �����
//!
/**/
int ClearList(struct List **Head)
{   
	struct List *temp = *Head; /** ��������� ��������� ����������� �� �������� ������ */
	int x = temp->x;
	*Head = temp->Next; /** ������ ������� ����� �������, �� ������� �������� Next */
	free(temp); /** ������� ������� */
	return x;
}
//!
//! ������� ������ ������ �����
//!
void Show1(List *MyList)
{
    List *temp = MyList->Head; /** ��������� ��������� � ��������� ���, ��� ��� ������� � ������ ����� */
    printf("%d",temp->x); /** ������� �� ����� ������� ����� */
}
//!
//! ������� ������� ����
//!
void main()
{
    List *MyList = new List; /** �������� ������ ��� ����� */
    MyList->Head = NULL; /** �� ��������� ������ �������������� ������ ������� */
	/** ������� ������ � ���� */ 
	int amount = 0;
	printf("Enter amount of elements in stack:");
	scanf("%d",&amount);
    for (int i=0;i<amount;i++) 
	{
		Add(i,&MyList);
	}
    Show(MyList);
	/** ���������� �������� � ����� */
	int amount1 = 0;
	printf("\nEnter amount of elements you want to add:");
	scanf("%d",&amount1);
	for (int i = 0; i<amount1;i++)
	{
		int item;
		printf("Enter a value of element you want to add:");
		scanf("%d",&item);
		Add(item,&MyList);
	}
	Show(MyList);
	/** �������� �������� �� ����� */
	int amount2 = 0;
	printf("\nEnter amount of elements you want to delete:");
	scanf("%d",&amount2);
	for (int i = 0; i<amount2;i++)
	{
		ClearList(&MyList->Head);
	}
	Show(MyList);
	/** ��������� �������� ������� ����� */
	printf("\nAre you want to learn the value of head?\n");
	char answer = NULL;
	scanf("%s",&answer);
	if (strcmp(&answer,"yes") == 0)
	{
		Show1(MyList);
	}
}