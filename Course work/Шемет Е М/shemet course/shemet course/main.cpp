#include <iostream>
#include "Kruskal.h"

int main()
{
    setlocale(LC_ALL, "Russian");
  //  system("chcp 1251");
    Graph graph;
    std::string str;
    std::cout << "������� ��� ����� � �������� ���������: ";
    std::getline(std::cin, str);
    graph.read(str);
    std::cout << "\n";
    std::cout << "����� ����� � �������: ";
    graph.DFS();
    std::cout << std::endl << "\n";
    std::cout << "����� ����� � ������: ";
    graph.BFS();
    std::cout << "\n" << "����������� �������� ������ �� ��������� ��������:" << std::endl;
    graph.algorithmKruskal();
    std::cout << "\n";
    std::cout << "����� MST � �������: ";
    graph.DFS();
    system("pause");
    return 0;
}