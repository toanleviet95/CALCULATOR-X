#include "CalculatorX.h"

// Cài đặt các hàm cho số BigInt:

// Nhập số BigInt
void ScanBigInt(BigInt &BI, int NumOfBit)
{
	string Dec = "";
	bool Error = false;
	cin >> Dec;
	if (Dec.length() > 1 && Dec[0] == '0')
		Error = true;
	for (int i = 0; i < Dec.length(); i++){
		if (Dec[i] > '9' || Dec[i] < '0'){
			Error = true;
			break;
		}
	}
	if (NumOfBit == 64){
		if (Dec.length() > 20 || Error){
			ClearAt(2, 4);
			ClearAt(2, 6);
			ClearAt(2, 7);
			gotoxy(2, 4);
			cout << "So ban nhap khong phai la mot so nguyen 8 byte!";
			gotoxy(2, 5);
			system("pause");
			BoardSoNguyen(NumOfBit);
		}
	}
	else if (NumOfBit == 128){
		if (Dec.length() > 38 || Error){
			ClearAt(2, 4);
			ClearAt(2, 6);
			ClearAt(2, 7);
			gotoxy(2, 4);
			cout << "So ban nhap khong phai la mot so nguyen 16 byte!";
			gotoxy(2, 5);
			system("pause");
			BoardSoNguyen(NumOfBit);
		}
	}
	StrToBigInt(Dec, BI, NumOfBit);
}

// Chuyển 1 chuỗi số thập phân thành kiểu BigInt
void StrToBigInt(string Dec, BigInt &BI, int NumOfBit)
{
	int Pos = NumOfBit - 1; 
	SetZeroAllBitBI(BI, NumOfBit);
	while (Dec != "0")
	{
		int bit = (Dec[Dec.length() - 1] - 48) % 2; 
		SetBitBI(BI, bit, Pos); 
		Dec = StrDiv2(Dec); 
		Pos--;
	}
	BI.EndPos = Pos;
}

// In ra số BigInt dưới dạng thập phân
void PrintBigInt(BigInt BI, int NumOfBit)
{
	string Result = BinToDec(BI, NumOfBit);
	cout << Result;
}

// Cộng hai số BigInt
string BigIntAdd(BigInt BI1, BigInt BI2, int NumOfBit)
{
	string A = BinToDec(BI1, NumOfBit);
	string B = BinToDec(BI2, NumOfBit);
	return StrAdd(A, B);
}

// Trừ hai số BigInt
string BigIntSub(BigInt BI1, BigInt BI2, int NumOfBit)
{
	string A = BinToDec(BI1, NumOfBit);
	string B = BinToDec(BI2, NumOfBit);
	return StrSub(A, B);
}

// Chia hai số BigInt
string BigIntDiv(BigInt BI1, BigInt BI2, int NumOfBit)
{
	string A = BinToDec(BI1, NumOfBit);
	string B = BinToDec(BI2, NumOfBit);
	return StrDiv(A, B);
}

// Nhân hai số BigInt
string BigIntMulti(BigInt BI1, BigInt BI2, int NumOfBit)
{
	string A = BinToDec(BI1, NumOfBit);
	string B = BinToDec(BI2, NumOfBit);
	return StrMulti(A, B);
}