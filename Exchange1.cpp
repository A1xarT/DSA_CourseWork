#include "Exchange1.h" 
#include "Filling.h" // ��� ������� �� ������� ���������� ������
#include "Common_Vector.h" // P, M, N, ������ �� ������
#include <stdio.h>
clock_t Exchange1()
{
	int tmp; // ����� ��� ����� �������� ������ 
	clock_t time_start, time_stop;
	time_start = clock();
	for (int k = 0; k < P; k++) // ����������� �� �������� ������
	{
		for (int R1 = M - 1, R2 = N - 1; ((R1 > 0) || (R2 > 0));)// ������� ���� ������, ���� � ��������� ������ ������� 
		{														 // �������(�����) ��� ����������� �������� �����
			for (int j = 0; j < R2; j++)		// ����������� �� �� �� ������������� ����������, ���� ����������
			{
				for (int i = 0; i < M-1; i++) // ����������� �� ������    
				{
					if (Arr3D[k][i][j] > Arr3D[k][i+1][j])
					{
						tmp = Arr3D[k][i][j];
						Arr3D[k][i][j] = Arr3D[k][i + 1][j];
						Arr3D[k][i + 1][j] = tmp;
					}
				}
				if (Arr3D[k][M - 1][j] > Arr3D[k][0][j + 1]) // ��������� ��������� �������� �������� j-�� ���������
				{											 // � ������ ��������� j+1-�� ���������
					tmp = Arr3D[k][M-1][j];
					Arr3D[k][M-1][j] = Arr3D[k][0][j+1];
					Arr3D[k][0][j+1] = tmp;
				}
			}
			for (int i = 0; i < R1; i++)	// ����������� �� ������ ���������� ���������������� ��������
			{
				if (Arr3D[k][i][R2] > Arr3D[k][i + 1][R2])
				{
					tmp = Arr3D[k][i][R2];
					Arr3D[k][i][R2] = Arr3D[k][i + 1][R2];
					Arr3D[k][i + 1][R2] = tmp;
				}
			}
			R1 = R1 - 1; // ���� ������� ����� ������� ��� �����������
			if (R1 == -1) { R1 = M - 1; R2 = R2 - 1; } // ���� ���������� M-1 ����������� ���������� �����, ����� �� ��������     
		}											   // ������������� �������� � ����� �������, �������� ������ ���� 
	}												   // ����������� �� �������� �� ��������� ���� �� ������ �� M-1 
	time_stop = clock();
	return time_stop - time_start;
}clock_t Exchange1Vect(){	int tmp; 
	clock_t time_start, time_stop;
	time_start = clock();	for (int R = M * N - 1; R > 0; R--) // ������ ���� ����������� ����������� �����
	{
		for (int i = 0; i < R; i++) // ����������� �� �������������� ��������� ������
		{
			if (Vector[i] > Vector[i + 1])
			{
				tmp = Vector[i];
				Vector[i] = Vector[i + 1];
				Vector[i + 1] = tmp;
			}
		}
	}
	time_stop = clock();
	return time_stop - time_start;}void Exchange1MeasOrdered() // �������, ��� ����� ������������� ����� measurements_number ���� �� ������ ���������� ����� ���� � Res[i]
{  
	for (int i = 0; i < measurements_number; i++) {
		FillArrOrdered();
		Res[i] = Exchange1();
	}
	return;
}
void Exchange1MeasRandom() // �������, ��� ����� �����, ���������� ����������� ������� measurements_number ���� 
{																		// �� ������ ���������� ����� ���� � Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillArrRandom();
		Res[i] = Exchange1();
	}
	return;
}
void Exchange1MeasBackOrdered() // �������, ��� ����� �������� ������������� ����� measurements_number ���� 
{																		// �� ������ ���������� ����� ���� � Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillArrBackOrdered();
		Res[i] = Exchange1();
	}
	return;
}
void Exchange1MeasOrderedVect() // �������, ��� ����� ������������ ���������� �����-������ measurements_number ���� 
{																		// �� ������ ���������� ����� ���� � Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillVecOrdered();
		Res[i] = Exchange1Vect();
	}
	return;
}

void Exchange1MeasRandomVect() // �������, ��� ����� ��������� ���������� �����-������ measurements_number ���� 
{																		// �� ������ ���������� ����� ���� � Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillVecRandom();
		Res[i] = Exchange1Vect();
	}
	return;
}

void Exchange1MeasBackOrderedVect() // �������, ��� ����� �������� ������������� ����� measurements_number ����																			
{																		// �� ������ ���������� ����� ���� � Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillVecBackOrdered();
		Res[i] = Exchange1Vect();
	}
	return;
}
