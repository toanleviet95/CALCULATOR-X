#include "CalculatorX.h"

// Cài đặt các hàm đồ họa cho chương trình:

// Đi đến một tọa độ nào đó
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Màu chữ
void textcolor(WORD color)
{
	HANDLE hConsoleOutput;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
	GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
	WORD wAttributes = screen_buffer_info.wAttributes;
	color &= 0x000f;
	wAttributes &= 0xfff0;
	wAttributes |= color;
	SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}

// Vẽ 1 kí tự tại 1 điểm với màu sắc cho trước
void multiPut(int x, int y, char c, int color)
{
	gotoxy(x, y);
	textcolor(color);
	printf("%c", c);
	gotoxy(40, 20);
}

// Chỉnh lại vùng đệm và kích thước cho cửa sổ Console
void resizeBuffer(int width, int height)
{
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0, 0, width, height };
	COORD bufferSize = { width + 1, height + 1 };
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	SetConsoleScreenBufferSize(wHnd, bufferSize);
}

// In LOGO chương trình khi mới bắt đầu khởi động
void Logo()
{
	char c = 0;
	int i = 1;
	gotoxy(18, i);
	ifstream in("Logo.in");
		do{
			in >> c;
			cout << c;
			if (c == ')'){
				i++;
				gotoxy(18, i);
			}
			Sleep(1);
		} while (c != ']');
	cout << endl << endl;
}

// Xóa một dòng nào đó tại vị trí cho trước
void ClearAt(int x, int y)
{
	gotoxy(x, y);
	cout << "                                                                              ";
}

// Xóa một dòng trong khung Menu tại vị trí cho trước
void ClearMenuAt(int x, int y)
{
	gotoxy(x, y);
	cout << "                                  ";
}