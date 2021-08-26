#include <iostream>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <Windows.h>
#include "DesEncrypt.h"

using namespace std;

bool AddConsoleTextColor(const string Text, const int Color = 7);//÷вета: 7 - белый(стандартный), 10 - зеленый, 12 - красный, 14 - желтый, 224 - черный на желтом фоне
int ReadConsoleNum(const string Text = "", const int Color = 7);

bitset<8> *StringToBitset8Array(const string Text);//функци€ преобразовани€ в массив битов
string Bitset8ArrayToString(bitset<8> *BiitsetArray, const int ArraySize);//функци€ преобразовани€ из массива битов в текст
//функции интерефейса дл€ шифровани€

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string myString = "привет";
	bitset<8> * testBitset = StringToBitset8Array(myString);


	for (int i = 0; i < myString.size(); ++i)
	{
		cout << testBitset[i] << endl;
	}
	cout << Bitset8ArrayToString(testBitset, myString.length()) << endl;

	int NewSize = myString.size();
	testBitset = FitArray(testBitset, &NewSize);
	for (int i = 0; i < NewSize; ++i)
	{
		cout << i * 8 << " - \t" << testBitset[i] << endl;
		//for (int Bit = 0; Bit < 8; Bit++)
		//{
		//	cout << testBitset[i][Bit];
		//}
		//cout << endl;
	}
	cout << Bitset8ArrayToString(testBitset, NewSize) << endl;

	bitset<8> * Permuted = InitialPermutaion8(testBitset);
	for (int i = 0; i < NewSize; i++)
	{
		cout << Permuted[i] << endl;
	}
	cout << Bitset8ArrayToString(Permuted, NewSize) << endl;

	return 0;
}

bool AddConsoleTextColor(const string Text, const int Color)//÷вета: 7 - белый(стандартный), 10 - зеленый, 12 - красный, 14 - желтый, 224 - черный на желтом фоне
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

bitset<8>* StringToBitset8Array(string Text)
{
	if(Text.length() <= 0) return nullptr;
	//объ€вление динамического массива дл€ результата
	bitset<8> * ResBitset = new bitset<8>[Text.length()];
	for (int i = 0; i < Text.size(); ++i)
	{
		ResBitset[i] = bitset<8>(Text.c_str()[i]);
	}
	return ResBitset;
}

string Bitset8ArrayToString(bitset<8>* BiitsetArray, int ArraySize)
{
	if(ArraySize <= 0) return string();
	string ResString;
	for (int i = 0; i < ArraySize; i++)
	{
		ResString += (char)BiitsetArray[i].to_ulong();
	}
	return ResString;
}
