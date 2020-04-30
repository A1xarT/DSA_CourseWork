#define _CRT_SECURE_NO_WARNINGS
#include "Printing.h" 
#include "Filling.h" // ���������� ������������� ������ �� ������-�������
#include "Select4.h" // ������� ��� 
#include "Select6.h" // ���������� ����
#include "Exchange1.h" // ������ ��������� ����������
#include "Common_Vector.h" // P, M, N, Arr(), Vec(), FreeArr(), FreeVec()
#include <stdio.h> // ��� printf
#include <Windows.h> // ��� system("cls");
float s;
void PrintSelect4() // ������� ��� ��������� �� ����� ������������� ������ �� ������ ��������� ����������,  
{					// ������������ ������ �������� Select4 �� ����� ���� ���������� ������� �� ������� ����������
	Arr();
	system("cls");
	printf("\n       ====Ordered====\n");
	FillArrOrdered();
	out();
	Select4MeasOrdered();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select4====\n");
	out();
	printf("\n Taken time: %f\n\n", s);
	printf("\n       ====Random====\n");
	FillArrRandom();
	out();
	Select4MeasRandom();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select4====\n");
	out();
	printf("\n Taken time: %f\n\n", s);
	printf("\n       ====Back Ordered====\n");
	FillArrBackOrdered();
	out();
	Select4MeasBackOrdered();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select4====\n");
	out();
	printf("\n Taken time: %f\n\n", s);
	printf("\n Input 0 to return to menu");
	int c = 1;
	while (c != 0)
	{
		scanf("%d", &c);
	}
	FreeArr();
}
void PrintSelect6() // ������� ��� ��������� �� ����� ������������� ������ �� ������ ��������� ����������,  
{					// ������������ ������ �������� Select6 �� ����� ���� ���������� ������� �� ������� ����������
	Arr();
	system("cls");
	printf("\n       ====Ordered====\n");
	FillArrOrdered();
	out();
	Select6MeasOrdered();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select6====\n");
	out();
	printf("\n Taken time: %f\n\n", s);
	printf("\n       ====Random====\n");
	FillArrRandom();
	out();
	Select6MeasRandom();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select6====\n");
	out();
	printf("\n Taken time: %f\n\n", s);;
	printf("\n       ====BackOordered====\n");
	FillArrBackOrdered();
	out();
	Select6MeasBackOrdered();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select6====\n");
	out();
	printf("\n Taken time: %f\n\n", s);
	printf("\n Input 0 to return to menu");
	int c = 1;
	while (c != 0)
	{
		scanf("%d", &c);
	}
	FreeArr();
}
void PrintExchange1() // ������� ��� ��������� �� ����� ������������� ������ �� ������ ��������� ����������,
{					  // ������������ ������ �������� Exchange1 �� ����� ���� ���������� ������� �� ������� ����������
	Arr();
	system("cls");
	printf("\n       ====Ordered====\n");
	FillArrOrdered();
	out();
	Exchange1MeasOrdered();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Exchange1====\n");
	out();
	printf("\n Taken time: %f\n\n", s);
	printf("\n       ====Random====\n");
	FillArrRandom();
	out();
	Exchange1MeasRandom();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Exchange1====\n");
	out();
	printf("\n Taken time : %f\n\n", s);
	printf("\n       ====BackOrdered====\n");
	FillArrBackOrdered();
	out();
	Exchange1MeasBackOrdered();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Exchange1====\n");
	out();
	printf("\n Taken time : %f\n\n", s);
	printf("\nInput 0 to return to menu");
	int c = 1;
	while (c != 0)
	{
		scanf("%d", &c);
	}
	FreeArr();
}
void PrintSelect4Vect() // ������� ��� ��������� �� ����� ������-������� �� ������ ��������� ����������,
{						// ������������ ������ �������� Select4Vect �� ����� ���� ���������� ������� �� ������� ����������
	Vec();
	system("cls");
	printf("\n       ====Ordered====\n");
	FillVecOrdered();
	outVect();
	Select4MeasOrderedVect();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select4====\n");
	outVect();
	printf("\n Taken time: %f\n\n", P * s);
	printf("\n       ====Random====\n");
	FillVecRandom();
	outVect();
	Select4MeasRandomVect();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select4====\n");
	outVect();
	printf("\n Taken time: %f\n\n", P * s);
	printf("\n       ====Back Ordered====\n");
	FillVecBackOrdered();
	outVect();
	Select4MeasBackOrderedVect();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select4====\n");
	outVect();
	printf("\n Taken time: %f\n\n", P * s);
	printf("\nInput 0 to return to menu");
	int c = 1;
	while (c != 0)
	{
		scanf("%d", &c);
	}
	FreeVec();
}
void PrintSelect6Vect() // ������� ��� ��������� �� ����� ������-������� �� ������ ��������� ����������,
{						// ������������ ������ �������� Select6Vect �� ����� ���� ���������� ������� �� ������� ����������
	Vec();
	system("cls");
	printf("\n       ====Ordered====\n");
	FillVecOrdered();
	outVect();
	Select6MeasOrderedVect();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select6====\n");
	outVect();
	printf("\n Taken time: %f\n\n", P * s);
	printf("\n       ====Random====\n");
	FillVecRandom();
	outVect();
	Select6MeasRandomVect();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select6====\n");
	outVect();
	printf("\n Taken time: %f\n\n", P * s);
	printf("\n       ====Back Ordered====\n");
	FillVecBackOrdered();
	outVect();
	Select6MeasBackOrderedVect();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Select6====\n");
	outVect();
	printf("\n Taken time: %f\n\n", P * s);
	printf("\nInput 0 to return to menu");
	int c = 1;
	while (c != 0)
	{
		scanf("%d", &c);
	}
	FreeVec();
}
void PrintExchange1Vect() // ������� ��� ��������� �� ����� ������-������� �� ������ ��������� ����������,
{						  // ������������ ������ �������� Exchange1Vect �� ����� ���� ���������� ������� �� ������� ����������
	Vec();
	system("cls");
	printf("\n       ====Ordered====\n");
	FillVecOrdered();
	outVect();
	Exchange1MeasOrderedVect();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Exchange1====\n");
	outVect();
	printf("\n Taken time: %f\n\n", P * s);
	printf("\n       ====Random====\n");
	FillVecRandom();
	outVect();
	Exchange1MeasRandomVect();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Exchange1====\n");
	outVect();
	printf("\n Taken time: %f\n\n", P * s);
	printf("\n       ====Back Ordered====\n");
	FillVecBackOrdered();
	outVect();
	Exchange1MeasBackOrderedVect();
	s = MeasurementProcessing();
	printf("\n       ====Sorted by Exchange1====\n");
	outVect();
	printf("\n Taken time: %f\n\n", P * s);
	printf("\nInput 0 to return to menu");
	int c = 1;
	while (c != 0)
	{
		scanf("%d", &c);
	}
	FreeVec();
}
void out() // ������� ��� ��������� ������������� ������ �� �����
{
	for (int k = 0; k < P; k++) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				printf("%d\t", Arr3D[k][i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
	}
	return;
}
void outVect() // ������� ��� ��������� ������-������� �� �����
{
	printf("\n");
	for (int i = 0; i < M*N; i++)
	{
		if (i % 20 == 0) printf("\n");
		printf("%d ", Vector[i]);
	}
}