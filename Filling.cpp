#include "Filling.h" 
#include "Common_Vector.h" // P, M, N, ������ �� 3D-������ �� ������-�������
#include <cstdlib> // ��� ������� rand()
void FillArrRandom() // ������� ��� ���������� ������������� ������ ������-����������� �������
{
	for (int k = 0; k < P; k++) {
		for (int j = 0; j < N; j++) {
			for (int i = 0; i < M; i++) {
				Arr3D[k][i][j] = rand() % (P*M*N);
			}
		}
	}
	return;
}

void FillArrOrdered() // ������� ��� ���������� ������������� ������ �������, �� ����������� �� ����������
{
	int number = 0;
	for (int k = 0; k < P; k++) {
		for (int j = 0; j < N; j++){
			for (int i = 0; i < M; i++){
				Arr3D[k][i][j] = number++;
			}
		}
	}
	return;
}

void FillArrBackOrdered() // ������� ��� ���������� ������������� ������, �� ����������� �� ���������
{
	int number = P * M * N;
	for (int k = 0; k < P; k++) {
		for (int j = 0; j < N; j++){
			for (int i = 0; i < M; i++){
				Arr3D[k][i][j] = number--;
			}
		}
	}
	return;
}
void FillVecOrdered() // ������� ��� ���������� ������� ������� �� ����������
{
	for (int i = 0; i < M * N; i++) {
		Vector[i] = i;
	}
	return;
}

void FillVecRandom() // ������� ��� ���������� ������� ����������� ������� 
{
	for (int i = 0; i < M * N; i++) {
		Vector[i] = rand() % M * N;
	}
	return;
}

void FillVecBackOrdered() // ������� ��� ���������� ������� ������� �� ���������
{
	int number = M * N;
	for (int i = 0; i < M*N; i++) {
		Vector[i] = number--;
	}
	return;
}