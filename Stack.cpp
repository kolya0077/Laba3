// Stack.cpp : Defines the entry point for the console application.
//
//!
//! Эта программа реализует стек
//!
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
//!
//! Структура стека
//!
struct List
{
    int x; /** информационный элемент */
    List *Next,*Head; /** Голова стека и указатель на следующий элемент */
};
//!
//! ФУНКЦИЯ ДОБАВЛЕНИЯ ЭЛЕМЕНТА В СТЕК
//!
void Add(int x, List **MyList) /** Принимаем элемент стека и указатель на стек, при этом говорим, что принимаемый указатель будет сам по себе указателем */
{
    List *temp = new List; /** Выделяем память для нового элемента */
    temp->x = x; /** Записываем в поле x принимаемый в функцию элемент x */
    temp->Next = (*MyList)->Head; /** Указываем, что следующий элемент это предыдущий */
    (*MyList)->Head = temp; /** Сдвигаем голову на позицию вперед */	
}
//!
//! ФУНКЦИЯ ОТОБРАЖЕНИЯ СТЕКА
//!
void Show(List *MyList)
{
	List *temp = MyList->Head; /** Объявляем указатель и Указываем ему, что его позиция в голове стека */
    /** с помощью цикла проходим по всему стеку */
    while (temp!=NULL)  /** выходим при встрече с пустым полем */
    {
        printf("%d,%s",temp->x, " "); /** Выводим на экран элемент стека */
        temp = temp->Next; /** Переходим к следующему элементу */
    }
}
//!
//! ФУНКЦИЯ УДАЛЕНИЯ ЭЛЕМЕНТА СТЕКа
//!
/**/
int ClearList(struct List **Head)
{   
	struct List *temp = *Head; /** Объявляем указатель ссылающийся на значение головы */
	int x = temp->x;
	*Head = temp->Next; /** Делаем головой стека элемент, на который указывал Next */
	free(temp); /** Удаляем элемент */
	return x;
}
//!
//! ФУНКЦИЯ ПЕЧАТИ ГОЛОВЫ СТЕКА
//!
void Show1(List *MyList)
{
    List *temp = MyList->Head; /** Объявляем указатель и Указываем ему, что его позиция в голове стека */
    printf("%d",temp->x); /** Выводим на экран элемент стека */
}
//!
//! Главгая функция кода
//!
void main()
{
    List *MyList = new List; /** Выделяем память для стека */
    MyList->Head = NULL; /** Во избежание ошибок инициализируем первый элемент */
	/** Заносим данные в стек */ 
	int amount = 0;
	printf("Enter amount of elements in stack:");
	scanf("%d",&amount);
    for (int i=0;i<amount;i++) 
	{
		Add(i,&MyList);
	}
    Show(MyList);
	/** Добавление элемента к стеку */
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
	/** Удаление элемента из стека */
	int amount2 = 0;
	printf("\nEnter amount of elements you want to delete:");
	scanf("%d",&amount2);
	for (int i = 0; i<amount2;i++)
	{
		ClearList(&MyList->Head);
	}
	Show(MyList);
	/** Получение значения вершины стека */
	printf("\nAre you want to learn the value of head?\n");
	char answer = NULL;
	scanf("%s",&answer);
	if (strcmp(&answer,"yes") == 0)
	{
		Show1(MyList);
	}
}