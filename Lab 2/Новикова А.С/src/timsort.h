#pragma once
#include "stack.h"

void randomInput(int* arr, int size);
void manualInput(int* arr, int size);
int getMinrun(int size); //���������� minrun-�
void reverse(int* arr, int size);
void merge(int* arr, int left, int mid, int right); //�������
void insertionSort(int* arr, int left, int right); //���������� ���������
void timsort(int* arr, int size); //�������

