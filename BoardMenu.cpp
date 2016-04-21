#include "CalculatorX.h"

// Cài đặt các hàm cho Board Menu:

// Vẽ board
void VeBoardMenu()
{
	cBoard board;
	system("Color 3F");
	resizeBuffer(79, 35);
	Logo();
	board.drawBoard(27, 20, 51, 30, 2, 14, "* Menu *", 14);
	board.drawBoard(28, 21, 50, 29, 2);
	gotoxy(30, 23);
	cout << "_ So nguyen 8 byte";
	gotoxy(30, 25);
	cout << "_ So nguyen 16 byte";
	gotoxy(30, 27);
	cout << "_ So thuc 16 byte";
	gotoxy(21, 32);
	cout << "* Su dung phim mui ten de di chuyen";
	gotoxy(25, 33);
	cout << "* Su dung phim ENTER de chon";
}

// Thiết lập kiểu di chuyển trong board
int KeyboardMenu(int &i)
{
	char ch = _getch();
	if (ch == 13) return 1; // NÚT ENTER
	if (ch == -32)
	{
		ch = _getch();
		if (ch == 80) if (i < 27)i=i+2; else i = 23; // Xuống
		if (ch == 72) if (i > 23)i=i-2; else i = 27; // Lên
		gotoxy(30, i);
	}
	return 0;
}

// Xử lý các thao tác trong board
void XuLyBoardMenu()
{
	int i = 23;
	gotoxy(30, 23);
	do{
		int chon;
		do{
			chon = KeyboardMenu(i);
		} while (chon == 0);
		if (i == 23){
			SetConsoleTitle(TEXT("So Nguyen 8 byte"));
			BoardLuaChon(64);
		}
		else if (i == 25)
		{
			SetConsoleTitle(TEXT("So Nguyen 16 byte"));
			BoardLuaChon(128);
		}
		else
			BoardSoThuc();
	} while (1);
}

// Đóng gói các hàm ở trên vào một hàm duy nhất
void BoardMenu()
{
	system("cls");
	SetConsoleTitle(TEXT("Calculator X"));
	VeBoardMenu();
	XuLyBoardMenu();
}