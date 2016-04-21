#include "CalculatorX.h"

// Cài đặt các hàm thao tác trên bit (Mỗi kiểu một hàm):

// Đặt tất cả bit về 0
void SetZeroAllBitBI(BigInt &BI, int NumOfBit)
{
	int n = NumOfBit / 32;
	for (int i = 0; i < n; i++)
		BI.data[i] = BI.data[i] & 0;
}

void SetZeroAllBitQF(QFloat &QF)
{
	for (int i = 0; i < 4; i++)
		QF.data[i] = QF.data[i] & 0;
}

// Bật bit tại vị trí Pos
void BitOnBI(BigInt &BI, int Pos)
{
	int Part = Pos / 32;
	BI.data[Part] = BI.data[Part] | (1 << (Pos % 32));
}

void BitOnQF(QFloat &QF, int Pos)
{
	int Part = Pos / 32;
	QF.data[Part] = QF.data[Part] | (1 << (Pos % 32));
}

// Tắt bit tại vị trí Pos
void BitOffBI(BigInt &BI, int Pos)
{
	int Part = Pos / 32;
	BI.data[Part] = BI.data[Part] & (~(1 << (Pos % 32)));
}

void BitOffQF(QFloat &QF, int Pos)
{
	int Part = Pos / 32;
	QF.data[Part] = QF.data[Part] & (~(1 << (Pos % 32)));
}

// Gán giá trị cho bit tại vị trí Pos
void SetBitBI(BigInt &BI, int bit, int Pos)
{
	if (bit == 0)
		BitOffBI(BI, Pos);
	else if (bit == 1)
		BitOnBI(BI, Pos);
}

void SetBitQF(QFloat &QF, int bit, int Pos)
{
	if (bit == 0)
		BitOffQF(QF, Pos);
	else if (bit == 1)
		BitOnQF(QF, Pos);
}

// Lấy giá trị của bit tại vị trí Pos
bool GetBitBI(BigInt BI, int Pos)
{
	int Part = Pos / 32;
	bool Value = (BI.data[Part] >> (Pos % 32)) & 1;
	return Value;
}

bool GetBitQF(QFloat QF, int Pos)
{
	int Part = Pos / 32;
	bool Value = (QF.data[Part] >> (Pos % 32)) & 1;
	return Value;
}