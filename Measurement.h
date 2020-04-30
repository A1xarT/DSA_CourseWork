#ifndef __Measurement_H__
#define __Measurement_H__
#include <time.h>
// Загальна кількість вимірів часу роботи алгоритма
#define measurements_number 28
// Кількість відкинутих початкових вимірів
#define rejected_number 2
// Кількість відкинутих вимірів з мінімільними значеннями.
// Вона ж дорівнює кількості відкинутих вимірів
// з максимальними значеннями.
#define min_max_number 3
// Масив значень часу роботи алгоритма
extern clock_t Res[measurements_number];
// Функція обробки і усереднення значень вимірів
// часу роботи алгоритма.
// Повертає усереднене значення часу роботи алгоритма.
float MeasurementProcessing();
#endif