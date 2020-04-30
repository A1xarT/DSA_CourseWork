#include "Select4.h"
#include "Filling.h" // ��� ������� �� ������� ���������� ������
#include "Common_Vector.h" // P, M, N, ������ �� ������


clock_t Select4()
{
	int L1, L2, R1, R2, imin, jmin, imax, jmax, tmp; // L1 - ��� ������� ����������� �� ������; L2 - �� ��������; tmp - ����� ��� ����� ��������
	clock_t time_start, time_stop;					 //	������.	R1 - ����� ������� ����������� �� ������; R2 - �� ��������                          
	time_start = clock();								    // imin, jmin - ���� ��� �����'���������� ��������� ���������� �������� ������
	for (int k = 0; k < P; k++)// ����������� �� �������	// imax, jmax - ���� ��� �����'���������� ��������� ������������� �������� ������
	{												 	
		L1 = 0; L2 = 0; R1 = M-1; R2 = N-1;
		while (L2 < R2) // ���� ��� � ����� ������� �� ���������� �� �����������
		{
			imin = L1; jmin = L2; imax = L1; jmax = L2; // (L1,L2) - �����; (R1,R2) - ��������
			for (int i = L1 + 1, j = L2; i < M; i++) // ����������� �� ������� ��������������� ���������
			{
				if (Arr3D[k][i][j] < Arr3D[k][imin][jmin])
				{
					imin = i; jmin = j;
				}
				else
				{
					if (Arr3D[k][i][j] > Arr3D[k][imax][jmax])
					{
						imax = i; jmax = j;
					}
				}
			}
			for (int j = L2 + 1; j < R2; j++) // ����������� �� �������� ������ ������� (��� ������� �� ���������� ��������������)
			{
				for (int i = 0; i < M; i++)
				{
					if (Arr3D[k][i][j] < Arr3D[k][imin][jmin])
					{
						imin = i; jmin = j;
					}
					else
					{
						if (Arr3D[k][i][j] > Arr3D[k][imax][jmax])
						{
							imax = i; jmax = j;
						}
					}
				}
			}
			for (int i = 0, j = R2; i < R1+1; i++) // ����������� �� ���������� ��������������� ���������
			{
				if (Arr3D[k][i][j] < Arr3D[k][imin][jmin])
				{
					imin = i; jmin = j;
				}
				else
				{
					if (Arr3D[k][i][j] > Arr3D[k][imax][jmax])
					{
						imax = i; jmax = j;
					}
				}
			}
			tmp = Arr3D[k][imin][jmin];
			Arr3D[k][imin][jmin] = Arr3D[k][L1][L2];
			Arr3D[k][L1][L2] = tmp;
			if ((imax == L1) && (jmax == L2))
			{
				tmp = Arr3D[k][imin][jmin];
				Arr3D[k][imin][jmin] = Arr3D[k][R1][R2];
				Arr3D[k][R1][R2] = tmp;
			}
			else
			{
				tmp = Arr3D[k][imax][jmax];
				Arr3D[k][imax][jmax] = Arr3D[k][R1][R2];
				Arr3D[k][R1][R2] = tmp;
			}
			L1 = L1 + 1; R1 = R1 - 1;
			if (L1 == M) { L2 = L2 + 1; L1 = 0; }
			if (R1 == -1) { R2 = R2 - 1; R1 = M - 1; }
		}
		if (L2 == R2) // ���� ��� �� ����� ������� �� ���������� ����������� (� �� �����������, ���� 
		{			  // ������� ��������� � �������� ������), ��� ������� �������� �������� ������ � ����� �� �����
			while (L1 < R1) // ���� �� ������ �� �������� (�������, ��������� ����� �� ������ �� �����)
			{
				imin = L1; jmin = L2; imax = R1; jmax = R2;
				for (int i = L1; i < R1 + 1; i++)
				{
					if (Arr3D[k][i][L2] < Arr3D[k][imin][jmin])
					{
						imin = i; jmin = L2;
					}
					else
					{
						if (Arr3D[k][i][L2] > Arr3D[k][imax][jmax])
						{
							imax = i; jmax = L2;
						}
					}
				}
				tmp = Arr3D[k][imin][jmin];
				Arr3D[k][imin][jmin] = Arr3D[k][L1][L2];
				Arr3D[k][L1][L2] = tmp;
				if ((imax == L1) && (jmax == L2))
				{
					tmp = Arr3D[k][imin][jmin];
					Arr3D[k][imin][jmin] = Arr3D[k][R1][R2];
					Arr3D[k][R1][R2] = tmp;
				}
				else
				{
					tmp = Arr3D[k][imax][jmax];
					Arr3D[k][imax][jmax] = Arr3D[k][R1][R2];
					Arr3D[k][R1][R2] = tmp;
				}
				L1 = L1 + 1; R1 = R1 - 1; // �������� ��� �� ����� ��� �� ������
			}
		}
	}
	time_stop = clock();
	return time_stop - time_start;
}

clock_t Select4Vect()
{
	int L, R, imin, imax, tmp; // L,R - ���, ����� ������� �����������, imin, imax - ���� ��� ��������� ���������� �� ������������� ��������, 
	clock_t time_start, time_stop;									// tmp - ����� ��� ����� ��������
	time_start = clock();
	L = 0; R = M * N - 1;
	while (L < R) // ���� ��� ������� �� ����������� � ������
	{
		imin = L; imax = L; // ��������� ������ �������� �� ����������� ��������� �������� ��� ������� 
		for (int i = L + 1; i < R + 1; i++) // ����� �� ���������, ��� ��� �� ����� ������������ ������
		{
			if (Vector[i] < Vector[imin]) imin = i;
			else
				if (Vector[i] > Vector[imax]) imax = i;
		}
		tmp = Vector[imin];
		Vector[imin] = Vector[L];
		Vector[L] = tmp;
		if (imax == L)
		{
			tmp = Vector[imin];
			Vector[imin] = Vector[R];
			Vector[R] = tmp;
		}
		else
		{
			tmp = Vector[imax];
			Vector[imax] = Vector[R];
			Vector[R] = tmp;
		}
		L = L + 1; R = R - 1;
	}
	time_stop = clock();
	return time_stop - time_start;

}
void Select4MeasOrdered()								// ������� ���������� ���� ���������� ������ ��������� ���������� ������������� ������
{														// �� ������-�������, ������� ��������� ���������� � Res[i], �� ��� �������������
	for (int i = 0; i < measurements_number; i++) {		// �������� MeasurementProcessing() ��� ��������� ���� ������� ����������
		FillArrOrdered();
		Res[i] = Select4();
	}
	return;
}
void Select4MeasRandom() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillArrRandom();
		Res[i] = Select4();
	}
	return;
}
void Select4MeasBackOrdered() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillArrBackOrdered();
		Res[i] = Select4();
	}
	return;
}
void Select4MeasOrderedVect() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillVecOrdered();
		Res[i] = Select4Vect();
	}
	return;
}

void Select4MeasRandomVect() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillVecRandom();
		Res[i] = Select4Vect();
	}
	return;
}

void Select4MeasBackOrderedVect() 
{
	for (int i = 0; i < measurements_number; i++) {
		FillVecBackOrdered();
		Res[i] = Select4Vect();
	}
	return;
}