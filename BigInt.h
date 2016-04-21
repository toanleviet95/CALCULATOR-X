#pragma once
#include "CalculatorX.h"

// Các hàm dành cho BigInt
void ScanBigInt(BigInt &BI, int NumOfBit);
void PrintBigInt(BigInt BI, int NumOfBit);
void StrToBigInt(string Dec, BigInt &BI, int NumOfBit);
string BigIntAdd(BigInt BI1, BigInt BI2, int NumOfBit);
string BigIntSub(BigInt BI1, BigInt BI2, int NumOfBit);
string BigIntDiv(BigInt BI1, BigInt BI2, int NumOfBit);
string BigIntMulti(BigInt BI1, BigInt BI2, int NumOfBit);