#pragma once
#include "CalculatorX.h"

// Các thao tác trên bit
void SetZeroAllBitBI(BigInt &BI, int NumOfBit);
void SetZeroAllBitQF(QFloat &QF);
void BitOnBI(BigInt &BI, int Pos);
void BitOnQF(QFloat &QF, int Pos);
void BitOffBI(BigInt &BI, int Pos);
void BitOffQF(QFloat &QF, int Pos);
void SetBitBI(BigInt &BI, int bit, int Pos);
void SetBitQF(QFloat &QF, int bit, int Pos);
bool GetBitBI(BigInt BI, int Pos);
bool GetBitQF(QFloat QF, int Pos);

