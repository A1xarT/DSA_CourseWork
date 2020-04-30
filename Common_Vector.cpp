#include "Common_Vector.h"
 #include <cstdlib> // для функцій malloc(), free()

int *Vector; // Оголошення динамічного масиву-вектора
int ***Arr3D; // Оголошення динамічного трьохвимірного масиву
const int P = 1, M = 5, N = 5;
void Arr() // Функція для виділення пам'яті для трьохвимірного масиву 
{
	Arr3D = (int***)malloc(P * sizeof(int**));
	for (int k = 0; k < P; k++) {
		Arr3D[k] = (int**)malloc(M * sizeof(int*));
		for (int i = 0; i < M; i++)
			Arr3D[k][i] = (int*)malloc(N * sizeof(int));
	}
}
void FreeArr() // Функція для звільнення пам'яті, що використовувалась для трьохвимірного масиву 
{
	for (int k = 0; k < P; k++) {
		for (int i = 0; i < M; i++) {
			free(Arr3D[k][i]);
		}
		free(Arr3D[k]);
	}
	free(Arr3D);
}

void Vec() // Функція для виділення пам'яті для масиву-вектора
{
	Vector = (int*)malloc(M* N * sizeof(int));
}
void FreeVec() // Функція для звільнення пам'яті, що використовувалась для масиву-вектора 
{
	free(Vector);
}
