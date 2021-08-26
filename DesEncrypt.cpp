#include "DesEncrypt.h"

int InitialPermutaionTable[] = {
	58, 50, 42, 34, 26, 18, 10, 2,	 60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,	 64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9,	1,	 59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,	 63, 55, 47, 39, 31, 23, 15, 7
};

bitset<8>* FitArray(bitset<8>* BitsetArray, int * ArraySize)
{
	if(*ArraySize <= 0) return nullptr;
	int NewArraySize = *ArraySize / 8 * 8;//новый размер массива
	if (*ArraySize % 8 > 0)
	{
		NewArraySize += 8;
	}
	bitset<8>* NewBitsetArray = new bitset<8>[NewArraySize];//новый массив
	for (int i = 0; i < *ArraySize; i++)
	{
		NewBitsetArray[i] = BitsetArray[i];
	}
	for (int i = *ArraySize; i < NewArraySize; i++)
	{
		NewBitsetArray[i] = bitset<8>(00000000);
	}
	*ArraySize = NewArraySize;
	return NewBitsetArray;
}

bitset<8>* InitialPermutaion8(bitset<8>* const FittedBitsetArray8)
{
	bitset<8> * InitialPermutaion8Res = new bitset<8>[8];//масив для результата
	for (int ByteNum = 0; ByteNum < 8; ByteNum++)//цикл перестановки
	{
		string NewByte;
		for (int BitNum = 0; BitNum < 8; BitNum++)
		{
			int FullBitNum = ByteNum * 8 + BitNum;
			int NewBitNum = InitialPermutaionTable[FullBitNum] - 1;
			string SelByte = FittedBitsetArray8[NewBitNum / 8].to_string();
			NewByte += SelByte[NewBitNum % 8];
		}
		InitialPermutaion8Res[ByteNum] = bitset<8>(NewByte);
	}

	return InitialPermutaion8Res;
}


