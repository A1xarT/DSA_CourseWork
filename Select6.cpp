#include "Select6.h"
#include "Filling.h" // ��� ������������ ������� ���������� ������
#include "Common_Vector.h" // P, M, N, ������ �� ������, 

clock_t Select6()
{
	int imin, jmin, tmp; // imin, jmin - ���� ��� �����'���������� ��������� ���������� �������� ������; tmp - ����� ��� ����� ��������
	clock_t time_start, time_stop;
	time_start = clock();
	for (int k = 0; k < P; k++) // ����������� �� �������� ������
	{
		for (int l = 0; l < N-1; l++) // ���� ��� ����������� �� �������������� ����������, ���� ����������(��� ����� �������� ������� ����)
		{
			for (int s = 0; s < M; s++) // ���� ��� ����������� �� �������������� ������ l-�� ���������
			{
				imin = s; jmin = l; // ������� ��������� ��������� ��������� ����� �������� �� ���������
				for (int i = s + 1; i < M; i++) // ����������� �� ������ ������� ��������������� ���������, ��������� � ����������
				{								// ���� ����, �� ���������� �� ������ ���������
					if (Arr3D[k][i][l] < Arr3D[k][imin][jmin])
					{
						imin = i; jmin = l;
					}
				} 
				for (int j = l + 1; j < N; j++) // ����������� �� ��������� �񳺿 �������, �� �������� ����������� ���� ������������ ����� 
				{								// ����� ��� �������������� ��������� ���� �������(���������������)
					for (int i = 0; i < M; i++) // ����������� �� ������
					{
						if (Arr3D[k][i][j] < Arr3D[k][imin][jmin])
						{
							imin = i; jmin = j;
						}
					}
				}
				if ((imin != s) || (jmin != l))	// ���� ������ ������ ���� ������� �������� �� ���������, ������ ���� ����� �� 
				{																							 // ��������� ���������
					tmp = Arr3D[k][imin][jmin];
					Arr3D[k][imin][jmin] = Arr3D[k][s][l];
					Arr3D[k][s][l] = tmp;
				}
			}
		}
		for (int s = 0; s < M-1; s++) // ���� ��� ����������� �� ��������� ���������� (N-1-�� ��������� �������)
		{
			imin = s; jmin = N-1;
			for (int i = s + 1; i < M; i++)
			{
				if (Arr3D[k][i][N-1] < Arr3D[k][imin][jmin])
				{
					imin = i; jmin = N-1;
				}
			}
			for (int j = N - 1 + 1; j < N; j++)
			{
				for (int i = 0; i < M; i++)
				{
					if (Arr3D[k][i][j] < Arr3D[k][imin][jmin])
					{
						imin = i; jmin = j;
					}
				}
			}
			if ((imin != s) || (jmin != N - 1))
			{
				tmp = Arr3D[k][imin][jmin];
				Arr3D[k][imin][jmin] = Arr3D[k][s][N - 1];
				Arr3D[k][s][N - 1] = tmp;
			}
		}

	}
	time_stop = clock();
	return time_stop - time_start;
}
clock_t Select6Vect()
{
	int imin, tmp; // imin - ������� ���������� ��������, tmp - ����� ��� ����� ��������
	clock_t time_start, time_stop;
	time_start = clock();
	for (int s = 0; s < M*N - 1; s++) // ����������� �� �������������� ���������
	{ 
		imin = s;
		for (int i = s + 1; i < M*N; i++)
			if (Vector[i] < Vector[imin]) imin = i;
		if (imin != s) 
		{
			tmp = Vector[imin];
			Vector[imin] = Vector[s];
			Vector[s] = tmp;
		}
	}
	time_stop = clock();
	return time_stop - time_start;
}

void Select6MeasOrdered()							// ������� ���������� ���� ���������� ������ ��������� ���������� ������������� ������
{													// �� ������-�������, ������� ��������� ���������� � Res[i], �� ��� �������������		
													// �������� MeasurementProcessing() ��� ��������� ���� ������� ����������
	for (int i = 0; i < measurements_number; i++) {
		FillArrOrdered();
		Res[i] = Select6();
	}
	return;
}
void Select6MeasRandom() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillArrRandom();
		Res[i] = Select6();
	}
	return;
}
void Select6MeasBackOrdered() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillArrBackOrdered();
		Res[i] = Select6();
	}
	return;
}
void Select6MeasOrderedVect() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillVecOrdered();
		Res[i] = Select6Vect();
	}
	return;
}

void Select6MeasRandomVect() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillVecRandom();
		Res[i] = Select6Vect();
	}
	return;
}

void Select6MeasBackOrderedVect() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillVecBackOrdered();
		Res[i] = Select6Vect();
	}
	return;
}

