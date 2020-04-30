#include "Common_Vector.h"
 #include <cstdlib> // ��� ������� malloc(), free()

int *Vector; // ���������� ���������� ������-�������
int ***Arr3D; // ���������� ���������� ������������� ������
const int P = 1, M = 5, N = 5;
void Arr() // ������� ��� �������� ���'�� ��� ������������� ������ 
{
	Arr3D = (int***)malloc(P * sizeof(int**));
	for (int k = 0; k < P; k++) {
		Arr3D[k] = (int**)malloc(M * sizeof(int*));
		for (int i = 0; i < M; i++)
			Arr3D[k][i] = (int*)malloc(N * sizeof(int));
	}
}
void FreeArr() // ������� ��� ��������� ���'��, �� ����������������� ��� ������������� ������ 
{
	for (int k = 0; k < P; k++) {
		for (int i = 0; i < M; i++) {
			free(Arr3D[k][i]);
		}
		free(Arr3D[k]);
	}
	free(Arr3D);
}

void Vec() // ������� ��� �������� ���'�� ��� ������-�������
{
	Vector = (int*)malloc(M* N * sizeof(int));
}
void FreeVec() // ������� ��� ��������� ���'��, �� ����������������� ��� ������-������� 
{
	free(Vector);
}
