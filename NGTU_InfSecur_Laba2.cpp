#include <iostream>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <Windows.h>
#include "DesEncrypt.h"

using namespace std;

bool AddConsoleTextColor(const string Text, const int Color = 7);//�����: 7 - �����(�����������), 10 - �������, 12 - �������, 14 - ������, 224 - ������ �� ������ ����
int ReadConsoleNum(const string Text = "", const int Color = 7);

bitset<8> *StringToBitset8Array(const string Text);//������� �������������� � ������ �����
string Bitset8ArrayToString(bitset<8> *BiitsetArray, const int ArraySize);//������� �������������� �� ������� ����� � �����
string Bitset8ArrayToIntString(bitset<8>* BiitsetArray, int ArraySize);//������� �������������� �� ������� ����� � ����� �� ����
string FitKey(const string Key);//������� ���������� �����

//������� ����������� ��� ����������

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	bool IsExit = false;
	string Message, Key;

	//���������� ���� ���������
	do {
		AddConsoleTextColor("���������� ��������� ���������� DES", 224);
		switch (ReadConsoleNum("��� ���������� ��������� ������� 1, ��� ������ 2...", 14))
		{
		case 1: //���� ����� ���������
		{
			AddConsoleTextColor("������� ���������...", 14);
			//cin >> Message;
			getchar();
			getline(cin, Message);
			AddConsoleTextColor("���� ��� �����, �� ������ 7 ��������...", 14);
			//cin >> Key;
			getline(cin, Key);
			if (Key.length() <= 7)
			{
				//���������� ����� �� 7 ��������
				Key = FitKey(Key);
				bitset<8> *BitMessage = StringToBitset8Array(Message);
				bitset<8> *BitKey = StringToBitset8Array(Key);
				size_t SizeMessage = Message.size();
				bitset<8> *EncryptedMessage = DesEncrypt(BitMessage, &SizeMessage, BitKey);
				string ResEncryptedMessage = Bitset8ArrayToIntString(EncryptedMessage, SizeMessage);
				AddConsoleTextColor("���������: [" + ResEncryptedMessage + "]", 14);
			}
			else
			{
				AddConsoleTextColor("������ ����������� ����! ���� ������ �� ���� ������ � ������ �������� ������ �� �������� �������� �������� ��� ����� ""�"" � ��������!", 12);
			}
			break;
		}
		case 2: //����� �� ���������
		{
			IsExit = true;
			break;
		}
		default:
			break;
		}
	} while (IsExit == false);

	return 0;
}

bool AddConsoleTextColor(const string Text, const int Color)//�����: 7 - �����(�����������), 10 - �������, 12 - �������, 14 - ������, 224 - ������ �� ������ ����
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
	//���������� ������������� ������� ��� ����������
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
		char NewLetter = (char)BiitsetArray[i].to_ulong();
		ResString += NewLetter;
	}
	return ResString;
}

string Bitset8ArrayToIntString(bitset<8>* BiitsetArray, int ArraySize)
{
	if (ArraySize <= 0) return string();
	string ResString = to_string(BiitsetArray[0].to_ulong());
	for (int i = 0; i < ArraySize; i++)
	{
		ResString += ' ' + to_string(BiitsetArray[i].to_ulong());
	}
	return ResString;
}


string FitKey(const string Key)
{
	int InKeyLength = Key.length();
	string ResKey = "";
	if (InKeyLength < 7)
	{
		for (int si = 0; si < 7; si++)
		{
			if (si < InKeyLength)
			{
				ResKey += Key[si];
			}
			else
			{
				ResKey += (char)0;
			}
		}
	}
	else
	{
		return string();
	}

	return ResKey;
}
