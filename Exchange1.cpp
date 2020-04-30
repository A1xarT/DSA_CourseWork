#include "Exchange1.h" 
#include "Filling.h" // Для доступу до функцій заповнення масивів
#include "Common_Vector.h" // P, M, N, доступ до масивів
#include <stdio.h>
clock_t Exchange1()
{
	int tmp; // змінна для обміну елементів масиву 
	clock_t time_start, time_stop;
	time_start = clock();
	for (int k = 0; k < P; k++) // проходження по перерізах масиву
	{
		for (int R1 = M - 1, R2 = N - 1; ((R1 > 0) || (R2 > 0));)// зовнішній цикл обходу, який в заголовку містить індекси 
		{														 // верхньої(більшої) межі проходження внутрішніх циклів
			for (int j = 0; j < R2; j++)		// Проходження по ще не відсортрованих стовпчиках, окрім останнього
			{
				for (int i = 0; i < M-1; i++) // Проходження по рядках    
				{
					if (Arr3D[k][i][j] > Arr3D[k][i+1][j])
					{
						tmp = Arr3D[k][i][j];
						Arr3D[k][i][j] = Arr3D[k][i + 1][j];
						Arr3D[k][i + 1][j] = tmp;
					}
				}
				if (Arr3D[k][M - 1][j] > Arr3D[k][0][j + 1]) // порівняння крайнього нижнього елемента j-го стовпчика
				{											 // з першим елементом j+1-го стовпчика
					tmp = Arr3D[k][M-1][j];
					Arr3D[k][M-1][j] = Arr3D[k][0][j+1];
					Arr3D[k][0][j+1] = tmp;
				}
			}
			for (int i = 0; i < R1; i++)	// проходження по рядках останнього невідсортрованого стопчика
			{
				if (Arr3D[k][i][R2] > Arr3D[k][i + 1][R2])
				{
					tmp = Arr3D[k][i][R2];
					Arr3D[k][i][R2] = Arr3D[k][i + 1][R2];
					Arr3D[k][i + 1][R2] = tmp;
				}
			}
			R1 = R1 - 1; // зміна індексу рядків верхньої межі проходження
			if (R1 == -1) { R1 = M - 1; R2 = R2 - 1; } // якщо виконалось M-1 проходження зовнішнього циклу, тобто ми отримали     
		}											   // впорядкований стовпчик з правої сторони, зменшуємо верхню межу 
	}												   // проходження по стовпцях та оновлюємо межу по рядках до M-1 
	time_stop = clock();
	return time_stop - time_start;
}clock_t Exchange1Vect(){	int tmp; 
	clock_t time_start, time_stop;
	time_start = clock();	for (int R = M * N - 1; R > 0; R--) // Верхня межа проходження внутрішнього циклу
	{
		for (int i = 0; i < R; i++) // проходження по невідсортованих елементах масиву
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
	return time_stop - time_start;}void Exchange1MeasOrdered() // Функція, яка сортує впорядкований масив measurements_number разів та записує результати вимірів часу в Res[i]
{  
	for (int i = 0; i < measurements_number; i++) {
		FillArrOrdered();
		Res[i] = Exchange1();
	}
	return;
}
void Exchange1MeasRandom() // Функція, яка сортує масив, заповнений випадковими числами measurements_number разів 
{																		// та записує результати вимірів часу в Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillArrRandom();
		Res[i] = Exchange1();
	}
	return;
}
void Exchange1MeasBackOrdered() // Функція, яка сортує обернено впорядкований масив measurements_number разів 
{																		// та записує результати вимірів часу в Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillArrBackOrdered();
		Res[i] = Exchange1();
	}
	return;
}
void Exchange1MeasOrderedVect() // Функція, яка сортує впорядковано заповнений масив-вектор measurements_number разів 
{																		// та записує результати вимірів часу в Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillVecOrdered();
		Res[i] = Exchange1Vect();
	}
	return;
}

void Exchange1MeasRandomVect() // Функція, яка сортує випадково заповнений масив-вектор measurements_number разів 
{																		// та записує результати вимірів часу в Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillVecRandom();
		Res[i] = Exchange1Vect();
	}
	return;
}

void Exchange1MeasBackOrderedVect() // Функція, яка сортує обернено впорядкований масив measurements_number разів																			
{																		// та записує результати вимірів часу в Res[i]
	for (int i = 0; i < measurements_number; i++) {
		FillVecBackOrdered();
		Res[i] = Exchange1Vect();
	}
	return;
}
