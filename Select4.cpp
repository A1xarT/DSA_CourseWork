#include "Select4.h"
#include "Filling.h" // для доступу до функцій заповнення масивів
#include "Common_Vector.h" // P, M, N, доступ до масивів


clock_t Select4()
{
	int L1, L2, R1, R2, imin, jmin, imax, jmax, tmp; // L1 - ліва границя проходження по рядках; L2 - по стовпцях; tmp - змінна для обміну елементів
	clock_t time_start, time_stop;					 //	масиву.	R1 - права границя проходження по рядках; R2 - по стовпцях                          
	time_start = clock();								    // imin, jmin - змінні для запам'ятовування координат мінімального елементу масиву
	for (int k = 0; k < P; k++)// проходження по розрізах	// imax, jmax - змінні для запам'ятовування координат максимального елементу масиву
	{												 	
		L1 = 0; L2 = 0; R1 = M-1; R2 = N-1;
		while (L2 < R2) // доки ліва і права границя по стовпчиках не перетнуться
		{
			imin = L1; jmin = L2; imax = L1; jmax = L2; // (L1,L2) - мінімум; (R1,R2) - максимум
			for (int i = L1 + 1, j = L2; i < M; i++) // проходження по першому невідсортованому стовпчику
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
			for (int j = L2 + 1; j < R2; j++) // проходження по внутрішній частині перерізу (без першого та останнього невідсортованих)
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
			for (int i = 0, j = R2; i < R1+1; i++) // проходження по останньому невідсортованому стовпчику
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
		if (L2 == R2) // якщо ліва та права границя по стовпчиках перетнулись (а це трапляється, коли 
		{			  // кількість стовпчиків є непарним числом), тоді сортуємо внутрішній стовпчик окремо в такий же спосіб
			while (L1 < R1) // доки не дійдемо до середини (парність, непарність рядків не впливає на умову)
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
				L1 = L1 + 1; R1 = R1 - 1; // звуження лівої та правої меж по рядках
			}
		}
	}
	time_stop = clock();
	return time_stop - time_start;
}

clock_t Select4Vect()
{
	int L, R, imin, imax, tmp; // L,R - ліва, права границі проходження, imin, imax - змінні для координат мінімального та максимального елементів, 
	clock_t time_start, time_stop;									// tmp - змінна для обміну елементів
	time_start = clock();
	L = 0; R = M * N - 1;
	while (L < R) // поки ліва границя не перетнеться з правою
	{
		imin = L; imax = L; // присвоєння змінним мінімальної та максимальної координат значення лівої границі 
		for (int i = L + 1; i < R + 1; i++) // обхід по елементах, крім лівої та правої відсортованих частин
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
void Select4MeasOrdered()								// Функції вимірювання часу сортування різними способами заповнення трьохвимірного масиву
{														// та масиву-вектора, функції передають результати у Res[i], які далі усереднюються
	for (int i = 0; i < measurements_number; i++) {		// функцією MeasurementProcessing() для отримання більш точного результату
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