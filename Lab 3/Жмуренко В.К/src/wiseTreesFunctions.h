#pragma once

struct binaryNode // ��������� �������� ��������� ������
{
	binaryNode() {};
	binaryNode(int data, binaryNode* par)
	{
		Inf = data;
		parent = par;
		leftChild = nullptr;
		rightChild = nullptr;
	}

	int Inf;
	binaryNode* leftChild, * rightChild, *parent; // ������ ���� ������ ��������� �� ����� � ��������
};

class BinaryTree
{
	binaryNode* ourTree; // ����� �������� ����� ������
public:

	BinaryTree(); // �����������

	void createNode(int data, binaryNode*& Node, binaryNode* par, bool isEmpty);		// ������� �������� �������� ������
	void createRoot(int data, bool isEmpty);							// ������� �������� ������������ ����� ������
	binaryNode* rootAddressGetter();					// ��������� ������ ������������ ����� ������
	void insertLeft(binaryNode* parent, int data, bool isEmpty);		// ������� ���������� ������ �������� ������
	void insertRight(binaryNode* parent, int data, bool isEmpty);		// ������� ���������� ������� �������� ������
	void passingTree(binaryNode* ourTree, int *& arr, int& point);				// ������� ��������������� ������ ������
	void deleteTree(binaryNode*& ourTree);				// ������� ������������� ������ ������
};

struct AVLnode
{
	int Inf;
	AVLnode* leftChild, * rightChild, * parent; // ������ ���� ������ ��������� �� ����� � ��������
	int balance; // ������ ��������
};

class AVLTree
{
	AVLnode* ourTree; // ����� �������� ����� ������
public:
	
	AVLTree(); // �����������
	int balance(AVLnode*& Node); // ��������������� ������� ��� ������������ �������
	int balanceDifference(AVLnode*& Node); // ��������������� ������� ��� ���������, ����� ������ ������� "�������"
	void correctingNodeBalance(AVLnode*& Node); // ������� ������ ��������������� ������
	void balancingTree(AVLnode*& Node);  // ������� ������������ ������
	AVLnode* insert(int data, AVLnode*& Node); // ������� �������� �������� ������
	AVLnode* singleLeftRotate(AVLnode*& Node); // ����� �������
	AVLnode* singleRightRotate(AVLnode*& Node); // ������ �������
	AVLnode* findMin(AVLnode*& Node); // ������� ������ �������� ���-������ � ����������� ��������� ������
	AVLnode* findMax(AVLnode*& Node); // ������� ������ �������� ���-������ � ������������ ��������� ������
	AVLnode* findForData(int data, AVLnode*& Node); // ������� ������ �������� ���-������ �� �������� ������
	AVLnode* deleteTreeElement(int data, AVLnode*& Node); // ������� �������� �������� �� ��������
	void deleteTree(AVLnode*& ourTree);	// ������� ������������� ������ ������
	void balanceChangingTree(AVLnode*& Node);
	void insert(int data); // ������� ������ �������� �������� ������
	void deleteTreeElement(int data); // ������� �������� �������� ������
	void straightPassing(); // ������� ������� ������ ������ ����� ��������
	void centralPassing(AVLnode*& Node); // ������� ��������������� ������ ����� ��������
	void reversePassing(AVLnode*& Node); // ������� ��������� ������ ����� ��������
	void widePassing(); // ������� ������ � ������ ����� �������
	void centralPassing(); // ������� ������ ��������������� ������
	void reversePassing(); // ������� ������ ��������� ������
};