#include <iostream>
#include<string>
#include "Tree.h"
int main()
{
    setlocale(LC_ALL, "Russian");
    std::string str;
    std::cout << "������� ��� ���������� �����: ";
    std::getline(std::cin, str);
    BinTree binTree;
    if (binTree.parcing(str) == -1)
    {
        system("pause");
        return -1;
    }
    int c = 0;
    std::cout << std::endl;
    std::cout << "������� ��������� ������:" << "\n" << std::endl;
    binTree.traversal();
    std::cout << std::endl;
    AVLTree avlTree;
    avlTree.make(binTree);
    
    while (true)
    {
        std::cout << std::endl;
        std::cout << "�������� ��������: 1 - ������� ������ ����� �����; 2 - ����� �������; 3 - �������� �������; 4 - ������� ������� ";
        std::cin >> c;
        if (c == 1)
        {
            std::cout << "�������� �����: 1 - ������; 2 - ��������������; 3 - ��������; 4 - � ������: ";
            std::cin >> c;
            if ((c == 1) || (c == 2) || (c == 3) || (c == 4))
            {
                std::cout << std::endl;
                avlTree.traversal(c);
            }
            else
            {
                std::cout << "������! �������� ���������� �����." << std::endl;
            }
        }
        else if (c == 2)
        {
            std::cout << "������� ������� �������: ";
            std::cin >> c;
            std::cout << std::endl;
            avlTree.find(c);
        }
        else if (c == 3)
        {
            std::cout << "������� ����������� �������: ";
            std::cin >> c;
            avlTree.insert(c);
        }
        else if (c == 4)
        {
            std::cout << "������� ��������� �������: ";
            std::cin >> c;
            avlTree.remove(c);
        }
        else
        {
            std::cout << "������! �������� ���������� �����." << std::endl;
        }
    }
    return 0;
}
