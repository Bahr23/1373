﻿#include<iostream>
#include"BinaryTree.h"
#include "List.h"

template<typename T>
Node<T>* RBTree<T>::insert(T value)
{
	//root creation
	if (root == nullptr) {
		root = new Node<T>(value, nullptr);
		root->isRed = false;
		return root;
	}
	Node<T>* cur = insertVal(value, root, root->parent, true);
	forwardRedCheck();
	return cur;
}

template<typename T>
Node<T>* RBTree<T>::find(T value)
{
	clearVisits();
	return find(value, root);
}

template<typename T>
void RBTree<T>::deleteItem(T value)
{
	root->isRed = false;
	Node<T>* node = find(value);
	if (node->left == nullptr && node->right == nullptr)//1. Нет потомков
	{
		if (node->isRed == true)///
		{
			if (node->parent->left == node) {
				node->parent->left = nullptr;
			}
			else {
				node->parent->right = nullptr;
			}
			delete node;
			return;
		}
		else
		{
			balanceZeroBlack(node);
			return;
		}
	}
	if ((node->left != nullptr && node->right == nullptr) || (node->left == nullptr && node->right != nullptr))//2. 1 Потомок///
	{
		Node<T>* child = (node->left != nullptr) ? node->left : node->right;
		if (node->parent->left == node)
			node->parent->left = child;
		else
			node->parent->right = child;
		child->parent = node->parent;
		if (child->parent->isRed == true)
			child->isRed = false;
		delete node;
		return;
	}
	if (node->left != nullptr && node->right != nullptr)//
	{
		Node<T>* current;
		current = node->right;
		while (current->left != nullptr)
		{
			current = current->left;
		}
		T buffer = current->data;
		deleteItem(current->data);
		node->data = buffer;
		return;
	}
}

template<typename T>
RBTree<T>::RBTree()
{
	root = nullptr;
}

template<typename T>
RBTree<T>::~RBTree()
{
	clean(root);
}

template<typename T>
void RBTree<T>::rightRotate(Node<T>* node)
{
	Node<T>* nodeChild = node->right;
	Node<T>* fatherParent = node->parent->parent;
	if (fatherParent != nullptr) {
		bool isRightParent = (fatherParent->right == node->parent) ? true : false;
		if (isRightParent)
			fatherParent->right = node;
		else
			fatherParent->left = node;
	}
	else
		root = node;
	node->right = node->parent;
	node->right->parent = node;
	node->parent = fatherParent;
	node->right->left = nodeChild;
	if (nodeChild != nullptr)
	{
		nodeChild->parent = node->right;
	}
}

template<typename T>
void RBTree<T>::leftRotate(Node<T>* node)
{
	Node<T>* nodeChild = node->left;//
	Node<T>* fatherParent = node->parent->parent;
	if (fatherParent != nullptr) {
		bool isRightParent = (fatherParent->left == node->parent) ? true : false;//
		if (isRightParent)
			fatherParent->left = node;//
		else
			fatherParent->right = node;
	}
	else
		root = node;
	node->left = node->parent;//
	node->left->parent = node;
	node->parent = fatherParent;
	node->left->right = nodeChild;//
	if (nodeChild != nullptr)
	{
		nodeChild->parent = node->left;
	}
}

template<typename T>
Node<T>* RBTree<T>::getRoot()
{
	return root;
}

template<typename T>
void RBTree<T>::print(Node<T>* main, int level)
{
	if (main != nullptr && main->isEmpty == false)
	{
		print(main->right, level + 1);
		for (int i = 0; i < level; i++)
			cout << "   ";
		cout << main->data <<" "<<main->isRed<< endl; 
		print(main->left, level + 1);
	}
}

template<typename T>
void RBTree<T>::clearVisits()
{
	clearVisits(root);
}

template<typename T>
void RBTree<T>::transformation(Node<T>* btRoot)
{
	if (btRoot == nullptr)
	{
		std::cout << "Ошибка: корень двоичного дерева равен null" << std::endl;
		return;
	}
	insertElemFromBT(btRoot);
}

template<typename T>
void RBTree<T>::reverse()
{
	clearVisits();
	reverse(root);
}

template<typename T>
void RBTree<T>::forward()
{
	clearVisits();
	forward(root);
}

template<typename T>
void RBTree<T>::central()
{
	clearVisits();
	central(root);
}

template<typename T>
void RBTree<T>::print()
{
	print(root, 0);
}

template<typename T>
void RBTree<T>::inWidth()
{
	ArrayList<Node<T>*> list = ArrayList<Node<T>*>(20);
	list.add(root);
	while (list.size() != 0)
	{
		cout << list[0]->data << " ";
		Node<T>* node = list[0];
		list.deleteItem(0);
		if (node->left != nullptr)
			list.add(node->left);
		if (node->right != nullptr)
			list.add(node->right);
	}
}

template<typename T>
void RBTree<T>::clearVisits(Node<T>* main)
{
	if (main == nullptr)
		return;
	main->isVisited = false;
	if (main->left != nullptr && main->left->isEmpty == false && main->left->isVisited == true)
		clearVisits(main->left);
	else
	{
		if (main->right != nullptr && main->right->isEmpty == false && main->right->isVisited == true)
			clearVisits(main->right);
		else
			clearVisits(main->parent);
	}
}

template<typename T>
void RBTree<T>::reverse(Node<T>* main)
{
	if (main == nullptr)
		return;
	if (main->left != nullptr && main->left->isEmpty == false && main->left->isVisited == false)
		reverse(main->left);
	else
	{
		if (main->right != nullptr && main->right->isEmpty == false && main->right->isVisited == false)
		{
			reverse(main->right);
		}
		else
		{
			main->isVisited = true;
			cout << main->data << " ";
			reverse(main->parent);
		}
	}
}


template<typename T>
void RBTree<T>::central(Node<T>* main)
{
	if (main == nullptr)
		return;
	if (main->isVisited == true && main->isPrinted == false)
	{
		main->isPrinted = true;
		cout << main->data << " ";
	}
	main->isVisited = true;
	if (main->left != nullptr && main->left->isEmpty == false && main->left->isVisited == false)
		central(main->left);
	else
	{
		if (main->right != nullptr && main->right->isEmpty == false && main->right->isVisited == false)
			central(main->right);
		else {
			if (main->isPrinted == false)
			{
				main->isPrinted = true;
				cout << main->data << " ";
			}
			central(main->parent);
		}
	}
}

template<typename T>
void RBTree<T>::forward(Node<T>* main)
{
	if (main == nullptr)
		return;
	if (main->isVisited == false)
	{
		cout << main->data << " ";
	}
	main->isVisited = true;
	if (main->left != nullptr && main->left->isEmpty == false && main->left->isVisited == false)
		forward(main->left);
	else
	{
		if (main->right != nullptr && main->right->isEmpty == false && main->right->isVisited == false)
			forward(main->right);
		else
			forward(main->parent);
	}
}


template<typename T>
Node<T>* RBTree<T>::find(T value, Node<T>* main)
{
	Node<T>* cur = main;
	if (cur->data == value)
		return cur;
	if (cur->data > value)
		find(value, cur->left);
	else
		find(value, cur->right);
	if (cur == nullptr)
		return nullptr;
}

template<typename T>
Node<T>* RBTree<T>::insertVal(T val, Node<T>* main, Node<T>* parent, bool isLeftMode)
{
	if (main == nullptr)
	{
		if (isLeftMode == true)
		{
			main = new Node<T>(val, parent);
			main->left = nullptr;
			main->right = nullptr;
			parent->left = main;
			return main;
		}
		else
		{
			main = new Node<T>(val, parent);
			main->left = nullptr;
			main->right = nullptr;
			parent->right = main;
			return main;
		}
	}
	if (val <= main->data)
		insertVal(val, main->left, main, true);
	else
		insertVal(val, main->right, main, false);
}

template<typename T>
void RBTree<T>::insertElemFromBT(Node<T>* main)
{
	if (main == nullptr || main->isEmpty == true)
	{
		return;
	}
	insert(main->data);
	insertElemFromBT(main->left);
	insertElemFromBT(main->right);
}

template<typename T>
void RBTree<T>::balance(Node<T>* inserted)
{
	if (inserted->parent->isRed == false)
		return;
	else
	{
		if (inserted->parent->isRed == true)
		{
			bool isLeftChild;
			Node<T>* uncle;
			if (inserted->parent->parent->left == inserted->parent)
			{
				uncle = inserted->parent->parent->right;
				isLeftChild = true;
			}
			else
			{
				uncle = inserted->parent->parent->left;//дядя
				isLeftChild = false;
			}
			if (uncle != nullptr && uncle->isRed == true)//1й случай
			{
				uncle->isRed = false;
				inserted->parent->isRed = false;
				uncle->parent->isRed = true;
				root->isRed = false;
			}
			else//второй случай
			{
				if (isLeftChild == true && (inserted->parent->left == inserted ? true : false))//1. Если у нас вставка левого и родитель является левым
				{
					rightRotate(inserted->parent);
					inserted->parent->right->isRed = true;
					inserted->parent->isRed = false;
				}
				if (isLeftChild == false && (inserted->parent->right == inserted ? true : false))//2. Если у нас вставка правого и родитель правый
				{
					leftRotate(inserted->parent);
					inserted->parent->left->isRed = true;
					inserted->parent->isRed = false;
				}
				if (isLeftChild == true && (inserted->parent->right == inserted ? true : false))//3. Если у нас вставка правого и родитель левый
				{
					leftRotate(inserted);
					rightRotate(inserted);
					inserted->isRed = false;
					inserted->right->isRed = true;
				}
				if (isLeftChild == false && (inserted->parent->left == inserted ? true : false))//4. Если у нас вставка левого и родитель правый
				{
					rightRotate(inserted);
					leftRotate(inserted);
					inserted->isRed = false;
					inserted->left->isRed = true;
				}
			}
		}
	}
}

template<typename T>
void RBTree<T>::balanceZeroBlack(Node<T>* node)
{

	Node<T>* brother = (node->parent->left != node) ? node->parent->left : node->parent->right;
	if (brother == nullptr)
	{
		return;
	}
	bool isBrotherLeft = (node->parent->left != node) ? true : false;
	if (!isBrotherLeft)
	{
		if (brother->isRed == false)
		{
			if ((brother->left == nullptr || brother->left->isRed == false) && (brother->right == nullptr || brother->right->isRed == false))
			{
				if (brother->parent->isRed == false)
				{
					brother->parent->isRed = false;
					brother->isRed = true;
					balanceZeroBlack(brother->parent);
					return;
				}
				if (brother->parent->isRed == true)
				{
					brother->parent->isRed = false;
						brother->isRed = true;
						return;
				}
			}
			if (brother->right != nullptr)
			{
				if (brother->right->isRed == true)
				{
					brother->right->isRed = false;
					bool color = brother->parent->isRed;
					brother->parent->isRed = brother->isRed;
					brother->isRed = color;
					leftRotate(brother);

				}
			}
			if (brother->left != nullptr && brother->left->isRed == true && (brother->right == nullptr || brother->right->isRed == false))
			{
				rightRotate(brother->left);
				brother->right->isRed = false;
				bool color = brother->parent->isRed;
				brother->parent->isRed = brother->isRed;
				brother->isRed = color;
				leftRotate(brother);
			}
		}
		else
		{
			if ((brother->left == nullptr || brother->left->isRed == false) && (brother->right == nullptr || brother->right->isRed == false))
			{
				bool color = brother->parent->isRed;
				brother->parent->isRed = brother->isRed;
				brother->isRed = color;
				leftRotate(brother);
			}
		}
	}
	else
	{
		if (brother->isRed == false)
		{
			if ((brother->right == nullptr || brother->right->isRed == false) && (brother->left == nullptr || brother->left->isRed == false))
			{
				if (brother->parent->isRed == false)
				{
					brother->parent->isRed = false;
					brother->isRed = true;
					balanceZeroBlack(brother->parent);
					return;
				}
				if (brother->parent->isRed == true)
				{
					brother->parent->isRed = false;
						brother->isRed = true;
						return;
				}
			}
			if (brother->left != nullptr)
			{
				if (brother->left->isRed == true)
				{
					brother->left->isRed = false;
					bool color = brother->parent->isRed;
					brother->parent->isRed = brother->isRed;
					brother->isRed = color;
					rightRotate(brother);

				}
			}
			if (brother->right != nullptr && brother->right->isRed == true && (brother->left == nullptr || brother->left->isRed == false))
			{
				leftRotate(brother->right);
				brother->left->isRed = false;
				bool color = brother->parent->isRed;
				brother->parent->isRed = brother->isRed;
				brother->isRed = color;
				rightRotate(brother);
			}
		}
		else
		{
			if ((brother->right == nullptr || brother->right->isRed == false) && (brother->left == nullptr || brother->left->isRed == false))
			{
				bool color = brother->parent->isRed;
				brother->parent->isRed = brother->isRed;
				brother->isRed = color;
				rightRotate(brother);
			}
		}

	}
}

template<typename T>
void RBTree<T>::clean(Node<T>* main)
{
	if (main == nullptr)
		return;
	if (main->left != nullptr && main->left->isEmpty == false && main->left->isVisited == false)
		clean(main->left);
	else
	{
		if (main->right != nullptr && main->right->isEmpty == false && main->right->isVisited == false)
		{
			clean(main->right);
		}
		else
		{
			main->isVisited = true;
			Node<T>* parent = main->parent;
			delete main;
			clean(parent);
		}
	}
}

template<typename T>
void RBTree<T>::forwardRedCheck()
{
	clearVisits();
	forwardRedCheck(root);
}

template<typename T>
Node<T>* RBTree<T>::forwardRedCheck(Node<T>* main)
{
	if (main == nullptr)
		return nullptr;
	if (main->isRed == true && main->parent->isRed == true)
	{
		balance(main);
	}
	main->isVisited = true;
	if (main->left != nullptr && main->left->isEmpty == false && main->left->isVisited == false)
		forwardRedCheck(main->left);
	else
	{
		if (main->right != nullptr && main->right->isEmpty == false && main->right->isVisited == false)
			forwardRedCheck(main->right);
		else
			forwardRedCheck(main->parent);
	}
}
