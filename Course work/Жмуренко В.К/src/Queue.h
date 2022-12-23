#pragma once

class Queue
{
	int size;
	int lastElementPostition;
	int* infArr;

public:

	Queue(int Size); // �����������

	void push(int Inf); // ���������� �������� � ������ �������

	void pop(); // �������� �������� �� ����� �������

	int peak(); // ������ �������� � ����� �������

	bool isNotEmpty(); // �������� ������� �� �������

	~Queue(); // ����������
};