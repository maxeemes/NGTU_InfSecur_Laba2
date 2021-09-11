#include "DesEncrypt.h"

//������� ��������� ������������
const int InitialPermutaionTable[] = {
	58, 50, 42, 34, 26, 18, 10, 2,	 60, 52, 44, 36, 28, 20, 12, 4,
	62, 54, 46, 38, 30, 22, 14, 6,	 64, 56, 48, 40, 32, 24, 16, 8,
	57, 49, 41, 33, 25, 17, 9,	1,	 59, 51, 43, 35, 27, 19, 11, 3,
	61, 53, 45, 37, 29, 21, 13, 5,	 63, 55, 47, 39, 31, 23, 15, 7
};

//������� ���������� E
const int ExtensionETable[] = {
	32,	1,	2,	3,	4,	5,
	4,	5,	6,	7,	8,	9,
	8,	9,	10,	11,	12,	13,
	12,	13,	14,	15,	16,	17,
	16,	17,	18,	19,	20,	21,
	20,	21,	22,	23,	24,	25,
	24,	25,	26,	27,	28,	29,
	28,	29,	30,	31,	32,	1
};

//������� �������������� S
const int TransormationSTable[32][16] = {
	{14,	4,	13,	1,	2,	15,	11,	8,	3,	10,	6,	12,	5,	9,	0,	7},		//
	{0,		15,	7,	4,	14,	2,	13,	1,	10,	6,	12,	11,	9,	5,	3,	8},		//S_1
	{4,		1,	14,	8,	13,	6,	2,	11,	15,	12,	9,	7,	3,	10,	5,	0},		//
	{15,	12,	8,	2,	4,	9,	1,	7,	5,	11,	3,	14,	10,	0,	6,	13},	//
	
	{15,	1,	8,	14,	6,	11,	3,	4,	9,	7,	2,	13,	12,	0,	5,	10},	//
	{3,		13,	4,	7,	15,	2,	8,	14,	12,	0,	1,	10,	6,	9,	11,	5},		//S_2
	{0,		14,	7,	11,	10,	4,	13,	1,	5,	8,	12,	6,	9,	3,	2,	15},	//
	{13,	8,	10,	1,	3,	15,	4,	2,	11,	6,	7,	12,	0,	5,	14,	9},		//
	
	{10,	0,	9,	14,	6,	3,	15,	5,	1,	13,	12,	7,	11,	4,	2,	8},		//
	{13,	7,	0,	9,	3,	4,	6,	10,	2,	8,	5,	14,	12,	11,	15,	1},		//S_3
	{13,	6,	4,	9,	8,	15,	3,	0,	11,	1,	2,	12,	5,	10,	14,	7},		//
	{1,		10,	13,	0,	6,	9,	8,	7,	4,	15,	14,	3,	11,	5,	2,	12},	//
	
	{7,		13,	14,	3,	0,	6,	9,	10,	1,	2,	8,	5,	11,	12,	4,	15},	//
	{13,	8,	11,	5,	6,	15,	0,	3,	4,	7,	2,	12,	1,	10,	14,	9},		//S_4
	{10,	6,	9,	0,	12,	11,	7,	13,	15,	1,	3,	14,	5,	2,	8,	4},		//
	{3,		15,	0,	6,	10,	1,	13,	8,	9,	4,	5,	11,	12,	7,	2,	14},	//
	
	{2,		12,	4,	1,	7,	10,	11,	6,	8,	5,	3,	15,	13,	0,	14,	9},		//
	{14,	11,	2,	12,	4,	7,	13,	1,	5,	0,	15,	10,	3,	9,	8,	6},		//S_5
	{4,		2,	1,	11,	10,	13,	7,	8,	15,	9,	12,	5,	6,	3,	0,	14},	//
	{11,	8,	12,	7,	1,	14,	2,	13,	6,	15,	0,	9,	10,	4,	5,	3},		//
	
	{12,	1,	10,	15,	9,	2,	6,	8,	0,	13,	3,	4,	14,	7,	5,	11},	//
	{10,	15,	4,	2,	7,	12,	9,	5,	6,	1,	13,	14,	0,	11,	3,	8},		//S_6
	{9,		14,	15,	5,	2,	8,	12,	3,	7,	0,	4,	10,	1,	13,	11,	6},		//
	{4,		3,	2,	12,	9,	5,	15,	10,	11,	14,	1,	7,	6,	0,	8,	13},	//
	
	{4,		11,	2,	14,	15,	0,	8,	13,	3,	12,	9,	7,	5,	10,	6,	1},		//
	{13,	0,	11,	7,	4,	9,	1,	10,	14,	3,	5,	12,	2,	15,	8,	6},		//S_7
	{1,		4,	11,	13,	12,	3,	7,	14,	10,	15,	6,	8,	0,	5,	9,	2},		//
	{6,		11,	13,	8,	1,	4,	10,	7,	9,	5,	0,	15,	14,	2,	3,	12},	//
	
	{13,	2,	8,	4,	6,	15,	11,	1,	10,	9,	3,	14,	5,	0,	12,	7},		//
	{1,		15,	13,	8,	10,	3,	7,	4,	12,	5,	6,	11,	0,	14,	9,	2},		//S_8
	{7,		11,	4,	1,	9,	12,	14,	2,	0,	6,	10,	13,	15,	3,	5,	8},		//
	{2,		1,	14,	7,	4,	10,	8,	13,	15,	12,	9,	0,	3,	5,	6,	11}		//
};

const int PermutaionTable[4][8] = {
	{16,	7,	20,	21,	29,	12,	28,	17},
	{1,		15,	23,	26,	5,	18,	31,	10},
	{2,		8,	24,	14,	32,	27,	3,	9},
	{19,	13,	30,	6,	22,	11,	4,	25}
};

const int KeyPermutationCTable[28] = {
	57,	49,	41,	33,	25,	17,	9,	1,	58,	50,	42,	34,	26,	18,	//C_0
	10,	2,	59,	51,	43,	35,	27,	19,	11,	3,	60,	52,	44,	36
};

const int KeyPermutationDTable[28] = {
	63,	55,	47,	39,	31,	23,	15,	7,	62,	54,	46,	38,	30,	22,	//D_0
	14,	6,	61,	53,	45,	37,	29,	21,	13,	5,	28,	20,	12,	4
};

const int FinalPermutaionTable[8][8] = {
	{40,	8,	48,	16,	56,	24,	64,	32},	{39,	7,	47,	15,	55,	23,	63,	31},
	{38,	6,	46,	14,	54,	22,	62,	30},	{37,	5,	45,	13,	53,	21,	61,	29},
	{36,	4,	44,	12,	52,	20,	60,	28},	{35,	3,	43,	11,	51,	19,	59,	27},
	{34,	2,	42,	10,	50,	18,	58,	26},	{33,	1,	41,	9,	49,	17,	57,	25}
};

const int KeyCDPermutationTable[6][8] = {
	{14,	17,	11,	24,	1,	5,	3,	28},	{15,	6,	21,	10,	23,	19,	12,	4 },
	{26,	8,	16,	7,	27,	20,	13,	2},		{41,	52,	31,	37,	47,	55,	30,	40},
	{51,	45,	33,	48,	44,	49,	39,	56},	{34,	53,	46,	42,	50,	36,	29,	32}
};

const int CiDiShiftSize[16] = { 1,	1,	2,	2,	2,	2,	2,	2,	1,	2,	2,	2,	2,	2,	2,	1 };

bitset<8>* FitArray(bitset<8>* BitsetArray, size_t * ArraySize)
{
	if(*ArraySize <= 0) return nullptr;
	int NewArraySize = *ArraySize / 8 * 8;//����� ������ �������
	if (*ArraySize % 8 > 0)
	{
		NewArraySize += 8;
	}
	bitset<8>* NewBitsetArray = new bitset<8>[NewArraySize];//����� ������
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

bitset<8>* InitialPermutation8(bitset<8>* const FittedBitsetArray8)
{
	bitset<8> * InitialPermutaion8Res = new bitset<8>[8];	//����� ��� ����������
	for (int ByteNum = 0; ByteNum < 8; ByteNum++)			//���� ������������
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

bitset<8>* InitialPermutation(bitset<8>* BitsetArray, const int ArraySize)
{
	if (ArraySize > 0 && ArraySize % 8 != 0) return nullptr;
	bitset<8>* PermutatedBitsetArray = new bitset<8>[ArraySize];
	bitset<8>* TempBitsetArray;

	for (int i = 0; i < ArraySize; i += 8)						//���� �������� ���������� �� 8 ����
	{
		TempBitsetArray = InitialPermutation8(&BitsetArray[i]);	//��������� �����������������
		for (int ByteNum = 0; ByteNum < 8; ByteNum++)
		{
			PermutatedBitsetArray[i + ByteNum] = TempBitsetArray[ByteNum];
		}
		delete[] TempBitsetArray;
	}

	return PermutatedBitsetArray;
}

bitset<8>* BitsetXor(bitset<8>* LBitset, bitset<8>* FBitset, int BisetArraySize)
{
	bitset <8> *ResBitset = new bitset<8>[BisetArraySize];
	for (int i = 0; i < BisetArraySize; i++)
	{
		ResBitset[i] = LBitset[i] ^ FBitset[i];
	}
	return ResBitset;
}

bitset<8>* ExtensionE(bitset<8>* RBitset)
{
	bitset<8> *ExtendedBitset = new bitset<8>[6];
	for (int ByteNum = 0; ByteNum < 6; ByteNum++)
	{
		string NewByte;
		for (int BitNum = 0; BitNum < 8; BitNum++)	//���� �������� ����� ����� ����� ������������ E
		{
			int FullBitNum = ByteNum * 8 + BitNum;
			int NewBitNum = ExtensionETable[FullBitNum] - 1;
			ExtendedBitset[ByteNum][BitNum] = RBitset[NewBitNum / 8][NewBitNum % 8];
		}
	}
	return ExtendedBitset;
}

bitset<4>* TransormationS(bitset<6>* EkBitset)
{
	bitset<4> *TransoformatedS = new bitset<4>[8];
	for (int SNum = 0, EkBitsetNum = 0; SNum < 32 && EkBitsetNum < 8; SNum += 4, EkBitsetNum++)
	{
		bitset<2> A;						//������ ������ � ������� �������������� S
		A[0] = EkBitset[EkBitsetNum][0];
		A[1] = EkBitset[EkBitsetNum][5];
		bitset<4> B;						//������� � ������� �������������� S
		for (int BitSetInd = 1, BInd = 0; BitSetInd <= 4 && BInd < 4; BitSetInd++, BInd++)//���� ������� ��������
		{
			B[BInd] = EkBitset[EkBitsetNum][BitSetInd];
		}
		TransoformatedS[EkBitsetNum] = TransormationSTable[SNum + A.to_ulong()][B.to_ulong()];//������� ���������������� ��������
	}
	return TransoformatedS;
}

bitset<8>* PermutationP(bitset<8>* SBitset)
{
	bitset<8> *PemutatedVal = new bitset<8>[4];										//���������� ��� �������� ����� ������������
	for (int ByteInd = 0; ByteInd < 4; ByteInd++)									//���� ������������ ������
	{
		for (int BitInd = 0; BitInd < 8; BitInd++)									//���� ������������ �����
		{
			int NewBitPos = PermutaionTable[ByteInd][BitInd];						//��������� ����� ������� ����
			PemutatedVal[ByteInd][BitInd] = SBitset[NewBitPos / 8][NewBitPos % 8];	//��������� ���� �� ����� �������
		}
	}
	return PemutatedVal;
}

bitset<8>* KeysGenerationK(bitset<8>* K)
{
	bitset<8> *GeneratedKeys = new bitset<8>[96];
	bitset<8> *KWithParityBits = KeyAddParityBits(K);
	bitset<1> *Ci, *Di;
	if (!KeyGetCD(KWithParityBits, Ci, Di))
	{
		delete[] GeneratedKeys;
		delete[] KWithParityBits;
		return nullptr;
	}
	delete[] KWithParityBits;

	for (int KiInd = 0, ShiftSize = 0; KiInd < 16; KiInd++)
	{
		ShiftSize += CiDiShiftSize[KiInd];
		bitset<1> *NewCi = LeftCyclicShift(Ci, ShiftSize);
		bitset<1> *NewDi = LeftCyclicShift(Di, ShiftSize);
		bitset<8> *NewKi = KeyCDPermutation(NewCi, NewDi);
		for (int KeyByteInd = KiInd * 6, KiByteInd = 0; KeyByteInd < ((KiInd + 1) * 6) && KiByteInd < 6; KeyByteInd++, KiByteInd++)
		{
			GeneratedKeys[KeyByteInd] = NewKi[KiByteInd];
		}
		delete[] NewCi;
		delete[] NewDi;
		delete[] NewKi;
	}

	return GeneratedKeys;
}

bitset<8>* KeyAddParityBits(bitset<8>* K)
{
	bitset<8> *KeyWithParityBits = new bitset<8>[8];
	for (int ByteInd = 0; ByteInd < 8; ByteInd++)
	{
		bitset<1> ParityBit = true;
		for (int BitInd = 0, KBitNum = ByteInd * 7; BitInd < 7; BitInd++, KBitNum++)
		{
			KeyWithParityBits[ByteInd][BitInd] = K[KBitNum / 8][KBitNum % 8];
			if (KeyWithParityBits[ByteInd][BitInd])
			{
				ParityBit.flip();
			}
		}
		KeyWithParityBits[ByteInd][7] = ParityBit[0];
	}
	return KeyWithParityBits;
}

bool KeyGetCD(bitset<8>* Kp, bitset<1>* Ci, bitset<1>* Di)
{
	for (int BitInd = 0; BitInd < 28; BitInd++)
	{
		int NewKpCiBitNum = KeyPermutationCTable[BitInd] - 1;
		Ci[BitInd][0] = Kp[NewKpCiBitNum / 8][NewKpCiBitNum % 8];
		int NewKpDiBitNum = KeyPermutationDTable[BitInd] - 1;
		Di[BitInd][0] = Kp[NewKpDiBitNum / 8][NewKpDiBitNum % 8];
	}
	return true;
}

bitset<1>* LeftCyclicShift(bitset<1> *Bitset, const size_t ShiftNumber, const int BitsetSize)
{
	bitset<1> *ShiftedBitset = new bitset<1>[BitsetSize];
	for (int BitInd = 0; BitInd < BitsetSize; BitInd++)
	{
		ShiftedBitset[BitInd] = Bitset[BitInd];
	}
	rotate(&ShiftedBitset[0], &ShiftedBitset[0] + ShiftNumber, &ShiftedBitset[BitsetSize]);
	return ShiftedBitset;
}

bitset<8>* KeyCDPermutation(bitset<1>* Ci, bitset<1>* Di)
{
	const int KeyCDPermutatedByteSize = 6;
	bitset<8> *KeyCDPermutated = new bitset<8>[KeyCDPermutatedByteSize];
	for (int ByteInd = 0; ByteInd < KeyCDPermutatedByteSize; ByteInd++)
	{
		for (int BitInd = 0; BitInd < 8; BitInd++)
		{
			int NewBitPos = KeyCDPermutationTable[ByteInd][BitInd] - 1;
			if (KeyCDPermutationTable[ByteInd][BitInd] >= 0 && KeyCDPermutationTable[ByteInd][BitInd] < 28)
			{
				KeyCDPermutated[ByteInd][BitInd] = Ci[NewBitPos][0];
			}
			else if (KeyCDPermutationTable[ByteInd][BitInd] >= 28 && KeyCDPermutationTable[ByteInd][BitInd] < 56)
			{
				NewBitPos -= 28;
				KeyCDPermutated[ByteInd][BitInd] = Di[NewBitPos][0];
			}
			else
			{
				delete[] KeyCDPermutated;
				break;
			}
		}
	}
	return KeyCDPermutated;
}

bitset<8>* FinalPermutation8(bitset<8>* FittedBitsetArray8)
{
	bitset<8> * FinalPermutation8Res = new bitset<8>[8];	//����� ��� ����������
	for (int ByteInd = 0; ByteInd < 8; ByteInd++)			//���� ������������
	{
		for (int BitInd = 0; BitInd < 8; BitInd++)
		{
			int NewBitNum = FinalPermutaionTable[ByteInd][BitInd] - 1;
			FinalPermutation8Res[ByteInd][BitInd] = FittedBitsetArray8[NewBitNum / 8][NewBitNum % 8];
		}
	}
	return FinalPermutation8Res;
}

bitset<8>* FinalPermutation(bitset<8>* BitsetArray, const int ArraySize)
{
	if (ArraySize > 0 && ArraySize % 8 != 0) return nullptr;
	bitset<8>* PermutatedBitsetArray = new bitset<8>[ArraySize];
	bitset<8>* TempBitsetArray;

	for (int i = 0; i < ArraySize; i += 8)						//���� ������� ������������ �� 8 ����
	{
		TempBitsetArray = FinalPermutation8(&BitsetArray[i]);
		for (int ByteNum = 0; ByteNum < 8; ByteNum++)
		{
			PermutatedBitsetArray[i + ByteNum] = TempBitsetArray[ByteNum];
		}
		delete[] TempBitsetArray;
	}
	return PermutatedBitsetArray;
}

