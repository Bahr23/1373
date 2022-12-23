#include <iostream>
#include "listFunctions.h"

List::List() // �����������
{
	Head = nullptr;
	Size = 0;
}

void List::CreateList(unsigned Lenght) // �������� ������������ ������
{
	box* HeadItem = nullptr; // ����� ���������� �������� ������
	box* Next = nullptr; // ����� ���������� �� ��������� �������� ������
	for (unsigned i = 1; i <= Lenght; ++i)
	{
		HeadItem = new box;
		HeadItem->FirstInf = nullptr;
		HeadItem->Adr = Next;
		Next = HeadItem;
	}
	Head = HeadItem;
}

box* List::addressGetter() // ��������� ������ ������ �������� ��������
{
	return(Head);
}

void List::dataInserting(AVLnode* data1) // ���� ������ � ������� ������� ������
{
	Head->FirstInf = data1;
}

void List::sizeOfList(box* Beg) // �������, ���������� ������ ������
{
	while (Beg)
	{
		++Size;
		Beg = Beg->Adr;
	}
}

void List::newItem(unsigned Index) // ���������� ������ �������� � ������
{
	box* Item = new box;
	if (Index == 1)	// ���� ����� ������� ����������� � ������ ������
	{
		Item->Adr = Head;
		Head = Item;
	}
	else
	{
		box* PredItem = Head; // �������, ������� ����� ��������� � ������ ����� �����������
		Index--;
		while (PredItem->Adr && (Index--))
			PredItem = PredItem->Adr;
		Item->Adr = PredItem->Adr;
		PredItem->Adr = Item;
	}
}

box* List::getItem(unsigned Index) // ��������� ������ ������������� �������� �� �������
{
	box* Item = Head;
	while (Item && --Index)
		Item = Item->Adr;
	if (!Item) // �������������� ��� ��������� ������� �� ������� ������
		std::cout << "This list item is missing. Try again\n";
	return Item;
}

unsigned List::IndexforData(AVLnode* data1) // ��������� ������� �� �������� ������ ��������
{
	unsigned Index = 0;
	bool isDataExists = 0;
	box* Item = Head;
	while (Item)
	{
		Index++;
		if (Item->FirstInf == data1)
		{
			isDataExists = 1;
			break;
		}
	}
	if (isDataExists == 0)
	{
		std::cout << "\nThere is no list element with such data\n";
		return 0;
	}
	else
		return Index;
}

void List::DeleteItem(unsigned Index) // ������� ������� �� �������
{
	box* Item = new box;
	if (Index == 1) // ���� ������� ������ ������� ������
	{
		Item = Head->Adr;
		delete Head;
		Head = Item;
	}
	else
	{
		Index--;
		Item = getItem(Index);
		box* DelItem = Item->Adr;
		Item->Adr = DelItem->Adr;
		delete DelItem;
	}
}

bool List::isListDataNotEmpty() // �������� ������ �� ������� ������ � ���
{
	if (Head == nullptr) // ���� � Head ������� �����, �� ������ ����
		return 0;
	else				// ���� �������� ���� �� ���� �������, �� ������ �� ����
		return 1;
}

void List::DeleteList() // ������� ������ � ����������� ������
{
	box* Next; // ����� ���������� �� ��������� �������� ������
	while (Head)
	{
		Next = Head->Adr;
		delete Head;
		Head = Next;
	}
}