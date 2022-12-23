#include "listFunctions.h"
#include "stackFunctions.h"
#include "queue.h"
#include "wiseTreesFunctions.h"
#include<iostream>
using namespace std;

BinaryTree::BinaryTree()	// �����������
{
	ourTree = nullptr;
}

void BinaryTree::createNode(int data, binaryNode*& Node, binaryNode* par, bool isEmpty)	// ������� �������� �������� ������
{
	Node = new binaryNode;
	if (isEmpty == false)
		Node->Inf = data;
	else
		Node->Inf = 0;
	Node->leftChild = nullptr;
	Node->rightChild = nullptr;
	Node->parent = par;
}

void BinaryTree::createRoot(int data, bool isEmpty)	// ������� �������� ������������ ����� ������
{
	createNode(data, ourTree, nullptr, isEmpty);
}


binaryNode* BinaryTree::rootAddressGetter()		// ��������� ������ ������������ ����� ������
{
	return(ourTree);
}

void BinaryTree::insertLeft(binaryNode* parent, int data, bool isEmpty)		// ������� ���������� ������ �������� ������
{
	createNode(data, parent->leftChild, parent, isEmpty);
}

void BinaryTree::insertRight(binaryNode* parent, int data, bool isEmpty)		// ������� ���������� ������� �������� ������
{
	createNode(data, parent->rightChild, parent, isEmpty);
}

void BinaryTree::passingTree(binaryNode* ourTree, int *& arr, int& point)              //������� ��������������� ������ ������
{
	if (ourTree != nullptr)               //���� �� ���������� ������ �����
	{
		passingTree(ourTree->leftChild, arr, point);               //����������� ������� ��� ������ ������ ���������
		cout << ourTree->Inf << '\t';
		arr[point] = ourTree->Inf;
		point++;
		passingTree(ourTree->rightChild, arr, point);               //����������� ������ ��� ������ ������� ���������
	}
}

void BinaryTree::deleteTree(binaryNode*& ourTree)		// ������� ������������� ������ ������
{
	if (ourTree->leftChild)
		deleteTree(ourTree->leftChild);
	if (ourTree->rightChild)
		deleteTree(ourTree->rightChild);
	delete ourTree;
}

AVLTree::AVLTree()		// �����������
{
	ourTree = nullptr;
}

int AVLTree::balance(AVLnode*& Node) // Height
{
	return (Node ? Node->balance : 0);
}

int AVLTree::balanceDifference(AVLnode*& Node) // balance Factor
{
	return(balance(Node->rightChild) - balance(Node->leftChild));
}

void AVLTree::correctingNodeBalance(AVLnode*& Node) // Correcting Height   balance - ������
{
	int left = balance(Node->leftChild);
	int right= balance(Node->rightChild);;
	Node->balance =(right > left ? right : left) + 1;
}

void AVLTree::balancingTree(AVLnode*& Node)
{
	correctingNodeBalance(Node);
	if (Node->balance >= 2)
	{
		if (balanceDifference(Node) >= 2)
		{
			if (balanceDifference(Node->rightChild) < 0)
				Node->rightChild = singleRightRotate(Node->rightChild);
			Node = singleLeftRotate(Node);
		}
		if (balanceDifference(Node) <= -2)
		{
			if (balanceDifference(Node->leftChild) > 0)
				Node->leftChild = singleLeftRotate(Node->leftChild);
			Node=singleRightRotate(Node);
		}
	}
}

AVLnode* AVLTree::insert(int data, AVLnode*& Node)
{
	if (Node == nullptr)
	{
		Node = new AVLnode;
		Node->Inf = data;
		Node->balance = 0;
		Node->leftChild = nullptr;
		Node->rightChild = nullptr;
	}
	else
	{
		if (data < Node->Inf)
			insert(data, Node->leftChild);	// ��������� � ����� ���������
		else
			insert(data, Node->rightChild);		// ��������� � ������ ���������
	}
	balancingTree(Node);
	return Node;
}

AVLnode* AVLTree::singleLeftRotate(AVLnode*& Node) // ��������� ����� �������
{
		AVLnode* item = Node->rightChild;
		Node->rightChild = item->leftChild;
		item->leftChild = Node;
		correctingNodeBalance(Node);
		correctingNodeBalance(item);
		return item;
}

AVLnode* AVLTree::singleRightRotate(AVLnode*& Node) // ��������� ������ �������
{
		AVLnode* item = Node->leftChild;
		Node->leftChild = item->rightChild;
		item->rightChild = Node;
		correctingNodeBalance(Node);
		correctingNodeBalance(item);
		return item;
}

AVLnode* AVLTree::findMin(AVLnode*& Node) // ������� ������ �������� ���-������ � ����������� ��������� ������
{
	if (Node == nullptr)
		return nullptr;
	else
	{
		if (Node->leftChild == nullptr)
			return Node;
		else
			return findMin(Node->leftChild);
	}
}

AVLnode* AVLTree::findMax(AVLnode*& Node) // ������� ������ �������� ���-������ � ������������ ��������� ������
{
	if (Node == nullptr)
		return nullptr;
	else
	{
		if (Node->rightChild == nullptr)
			return Node;
		else
			return findMin(Node->rightChild);
	}
}

AVLnode* AVLTree::findForData(int data, AVLnode*& Node) // ������� ������ �������� ���-������ �� �������� ������
{
	if (Node == nullptr)
	{
		cout << endl << "Error.This value is not contained in our tree";
		return Node;
	}
	else if (Node->Inf == data)
		return Node;
	else if (data < Node->Inf)
		return findForData(data, Node->leftChild);
	else
		return findForData(data, Node->rightChild);
}
AVLnode* AVLTree::deleteTreeElement(int data, AVLnode*& Node)
{
	AVLnode* minItem;
	if (Node == nullptr)	//	�� ����� ������ �������
	{
		cout << endl << "Error. This value is not contained in our tree";
		return nullptr;
	}

	//	�������� ����� ��������
	else if (data < Node->Inf)
		Node->leftChild = deleteTreeElement(data, Node->leftChild);
	else if (data > Node->Inf)
		Node->rightChild = deleteTreeElement(data, Node->rightChild);

	// ������� ��� ������

	else 
	{
		if (Node->leftChild && Node->rightChild)	// ����� ���� ��������
		{
			minItem = findMin(Node->rightChild);
			Node->Inf = minItem->Inf;
			Node->rightChild = deleteTreeElement(Node->Inf, Node->rightChild);
			balancingTree(Node);
			return Node;
		}
		else	// ����� ������ ��� ���� ��������
		{
			minItem = Node;
			if (Node->leftChild == nullptr)
				Node = Node->rightChild;
			else if (Node->rightChild == nullptr)
				Node = Node->leftChild;
			delete minItem;
		}
		if (Node == nullptr)
			return Node;
		balancingTree(Node);
		return Node;
	}
	balancingTree(Node);
	return Node;
}

void AVLTree::insert(int data)
{
	ourTree = insert(data, ourTree);
	balancingTree(ourTree);
}

void AVLTree::deleteTreeElement(int data)
{
	ourTree = deleteTreeElement(data, ourTree);
}

void AVLTree::deleteTree(AVLnode*& Node)		// ������� ������������� ������ ������
{
	if (Node->leftChild)
		deleteTree(Node->leftChild);
	if (Node->rightChild)
		deleteTree(Node->rightChild);
	delete Node;
}

void AVLTree::balanceChangingTree(AVLnode*& Node)		// ������� ������������� ������ ������
{
	if (Node->leftChild)
		balanceChangingTree(Node->leftChild);
	if (Node->rightChild)
		balanceChangingTree(Node->rightChild);
	correctingNodeBalance(Node->rightChild);;
}

void AVLTree::straightPassing()
{
	List OurList = List();
	Stack OurStack;
	AVLnode* buffer;
	box* listBeggining = OurStack.push(OurList);
	listBeggining->FirstInf = ourTree;
	while (OurStack.isNotEmpty(OurList))
	{
		listBeggining = OurList.addressGetter();
		buffer = listBeggining->FirstInf;
		cout << buffer->Inf << '\t';
		OurStack.pop(OurList);
		if (buffer->rightChild!=nullptr)
		{
			listBeggining = OurStack.push(OurList);
			listBeggining->FirstInf = buffer->rightChild;
		}
		if (buffer->leftChild != nullptr)
		{
			listBeggining = OurStack.push(OurList);
			listBeggining->FirstInf = buffer->leftChild;
		}
	}
}

void AVLTree::centralPassing(AVLnode*& Node)
{
	if (Node != nullptr)
	{
		centralPassing(Node->leftChild);               //����������� ������� ��� ������ ������ ���������
		cout << Node->Inf << '\t';
		centralPassing(Node->rightChild);               //����������� ������ ��� ������ ������� ���������
	}
}

void AVLTree::reversePassing(AVLnode*& Node)
{
	if (Node != nullptr)
	{
		reversePassing(Node->leftChild);               //����������� ������� ��� ������ ������ ���������
		reversePassing(Node->rightChild);               //����������� ������ ��� ������ ������� ���������
		cout << Node->Inf << '\t';
	}
}

void AVLTree::widePassing()
{
	Queue ourQueue = Queue(15);
	AVLnode* buffer;
	ourQueue.push(ourTree);
	while (ourQueue.isNotEmpty())
	{
		buffer = ourQueue.peak();
		cout << buffer->Inf << '\t';
		ourQueue.pop();
		if (buffer->leftChild != nullptr)
			ourQueue.push(buffer->leftChild);
		if (buffer->rightChild != nullptr)
			ourQueue.push(buffer->rightChild);
	}
}

void AVLTree::centralPassing()
{
	centralPassing(ourTree);
}
void AVLTree::reversePassing()
{
	reversePassing(ourTree);
}