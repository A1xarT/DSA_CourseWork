#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include <stdio.h> // ��� printf()
#include "Printing.h" // ��� ������� �� ������� ��������� ������ � ������� 
#include "Windows.h" // ��� system("cls")
#include <conio.h> // ��� _getch()
#include "Table.h" // ��� ������� table_form()
const int l = 5; // ����� ��� ��������� ������ ���� ������ ����
m_names articles[l] = { "Select-4", "Select-6", "Exchange-1" ,"Table", "Exit" }; // ����� ���� ������ ����
void gotoxy(int x, int y) // ������� ��� ���� ������� �������(�������) � ������ 
{
	printf("\033[%d;%dH", y, x); 
}
void frame(int x1, int y1, int x2, int y2) // ������� ��� ��������� �� ����� �����
{										   // (�1,�1) � ������ ���� ���; (x2,y2) � ������ �����
	int i;
	gotoxy(x1, y1);
	printf("%c", '\311');
	for (i = x1 + 1; i <= x2 - 1; i++) {
		printf("%c", '\315');
	}
	printf("%c", '\273');
	for (i = y1 + 1; i <= y2 - 1; i++) {
		gotoxy(x1, i);
		printf("%c", '\272');
		gotoxy(x2, i);
		printf("%c", '\272');
	}
	gotoxy(x1, y2);
	printf("%c", '\310');
	for (i = x1 + 1; i <= x2 - 1; i++) {
		printf("%c", '\315');

	}
	printf("%c", '\274');

}
void fPage() // ������� ��� ��������� ��������� ������� ����
{
	frame(10, 5, 70, 18);
	gotoxy(33, 8);
	printf("SDA Coursework\n");
	gotoxy(35, 10);
	printf("Variant 88\n");
	gotoxy(32, 12);
	printf("Group name: KV-82");
	gotoxy(36, 14);
	printf("Made by");
	gotoxy(32, 16);
	printf("Illya Lyubchych\n");
	_getch();
}

void Menu() // �������, ��� ����������� ����� �������� ����
{
	system("cls");
	fPage();
	int c, a;
	int p = 0;
	while (1)
	{
		c = 0;
		system("cls");
		frame(10, 5, 70, 18);
		gotoxy(36, 6);
		printf("Main Menu");
		for (int i = 0; i < l; i++)
		{
			gotoxy(36, 6 + (c=c+2));
			printf("%d%s", i+1, articles[i]);
		}
		gotoxy(36, 23);
		printf("Input the number of command you want to be executed\n\n  ");
		scanf("%d", &p);
		switch (p) {
		case 1: 
			system("cls");
			a = -1;
			printf("  Select what to sort:\n\n  1. 3D Array\n\n  2. Vector\n\n  3. Back to menu\n\n");
			while ((a != 1) && (a != 2)&&(a != 3))
			{
				scanf("%d", &a);
			}
			switch (a) {
			case 1: PrintSelect4(); break;
			case 2: PrintSelect4Vect(); break;
			case 3: break;
			}
			continue;
		case 2: 
			system("cls");
			a = -1;
			printf("  Select what to sort:\n\n  1. 3D Array\n\n  2. Vector\n\n  3. Back to menu\n\n");
			while ((a != 1) && (a != 2) && (a != 3))
			{
				scanf("%d", &a);
			}
			switch (a) {
			case 1: PrintSelect6(); continue;
			case 2: PrintSelect6Vect(); continue;
			case 3: break;
			}
			continue;
		case 3: 
			system("cls");
			a = -1;
			printf("  Select what to sort:\n\n  1. 3D Array\n\n  2. Vector\n\n  3. Back to menu\n\n");
			while ((a != 1) && (a != 2) && (a != 3))
			{
				scanf("%d", &a);
			}
			switch (a) {
			case 1: PrintExchange1(); continue;
			case 2: PrintExchange1Vect(); continue;
			case 3: break;
			}
			continue;
		case 4: system("cls"); table_form(); continue;
		case 5: system("cls"); system("cls"); return;
		}
		
	}
	
}