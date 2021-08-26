#include <iostream>
#include <stdlib.h>
#include <string>
#include <Windows.h>
#include "DesEncrypt.h"

using namespace std;

bool AddConsoleTextColor(const string Text, const int Color = 7);//Цвета: 7 - белый(стандартный), 10 - зеленый, 12 - красный, 14 - желтый, 224 - черный на желтом фоне
int ReadConsoleNum(const string Text = "", const int Color = 7);

//функция преобразования в массив битов
//функция преобразования из массива битов в текст
//функции интерефейса для шифрования

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	return 0;
}

bool AddConsoleTextColor(const string Text, const int Color)//Цвета: 7 - белый(стандартный), 10 - зеленый, 12 - красный, 14 - желтый, 224 - черный на желтом фоне
{
	if (Color == 7) {
		cout << Text << endl;
	}
	else {
		HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(Console, Color);
		cout << Text << endl;
		SetConsoleTextAttribute(Console, 7);
	}
	return true;
}

int ReadConsoleNum(const string Text, const int Color)
{
	if (!Text.empty())
	{
		AddConsoleTextColor(Text, Color);
	}
	int Num;
	cin >> Num;
	if (Num >= 0)
	{
		return Num;
	}
	return -1;
}
