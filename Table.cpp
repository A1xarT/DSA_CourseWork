#define _CRT_SECURE_NO_WARNINGS
#include "Table.h"				
#include "Select4.h"			// Функції для
#include "Select6.h"			// вимірювання часу
#include "Exchange1.h"			// виконання алгоритмів сортування
#include "Common_Vector.h" // M, N, P
#include <stdio.h> // для scanf()
#include <cstdlib> // для srand()
float st1_1, st1_2, st1_3, st2_1, st2_2, st2_3, st3_1, st3_2, st3_3, st1_11, st1_22, st1_33, st2_11, st2_22, st2_33, st3_11, st3_22, st3_33;
// оголошення змінних для виводу значень часу виконання алгоритмів
void table_form() // Здійснення вимірів часу дії алгоритмів сортування
{
	int i = 1; // лічильник для слідкування процесу завершення формування таблиці 
	srand(time(NULL));
	Arr(); // виділення пам'яті для трьохвимірного масиву
	Vec(); // виділення пам'яті для масиву-вектора
	Select4MeasOrdered();					// Далі йдуть записи результатів усереднення часу сортування 
	st1_1 = MeasurementProcessing();		// до відповідних змінних типу float
	printf("%d/18\n", i++);					// Результати вимірів сортування векторів розмірністю [M x N] множаться на P - кількість перерізів 
	Select4MeasRandom();					// трьохвимірного масиву (для порівняння)
	st1_2 = MeasurementProcessing();
	printf("%d/18\n", i++);
	Select4MeasBackOrdered();
	st1_3 = MeasurementProcessing();
	printf("%d/18\n", i++);
	Select6MeasOrdered();
	st2_1 = MeasurementProcessing();
	printf("%d/18\n", i++);
	Select6MeasRandom();
	st2_2 = MeasurementProcessing();
	printf("%d/18\n", i++);
	Select6MeasBackOrdered();
	st2_3 = MeasurementProcessing();
	printf("%d/18\n", i++);
	Exchange1MeasOrdered();
	st3_1 = MeasurementProcessing();
	printf("%d/18\n", i++);
	Exchange1MeasRandom();
	st3_2 = MeasurementProcessing();
	printf("%d/18\n", i++);
	Exchange1MeasBackOrdered();
	st3_3 = MeasurementProcessing();
	printf("%d/18\n", i++);
	Select4MeasOrderedVect();
	st1_11 = P * MeasurementProcessing();
	printf("%d/18\n", i++);
	Select4MeasRandomVect();
	st1_22 = P * MeasurementProcessing();
	printf("%d/18\n", i++);
	Select4MeasBackOrderedVect();
	st1_33 = P * MeasurementProcessing();
	printf("%d/18\n", i++);
	Select6MeasOrderedVect();
	st2_11 = P * MeasurementProcessing();
	printf("%d/18\n", i++);
	Select6MeasRandomVect();
	st2_22 = P * MeasurementProcessing();
	printf("%d/18\n", i++);
	Select6MeasBackOrderedVect();
	st2_33 = P * MeasurementProcessing();
	printf("%d/18\n", i++);
	Exchange1MeasOrderedVect();
	st3_11 = P * MeasurementProcessing();
	printf("%d/18\n", i++);
	Exchange1MeasRandomVect();
	st3_22 = P * MeasurementProcessing();
	printf("%d/18\n", i++);
	Exchange1MeasBackOrderedVect();
	st3_33 = P * MeasurementProcessing();
	printf("%d/18\n", i++);
	FreeArr(); // Звільнення пам'яті трьохвимірного масиву
	FreeVec(); // Звільнення пам'яті масиву-вектора
	table_printf(); // виклик функції, що очищує екран та виводить готову таблицю в консолі
	printf("Input 0 to return to menu"); // повернення до меню при введені "0"
	int c = 1;
	while (c != 0)
	{
		scanf("%d", &c);
	}
}
void table_printf() { // очищення екрану, виведення таблиці на екран
	system("cls");
	printf("\n     Measurement Table     P = %d,     M = %d,     N = %d\n\n", P, M, N);
	printf("_______________________________________________________________________________\n");
	printf("                       |                  |                 |                  |\n");
	printf("                       |   Sorted         |   Random        |Back Sorted       |\n");
	printf("_______________________|__________________|_________________|__________________|\n");
	printf("                       |                  |                 |                  |\n");
	printf("Strict Select #4       |    %.2f               %.2f              %.2f           \n", st1_1, st1_2, st1_3);
	printf("_______________________|__________________|_________________|__________________|\n");
	printf("                       |                  |                 |                  |\n");
	printf("Strict Select #6       |    %.2f               %.2f              %.2f           \n", st2_1, st2_2, st2_3);
	printf("_______________________|__________________|_________________|__________________|\n");
	printf("                       |                  |                 |                  |\n");
	printf("Exchange #1            |    %.2f               %.2f              %.2f           \n", st3_1, st3_2, st3_3);
	printf("_______________________|__________________|_________________|__________________|\n");
	printf("                       |                  |                 |                  |\n");
	printf("Vector Strict Select #4|    %.2f               %.2f              %.2f           \n", st1_11, st1_22, st1_33);
	printf("_______________________|__________________|_________________|__________________|\n");
	printf("                       |                  |                 |                  |\n");
	printf("Vector Strict Select #6|    %.2f               %.2f              %.2f           \n", st2_11, st2_22, st2_33);
	printf("_______________________|__________________|_________________|__________________|\n");
	printf("                       |                  |                 |                  |\n");
	printf("Vector Exchange-1      |    %.2f               %.2f              %.2f           \n", st3_11, st3_22, st3_33);
	printf("_______________________|__________________|_________________|__________________|\n");
}
