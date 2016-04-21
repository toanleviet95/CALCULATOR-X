#include "CalculatorX.h"

// Cài đặt các hàm cho Board xử lý: Đổi từ số QFloat sang số Bin và từ số Bin sang số QFloat

// Vẽ board
void VeBoardSoThuc()
{
	cBoard board;
	system("Color 1F");
	resizeBuffer(79, 35);
	board.drawBoard(1, 2, 80, 9, 11, 14, "Ket qua:", 14);
	board.drawBoard(1, 11, 80, 18, 11, 14, "Nhap so:", 14);
	board.drawBoard(20, 20, 60, 36, 2, 14, "Chon thao tac", 14);
	gotoxy(22, 22);
	cout << "  Chuyen doi: ";
	gotoxy(28, 24);
	cout << "1. QFloat -> Bin";
	gotoxy(28, 26);
	cout << "2. Bin -> QFloat";
	gotoxy(28, 28);
	cout << "3. Thoat";
	gotoxy(22, 30);
	cout << "Nhap ma so thao tac can thuc hien: ";
	gotoxy(22, 32);
	cout << "Luu y: Chi nhap ma so tu 1 den 3";
	gotoxy(22, 34);
	cout << "Phai nhap dung so bit cua S, E, M";
}

// Nhập thao tác chuyển đổi 
void NhapThaoTacChuyenDoiQF(int &chon)
{
	do{
		gotoxy(57, 30);
		cin >> chon;
		if (chon < 1 || chon > 2){
			gotoxy(57, 30);
			cout << " ";
		}
		if (chon == 3)
			BoardMenu();
	} while (chon < 1 || chon > 3);
}

// Nhập dãy nhị phân
void NhapDayNhiPhan(QFloat &QF)
{
	cBoard board;
	ClearAt(2, 4);
	ClearAt(2, 5);
	ClearAt(2, 6);
	ClearAt(2, 12);
	ClearAt(2, 13);
	ClearAt(2, 14);
	ClearAt(2, 16);
	ClearAt(2, 17);
	board.drawBoard(1, 11, 80, 18, 11, 14, "Nhap so:", 14);
	board.drawBoard(1, 2, 80, 9, 11, 14, "Ket qua:", 14);
	gotoxy(2, 12);
	cout << "S (1 bit): ";
	gotoxy(2, 14);
	cout << "E (15 bit): ";
	gotoxy(2, 16);
	cout << "M (Trong pham vi 112 bit): ";
	ScanBinaryQF(QF);
}

// Nhập số thực QFloat
void NhapSoThuc(QFloat &QF)
{
	cBoard board;
	ClearAt(2, 4);
	ClearAt(2, 5);
	ClearAt(2, 6);
	ClearAt(2, 12);
	ClearAt(2, 13);
	ClearAt(2, 14);
	ClearAt(2, 16);
	ClearAt(2, 17);
	board.drawBoard(1, 11, 80, 18, 11, 14, "Nhap so:", 14);
	board.drawBoard(1, 2, 80, 9, 11, 14, "Ket qua:", 14);
	gotoxy(2, 13);
	ScanQFloat(QF);
}

// Xuất ra dãy nhị phân
void XuatDayNhiPhan(QFloat QF)
{
	gotoxy(2, 4);
	cout << "Bin 128 bit: ";
	gotoxy(2, 5);
	PrintBinaryQF(QF);
}

// Xuất ra số thực
void XuatSoThuc(QFloat QF)
{
	gotoxy(2, 4);
	cout << "QFloat 16 byte: ";
	gotoxy(2, 5);
	PrintQFloat(QF);
}

// Xử lý công việc chuyển đổi
void XuLyBoardSoThuc()
{
	QFloat QF;
	int chon = 0;
	cBoard board;
	NhapThaoTacChuyenDoiQF(chon);
	do{
		gotoxy(57, 30);
		cout << " ";
		if (chon == 1){
			NhapSoThuc(QF);
			XuatDayNhiPhan(QF);
			NhapThaoTacChuyenDoiQF(chon);
		}
		else if (chon == 2){
			NhapDayNhiPhan(QF);
			XuatSoThuc(QF);
			NhapThaoTacChuyenDoiQF(chon);
		}
	} while (chon);
}

// Đóng gói các hàm ở trên vào một hàm duy nhất
void BoardSoThuc()
{
	system("cls");
	SetConsoleTitle(TEXT("So thuc 16 byte"));
	VeBoardSoThuc();
	XuLyBoardSoThuc();
}