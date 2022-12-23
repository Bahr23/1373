#pragma once
#include "Queue.h"
#include <string>


template<typename T>
class ArrayList
{
	T* arr;
	int arraySize;
	int lastFilledPart;

public:

	// ������������ � ����������
	ArrayList()
	{
		arraySize = 50;
		arr = new T[arraySize];
		lastFilledPart = -1;
	}
	ArrayList(unsigned size)
	{
		arraySize = size;
		arr = new T[arraySize];
		lastFilledPart = -1;
	}
	~ArrayList()
	{
		delete[]arr;
	}

	// ������, ���������� � ������������ ��������
	void addData(T data); // ������ �������� � ������
	int getSize(); // ��������� ������� ����������� ����� �������
	T* getItem(unsigned Index); // ��������� � �������� �� ��� �������
	void addDataForIndex(unsigned Index, T data); // ������ �������� �� �������
	void fillEntireArray(T data); // ���������� ���� ��������� ������� ���������� ����������� �������
	void deleteItem(unsigned Index); // �������� �������� �������� �� �������
	unsigned IndexforData(T data); // ��������� ������� �� �������� ��������
	T& operator[](int i); // �������� ������ �������� ������� �� ��� �������
	void sizeExpantion(); //������� ��������������� ���������� ������� ��� ��� ������������
};


struct Edge // ��������� �����
{
	int firstVertex; // ������ �������, ����������� ������
	int secondVertex; // ������ �������, ����������� ������
	int weight; // ��� �����
};


class Graph
{
	ArrayList<Edge> minimumSpanningTree; // ������ ��� �������� ����������� ������������ ��������� ������ �����
	ArrayList<Edge> edges; // ������ ��� �������� �����
	ArrayList<int> sets; // ������ ��� �������� ���������������� �����������
	ArrayList<int> rank; // ������ ��� �������� ���������������� �����������
	ArrayList<std::string> vertexesNames; // ������ ��� �������� �������� ������, ��������� �� �����
	bool resultOfChecking; // ������� ����������, ��� �������� ���������� �������� �����

public:

	// ������� ������� ���������������� ��������
	void MakeSet(int x); // ������� �������� ������ ������������ ��� ��������
	int Find(int x); // �������, ������������ ������������, � �������� ����������� �������
	void Union(int x, int y); // �������, ������������ ��� ������������ � ����

	// ������� �����
	bool readDataFromFile(std::string fileName); // ������� ���������� ������ �� �����
	void printOurGraph(); // ������� ������ ��������� �� ����� �����
	void insertionSortOfEdges(); // ������� ���������� ��������� ��� ������� �����
	void kraskalAlgorithm(); // ������� ��������� ��������
	void printMinimumSpanningTree(); // ������� ������ ������������ ��������� ������ (���� � ������� ������� + ��������� ���)
	void DFS(int vertexNumber); // ������� ������ ����� ������� � �������
	void BFS(int vertexNumber); // ������� ������ ����� ������� � ������
};

