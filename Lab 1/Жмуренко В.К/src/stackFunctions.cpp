#include "listFunctions.h"
#include "stackFunctions.h"

box* stack::push(List& ourList) // ���������� �������� � ������ �����
{
	if (ourList.addressGetter() == nullptr) // ������, ����� ����������� ������� ����� ������������ � �����
		ourList.CreateList(1);
	else
		ourList.newItem(1);
	return(ourList.addressGetter());
}

void stack::pop(List& ourList) // �������� �������� �� ������ �����
{
	ourList.DeleteItem(1);
}

bool stack::isEmpty(List& ourList) // �������� ����� �� �������
{
	bool answer = ourList.isListDataNotEmpty();
	return (answer);
}