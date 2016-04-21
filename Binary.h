#pragma once
#include "CalculatorX.h"

// Các hàm dành cho BigInt và QFloat dưới dạng Binary
void StrToBinBI(string Bin, BigInt &BI, int NumOfBit);
void StrToBinQF(string Bin, QFloat &QF);
string BinToDec(BigInt BI, int NumOfBit);
string BinToFloat(QFloat QF);
string BinToHex(BigInt BI, int NumOfBit);
void ScanBinaryBI(BigInt &BI, int NumOfBit);
void ScanBinaryQF(QFloat &QF);
void PrintBinaryBI(BigInt BI, int NumOfBit);
void PrintBinaryQF(QFloat QF);
void PrintHexa(BigInt BI, int NumOfBit);