#include <iostream>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <Windows.h>

using namespace std;

bitset<8> *FitArray(bitset<8> * BitsetArray, int * ArraySize);				//������� ���������� ����� ��� ��������� ������ �� 64 ����
bitset<8> *InitialPermutation8(bitset<8> * const FittedBitsetArray8);		//������� ��������� ������������ ��� 64 ���
bitset<8> *InitialPermutation(bitset<8> * BitsetArray, const int ArraySize);	//������� ��������� ������������ ��� ���� ������



bitset<8> *DesEncrypt();								//������� ����������
bitset<8> *BitsetXor(bitset<8> *LBitset, bitset<8> *FBitset, int BisetArraySize = 4);	//������� �������� �������� ������ �� 32 ���� �� ������ 2
bitset<8> *Feistel(bitset<8> *RBitset, bitset<8> *NKey);		//�������� ������� ���������� (������� ��������)
		/*
			����������� ������� f �������� 32-������� ������ R_{i-1} � 48-������� ���� k_i, 
			������� �������� ����������� �������������� 56-�������� ��������� ����� ����� k. 
		*/
bitset<8> *ExtensionE(bitset<8> *RBitset);							//������� ���������� 32-�������� E, ��������� ������ R �� 48-�������� ������� E(R)
//BitsetXor(*ExtensionE(bitset<8> *RBitset), k_i)					//�������� �� ������ 2 � ������ k_i
bitset<4> *TransormationS(bitset<6> *EkBitset);						//�������������� S, ��������� �� 8 �������������� S -������ S_1, S_2, S_3... S_8,
bitset<8> *Permutation(bitset<8> *SBitset);							//������������  P.

bitset<8> *KeysGenerationK(bitset<8> *K);									//������������� ������ k_i, ������� ������ ������� ���� �� 7 ����
bitset<8> *KeyAddParityBits(bitset<8> *K);										//���������� � 56 �������� ����� ����� ����� �������, ����� ������ ���� �������� �������� ����� ������.
bool KeyGetCD(bitset<8> *Kp, bitset<1> *Ci, bitset<1> *Di);						//������������ ������ C_0 � D_0
bitset<1> *CyclicShift(bitset<1> Bitset, const int ShiftNumber, const int BitsetSize = 28 );			//������� ����������� ������� �����
bitset<8> *FinalPermutation8(bitset<8> * FittedBitsetArray8);			//������� �������� ������������ ��� 64 ���
bitset<8> *FinalPermutation(bitset<8> * BitsetArray, const int ArraySize);		//������� �������� ������������ ��� ���� ������


