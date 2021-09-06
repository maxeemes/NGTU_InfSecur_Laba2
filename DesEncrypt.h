#include <iostream>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <Windows.h>

using namespace std;
//TODO: сделать очистку памяти 

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
bitset<4> *TransormationS(bitset<6> *EkBitset);						//преобразование S, состоящее из 8 преобразований S -блоков S_1, S_2, S_3... S_8,
bitset<8> *Permutation(bitset<8> *SBitset);							//перестановка  P.

bitset<8> *KeysGenerationK(bitset<8> *K);									//Генерирование ключей k_i, входные данные битовый ключ из 7 байт, возвращает массив 16 ключей по 6 байт
bitset<8> *KeyAddParityBits(bitset<8> *K);										//добавление к 56 битовому ключу битов таким образом, чтобы каждый байт содержал нечетное число единиц.
bool KeyGetCD(bitset<8> *Kp, bitset<1> *Ci, bitset<1> *Di);						//формирование блоков C_0 и D_0
bitset<1> *LeftCyclicShift(bitset<1> *Bitset, const size_t ShiftNumber, const int BitsetSize = 28 );			//функция циклических сдвигов влево
bitset<8> *KeyCDPermutation(bitset<1> *Ci, bitset<1> *Di);


bitset<8> *FinalPermutation8(bitset<8> * FittedBitsetArray8);			//функция конечной перестановки для 64 бит
bitset<8> *FinalPermutation(bitset<8> * BitsetArray, const int ArraySize);		//функция конечной перестановки для всех блоков


