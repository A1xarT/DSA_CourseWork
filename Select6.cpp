#include "Select6.h"
#include "Filling.h" // Для використання функцій заповнення масивів
#include "Common_Vector.h" // P, M, N, доступ до масивів, 

clock_t Select6()
{
	int imin, jmin, tmp; // imin, jmin - змінні для запам'ятовування координат мінімального елементу масиву; tmp - змінна для обміну елементів
	clock_t time_start, time_stop;
	time_start = clock();
	for (int k = 0; k < P; k++) // Проходження по перерізах масиву
	{
		for (int l = 0; l < N-1; l++) // Цикл для проходження по невідсортованих стовпчиках, окрім останнього(для нього виділений окремий цикл)
		{
			for (int s = 0; s < M; s++) // Цикл для проходження по невідсортованих рядках l-го стовпчика
			{
				imin = s; jmin = l; // обрання координат крайнього верхнього лівого елементу як мінімальних
				for (int i = s + 1; i < M; i++) // Проходження по рядках першого невідсортованого стовпчика, починаючи з наступного
				{								// після того, чиї координати ми обрали мінімальним
					if (Arr3D[k][i][l] < Arr3D[k][imin][jmin])
					{
						imin = i; jmin = l;
					}
				} 
				for (int j = l + 1; j < N; j++) // проходження по елементах усієї частини, що лишилась непройденою після попереднього циклу 
				{								// тобто усіх невідсортованих стовпчиків після першого(невідсортованого)
					for (int i = 0; i < M; i++) // проходження по рядках
					{
						if (Arr3D[k][i][j] < Arr3D[k][imin][jmin])
						{
							imin = i; jmin = j;
						}
					}
				}
				if ((imin != s) || (jmin != l))	// якщо крайній верхній лівий елемент виявився не мінімальним, міняємо його місцем із 
				{																							 // знайденим мінімальним
					tmp = Arr3D[k][imin][jmin];
					Arr3D[k][imin][jmin] = Arr3D[k][s][l];
					Arr3D[k][s][l] = tmp;
				}
			}
		}
		for (int s = 0; s < M-1; s++) // Цикл для проходження по елементах останнього (N-1-го стовпчика перерізу)
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
	int imin, tmp; // imin - позиція мінімального елементу, tmp - змінна для обміну елементів
	clock_t time_start, time_stop;
	time_start = clock();
	for (int s = 0; s < M*N - 1; s++) // Проходження по невідсортованих елементах
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

void Select6MeasOrdered()							// Функції вимірювання часу сортування різними способами заповнення трьохвимірного масиву
{													// та масиву-вектора, функції передають результати у Res[i], які далі усереднюються		
													// функцією MeasurementProcessing() для отримання більш точного результату
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

