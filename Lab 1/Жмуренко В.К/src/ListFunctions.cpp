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
		HeadItem->Inf = ' ';
		HeadItem->Adr = Next;
		Next = HeadItem;
	}
	Head = HeadItem;
}

box * List::addressGetter() // ��������� ������ ������ �������� ��������
{
	return(Head);
}

void List:: dataInserting(char data) // ���� ������ � ������� ������� ������
{
	Head->Inf = data;
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
	if (Index==1)	// ���� ����� ������� ����������� � ������ ������
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

unsigned List::IndexforData(char data) // ��������� ������� �� �������� ������ ��������
{
	unsigned Index=0;
	bool isDataExists = 0;
	box* Item = Head;
	while (Item)
	{
		Index++;
		if (Item->Inf == data)
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



ArrayList::ArrayList() // �����������
{
	capacity = 4;
	size = -1;
	arr = new char[capacity];
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = ' ';
	}
}

ArrayList::ArrayList(unsigned Size) // �����������
{
	capacity = Size;
	size = -1;
	arr = new char[capacity];
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = ' ';
	}
}

char * ArrayList::getItem(unsigned Index) // ��������� � �������� �� ��� �������
{
	if (Index >= 0 && Index <= size)
	{
		return(&arr[Index]);
	}
	else
	{
		std::cout << "\nThis array item is missing. Try again\n";
	}
}

char ArrayList::getData(unsigned Index) // ������ ������ �� �������
{
	return arr[Index];
}

int ArrayList ::getSize() // ��������� ������� �������
{
	return (size+1);
}

int ArrayList::getCapacity()	// ��������� ������� ���������� ������ ��� �������
{
	return(capacity);
}

void ArrayList::addData(char data) // ������ �������� � ������
{
	if (size < capacity - 1)
	{
		size++;
		arr[size] = data;
	}
	else
	{
		sizeExpantion();
		size++;
		arr[size] = data;
	}
}

void ArrayList::addDataForIndex(unsigned Index, char data) // ������ �������� �� �������
{
	if (Index >= 0 && Index <= size)
	{
		arr[Index] = data;

	}
	else
	{
		std::cout << "\nThis array item is missing. Try again\n";
	
	}
}

void ArrayList::deleteItem(unsigned Index) // �������� �������� �������� �� �������
{
	if (Index >= 0 && Index < size)
	{
		if (Index == 0)
		{
			for (int i = 1; i < size; i++)
			{
				arr[i - 1] = arr[i];
			}
			size--;
		}
		else
		{
			for (int i = Index; i < size; i++)
			{
				arr[i - 1] = arr[i];
			}
			size--;
		}
	}
	else
	{
		std::cout << "\nThis array item is missing. Try again\n";
	}
}

unsigned ArrayList::IndexforData(char data) // ��������� ������� �� �������� ��������
{
	unsigned Index = 0;
	bool isDataExists = 0;
	for (int i = 0; i <= size; i++)
	{
		if (arr[i] == data)
		{
			isDataExists = 1;
			break;
		}
		Index++;
	}
	if (isDataExists == 0)
		std::cout << "\nThere is no array element with such data\n";
	else
		return Index;
}

void ArrayList::sizeExpantion() //������� ��������������� ���������� ������� ��� ��� ������������
{
	char* newArr = new char[capacity * 2];
	for (int i = 0; i <= size; i++)
	{
		newArr[i] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	capacity = capacity * 2;
}

ArrayList::~ArrayList() // ����������
{
	delete arr;
}