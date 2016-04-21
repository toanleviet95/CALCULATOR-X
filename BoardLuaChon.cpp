#include "CalculatorX.h"

// Cài đặt các hàm cho Board Lựa Chọn:

// Vẽ board
void VeBoardLuaChon()
{
	cBoard board;
	system("Color FC");
	resizeBuffer(79, 35);
	board.drawBoard(12, 2, 68, 33, 2, 1, "Lua chon thao tac", 12);
	board.drawBoard(26, 12, 54, 23, 2, 1);
	gotoxy(29, 15);
	cout << "Ban muon thao tac tren ? ";
	gotoxy(31, 17);
	cout << "  So nguyen (Dec)";
	gotoxy(31, 19);
	cout << "  So nhi phan (Bin)";
	gotoxy(22, 30);
	cout << "* Su dung phim mui ten de di chuyen";
	gotoxy(26, 31);
	cout << "* Su dung phim ENTER de chon";
}

// Thiết lập kiểu di chuyển trong board
int KeyboardLuaChon(int &i)
{
	char ch = _getch();
	if (ch == 13) return 1; // NÚT ENTER
	if (ch == -32)
	{
		ch = _getch();
		if (ch == 80) if (i < 19)i = i + 2; else i = 17; // Xuống
		if (ch == 72) if (i > 17)i = i - 2; else i = 19; // Lên
		gotoxy(31, i);
	}
	return 0;
}

// Xử lý các thao tác trong board
void XuLyBoardLuaChon(int NumOfBit)
{
	int i = 17;
	gotoxy(31, 17);
	do{
		int chon;
		do{
			chon = KeyboardLuaChon(i);
		} while (chon == 0);
		if (i == 17)
			BoardSoNguyen(NumOfBit);
		else if (i == 19)
			BoardNhiPhan(NumOfBit);
	} while (1);
}

// Đóng gói các hàm ở trên vào một hàm duy nhất
void BoardLuaChon(int NumOfBit)
{
	system("cls");
	if (NumOfBit == 64)
		SetConsoleTitle(TEXT("Lua chon cho 8 byte"));
	else
		SetConsoleTitle(TEXT("Lua chon cho 16 byte"));
	VeBoardLuaChon();
	XuLyBoardLuaChon(NumOfBit);
}