#pragma once
#include "wiseTreesFunctions.h"

struct box				// ��������� �������� ������������ ������
{
	AVLnode* FirstInf;
	box* Adr;
};

class List
{
	box* Head;
	unsigned Size;

public:

	// �����������
	List();

	// ������, ���������� � ����������� �������
	void CreateList(unsigned Lenght);	// �������� ������������ ������
	box* addressGetter();	// ��������� ������ ������ �������� ��������
	void dataInserting(AVLnode* data1);	// ���� ������ � ������� ������� ������
	void sizeOfList(box* Beg);	// �������, ���������� ������ ������
	void newItem(unsigned Index);	// ���������� ������ �������� � ������
	box* getItem(unsigned Index);	// ��������� ������ ������������� �������� �� �������
	unsigned IndexforData(AVLnode* data1); // ��������� ������� �� �������� ������ ��������
	void DeleteItem(unsigned Index);	// ������� ������� �� �������
	bool isListDataNotEmpty();	// �������� ������ �� ������� ������ � ���
	void DeleteList();	// ������� ������ � ����������� ������
};
