#pragma once
#include "wiseTreesFunctions.h"

class Queue
{
	int size;
	int lastElementPostition;
	AVLnode** infArr;

public:

	Queue(int Size); // �����������

	void push(AVLnode* Inf); // ���������� �������� � ������ �������

	void pop(); // �������� �������� �� ����� �������

	AVLnode* peak(); // ������ �������� � ����� �������

	bool isNotEmpty(); // �������� ������� �� �������

	~Queue(); // ����������
};