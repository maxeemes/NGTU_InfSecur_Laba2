#include <iostream>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <Windows.h>

using namespace std;
//TODO: ������� ������� ������ 

bitset<8> *FitArray(bitset<8> * BitsetArray, size_t * ArraySize, const size_t BlockSize = 8);				//������� ���������� ����� ��� ��������� ������ �� 64 ����
bitset<6> *Bitset8ToBiset6Array(bitset<8> * BitsetArray, size_t * ArraySize);
bitset<8> *Bitset4ToBiset8Array(bitset<4> * BitsetArray, size_t * ArraySize);
bool BrakeBitsetBlock(bitset<8> * BitsetArray, bitset<8> *L, bitset<8> *R);							//�������� ����� 64 ���� �� ����� �� 32
bitset<8> *UniteBiset8Array(bitset<8> * BitsetArray1, const size_t Array1Size, bitset<8> * BitsetArray2, const size_t Array2Size);

bitset<8> *InitialPermutation8(bitset<8> * const FittedBitsetArray8);		//������� ��������� ������������ ��� 64 ���
bitset<8> *InitialPermutation(bitset<8> * BitsetArray, const int ArraySize);	//������� ��������� ������������ ��� ���� ������



bitset<8> *DesEncrypt(bitset<8> * BitsetArray, size_t *ArraySize, bitset<8> *Key);					//������� ����������, � �������� ������� ������ ��������� ������ ����� ����� ������ � ���� 7 ����
bitset<8> *BitsetXor(bitset<8> *LBitset, bitset<8> *FBitset, int BisetArraySize = 4);	//������� �������� �������� ������ �� 32 ���� �� ������ 2
bitset<8> *Feistel(bitset<8> *RBitset, bitset<8> *NKey);		//�������� ������� ���������� (������� ��������)
		/*
			����������� ������� f �������� 32-������� ������ R_{i-1} � 48-������� ���� k_i, 
			������� �������� ����������� ����			������� ���������� ������ 32 ����
���������� 56-�������� ��������� ����� ����� k. 
		*/
bitset<8> *ExtensionE(bitset<8> *RBitset);							//������� ���������� 32-�������� E, ��������� ������ R �� 48-�������� ������� E(R)
//BitsetXor(*ExtensionE(bitset<8> *RBitset), k_i)					//�������� �� ������ 2 � ������ k_i
bitset<4> *TransormationS(bitset<6> *EkBitset);						//�������������� S, ��������� �� 8 �������������� S -������ S_1, S_2, S_3... S_8,
bitset<8> *PermutationP(bitset<8> *SBitset);							//������������  P.

bitset<8> *KeysGenerationK(bitset<8> *K);									//������������� ������ k_i, ������� ������ ������� ���� �� 7 ����, ���������� ������ 16 ������ �� 6 ����
bitset<8> *KeyAddParityBits(bitset<8> *K);										//���������� � 56 �������� ����� ����� ����� �������, ����� ������ ���� �������� �������� ����� ������.
bool KeyGetCD(bitset<8> *Kp, bitset<1> *Ci, bitset<1> *Di);						//������������ ������ C_0 � D_0
bitset<1> *LeftCyclicShift(bitset<1> *Bitset, const size_t ShiftNumber, const int BitsetSize = 28 );			//������� ����������� ������� �����
bitset<8> *KeyCDPermutation(bitset<1> *Ci, bitset<1> *Di);


bitset<8> *FinalPermutation8(bitset<8> * FittedBitsetArray8);			//������� �������� ������������ ��� 64 ���
bitset<8> *FinalPermutation(bitset<8> * BitsetArray, const int ArraySize);		//������� �������� ������������ ��� ���� ������


