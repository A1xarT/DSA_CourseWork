#ifndef __Measurement_H__
#define __Measurement_H__
#include <time.h>
// �������� ������� ����� ���� ������ ���������
#define measurements_number 28
// ʳ������ ��������� ���������� �����
#define rejected_number 2
// ʳ������ ��������� ����� � ��������� ����������.
// ���� � ������� ������� ��������� �����
// � ������������� ����������.
#define min_max_number 3
// ����� ������� ���� ������ ���������
extern clock_t Res[measurements_number];
// ������� ������� � ����������� ������� �����
// ���� ������ ���������.
// ������� ���������� �������� ���� ������ ���������.
float MeasurementProcessing();
#endif