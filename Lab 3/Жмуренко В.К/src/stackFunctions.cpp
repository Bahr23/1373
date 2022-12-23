#include "listFunctions.h"
#include "stackFunctions.h"

box* Stack::push(List& ourList) // ���������� �������� � ������ �����
{
	if (ourList.addressGetter() == nullptr) // ������, ����� ����������� ������� ����� ������������ � �����
		ourList.CreateList(1);
	else
		ourList.newItem(1);
	return(ourList.addressGetter());
}

void Stack::pop(List& ourList) // �������� �������� �� ������ �����
{
	ourList.DeleteItem(1);
}

void Stack::popForIndex(List& ourList, unsigned Index) // �������� �������� �� ����� �� ��� �������
{
	ourList.DeleteItem(Index);
}

bool Stack::isNotEmpty(List& ourList) // �������� ����� �� �������
{
	bool answer = ourList.isListDataNotEmpty();
	return(answer);
}