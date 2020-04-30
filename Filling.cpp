#include "Filling.h" 
#include "Common_Vector.h" // P, M, N, доступ до 3D-масиву та масиву-вектора
#include <cstdlib> // для функції rand()
void FillArrRandom() // Функція для заповнення трьохвимірного масиву псевдо-випадковими числами
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

void FillArrOrdered() // Функція для заповнення трьохвимірного масиву числами, що впорядковані за зростанням
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

void FillArrBackOrdered() // Функція для заповнення трьохвимірного масиву, що впорядковані за спаданням
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
void FillVecOrdered() // Функція для заповнення вектора числами за зростанням
{
	for (int i = 0; i < M * N; i++) {
		Vector[i] = i;
	}
	return;
}

void FillVecRandom() // Функція для заповнення вектора випадковими числами 
{
	for (int i = 0; i < M * N; i++) {
		Vector[i] = rand() % M * N;
	}
	return;
}

void FillVecBackOrdered() // Функція для заповнення вектора числами за спаданням
{
	int number = M * N;
	for (int i = 0; i < M*N; i++) {
		Vector[i] = number--;
	}
	return;
}