#include "Queue.h"
#include<iostream>
using namespace std;

Queue::Queue(int Size) // �����������

{
	size = Size;
	lastElementPostition = -1;
	infArr = new int [size];
}

void Queue::push(int Inf) // ���������� �������� � ������ �������
{
	if (lastElementPostition < size - 1)
	{
		lastElementPostition++;
		infArr[lastElementPostition] = Inf;
	}
	else
		cout << endl << "Error.The queue is full";
}

void Queue::pop() // �������� �������� �� ����� �������
{
	if (lastElementPostition > 0)
	{
		for (int i = 1; i <= lastElementPostition; i++)
			infArr[i - 1] = infArr[i];
	}
	else
		infArr[lastElementPostition] = -1;
	lastElementPostition--;
}

int Queue::peak() // ������ �������� � ����� �������
{
	if (isNotEmpty())
		return (infArr[0]);
	else
	{
		cout << endl << "Error.The queue is empty";
		return -1;
	}
}

bool Queue::isNotEmpty() // �������� ������� �� �������
{
	if (lastElementPostition!=-1 )
		return true;
	else
		return false;
}

Queue::~Queue() // ����������
{
	delete infArr;
}