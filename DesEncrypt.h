#include <iostream>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <Windows.h>

using namespace std;

bitset<8> *FitArray(bitset<8> * BitsetArray, int * ArraySize);				//функция добавления битов для получения блоков по 64 бита
bitset<8> *InitialPermutation8(bitset<8> * const FittedBitsetArray8);		//функция начальной перестановки для 64 бит
bitset<8> *InitialPermutation(bitset<8> * BitsetArray, const int ArraySize);	//функция начальной перестановки для всех блоков



bitset<8> *DesEncrypt();								//функция шифрования
bitset<8> *BitsetXor(bitset<8> *LBitset, bitset<8> *FBitset, int BisetArraySize = 4);	//функция битового сложения блоков по 32 бита по модулю 2
bitset<8> *Feistel(bitset<8> *RBitset, bitset<8> *NKey);		//Основная функция шифрования (функция Фейстеля)
		/*
			Аргументами функции f являются 32-битовый вектор R_{i-1} и 48-битовый ключ k_i, 
			который является результатом преобразования 56-битового исходного ключа шифра k. 
		*/
bitset<8> *ExtensionE(bitset<8> *RBitset);							//функция расширения 32-битового E, расширяет вектор R до 48-битового вектора E(R)
//BitsetXor(*ExtensionE(bitset<8> *RBitset), k_i)					//сложение по модулю 2 с ключом k_i
bitset<8> *TransormationS(bitset<8> *EkBitset);						//преобразование S, состоящее из 8 преобразований S -блоков S_1, S_2, S_3... S_8,
bitset<8> *Permutation(bitset<8> *SBitset);							//перестановка  P.

bitset<8> *KeysGenerationK(bitset<8> *K);						//Генерирование ключей k_i, входные данные битовый ключ из 7 байт
bitset<8> *KeyAddParityBits(bitset<8> *K);							//добавление к 48 битовому ключу битов таким образом, чтобы каждый байт содержал нечетное число единиц.
bool KeyGetCD(bitset<8> *Kp, bitset<8> *Ci, bitset<8> *Di);			//формирование блоков C_0 и D_0
bitset<8> *CyclicShift(bitset<8> Bitset, int BitsetSize, int ShiftNumber);//функция циклических сдвигов влево
bitset<8> *FinalPermutation8(bitset<8> * const FittedBitsetArray8);		//функция конечной перестановки для 64 бит
bitset<8> *FinalPermutation(bitset<8> * BitsetArray, const int ArraySize);	//функция конечной перестановки для всех блоков


