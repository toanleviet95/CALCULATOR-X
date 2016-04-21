#include "CalculatorX.h"

// Cài đặt các hàm cho Board xử lý: Đổi từ số Bin sang số Dec và Hex

// Vẽ board
void VeBoardNhiPhan()
{
	cBoard board;
	system("Color 1F");
	resizeBuffer(79, 35);
	board.drawBoard(1, 2, 80, 9, 11, 14, "Ket qua:", 14);
	board.drawBoard(1, 11, 80, 15, 7, 14, "Nhap day nhi phan:", 14);
	board.drawBoard(20, 17, 60, 33, 2, 14, "Chon thao tac", 14);
	gotoxy(22, 19);
	cout << "  Chuyen doi sang he so: ";
	gotoxy(28, 21);
	cout << "1. Dec	    2. Hex";
	gotoxy(32, 23);
	cout << "3. Tro ve Menu";
	gotoxy(22, 25);
	cout << "Nhap ma so thao tac can thuc hien: ";
	gotoxy(22, 27);
	cout << "Luu y: Chi nhap ma so tu 1 den 3";
}

// Nhập thao tác chuyển đổi cho số nhị phân
void NhapThaoTacChuyenDoiBin(int &chon)
{
	do{
		gotoxy(57, 25);
		cin >> chon;
		if (chon < 1 || chon > 2){
			gotoxy(57, 25);
			cout << " ";
		}
		if (chon == 3)
			BoardMenu();
	} while (chon < 1 || chon > 3);
}

// Nhập dãy nhị phân
void NhapDayNhiPhan(BigInt &BI, int NumOfBit)
{
	gotoxy(2, 12);
	ScanBinaryBI(BI, NumOfBit);
}

// Xuất dãy nhị phân
void XuatDayNhiPhan(BigInt BI, int NumOfBit)
{
	cBoard board;
	ClearAt(2, 12);
	ClearAt(2, 13);
	ClearAt(2, 4);
	ClearAt(2, 5);
	ClearAt(2, 6);
	ClearAt(2, 7);
	board.drawBoard(1, 11, 80, 15, 7, 14, "Nhap day nhi phan:", 14);
	gotoxy(2, 4);
	PrintBinaryBI(BI, NumOfBit);
}

// Xử lý các thao tác trong board
void XuLyBoardNhiPhan(int NumOfBit)
{
	BigInt BI;
	int chon = 0;
	NhapDayNhiPhan(BI, NumOfBit);
	XuatDayNhiPhan(BI, NumOfBit);
	NhapThaoTacChuyenDoiBin(chon);
	do
	{
		gotoxy(57, 25);
		cout << " ";
		if (chon == 1)
		{
			gotoxy(2, 6);
			cout << "Dec " << NumOfBit << " bit: ";
			gotoxy(2, 7);
			PrintBigInt(BI, NumOfBit);
			NhapDayNhiPhan(BI, NumOfBit);
			XuatDayNhiPhan(BI, NumOfBit);
			ClearAt(2, 6);
			ClearAt(2, 7);
			NhapThaoTacChuyenDoiBin(chon);
		}
		else if (chon == 2)
		{
			gotoxy(2, 6);
			cout << "Hex " << NumOfBit << " bit: ";
			gotoxy(2, 7);
			PrintHexa(BI, NumOfBit);
			NhapDayNhiPhan(BI, NumOfBit);
			XuatDayNhiPhan(BI, NumOfBit);
			ClearAt(2, 6);
			ClearAt(2, 7);
			NhapThaoTacChuyenDoiBin(chon);
		}
	} while (chon);
}

// Đóng gói các hàm ở trên vào một hàm duy nhất
void BoardNhiPhan(int NumOfBit)
{
	system("cls");
	if (NumOfBit == 64)
		SetConsoleTitle(TEXT("So nhi phan 8 byte"));
	else
		SetConsoleTitle(TEXT("So nhi phan 16 byte"));
	VeBoardNhiPhan();
	XuLyBoardNhiPhan(NumOfBit);
}