#pragma once
class stack
{
public:
	//������
	box* push(List& ourList); // ���������� �������� � ������ �����
	void pop(List& ourList); // �������� �������� �� ������ �����
	bool isEmpty(List& ourList); // �������� ����� �� �������
};