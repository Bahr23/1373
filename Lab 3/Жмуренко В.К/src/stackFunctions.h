#pragma once
#include "listFunctions.h"

class Stack
{
public:
	box* push(List& ourList); // ���������� �������� � ������ �����

	void pop(List& ourList); // �������� �������� �� ������ �����

	void popForIndex(List& ourList, unsigned Index); // �������� �������� �� ����� �� ��� �������

	bool isNotEmpty(List& ourList); // �������� ����� �� �������
};