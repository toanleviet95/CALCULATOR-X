#include "CalculatorX.h"

// Cài đặt các hàm cho Board xử lý: Tính toán cho số BigInt và đổi số BigInt từ số Dec sang số Bin và Hex 

// Vẽ board
void VeBoardSoNguyen()
{
	cBoard board;
	system("Color 1F");
	resizeBuffer(79, 35);
	board.drawBoard(1, 2, 80, 9, 11, 14, "Ket qua:", 14);
	board.drawBoard(1, 11, 80, 15, 8, 14, "Nhap so nguyen:", 14);
	board.drawBoard(20, 17, 60, 33, 2, 14, "Chon thao tac", 14);
	gotoxy(22, 19);
	cout << "  Chuyen doi sang he so: ";
	gotoxy(28, 21);
	cout << "1. Bin	    2. Hex";
	gotoxy(22, 25);
	cout << "  Lam phep tinh: ";
	gotoxy(28, 27);
	cout << "1. Cong          3. Nhan";
	gotoxy(28, 28);
	cout << "2. Tru           4. Chia";
	gotoxy(22, 30);
	cout << "*Su dung phim mui ten de di chuyen";
	gotoxy(26, 31);
	cout << "*Su dung phim ENTER de chon";
}

// Thiết lập kiểu di chuyển trong board
int KeyboardSoNguyen(int &i, int NumOfBit)
{
	char ch = _getch();
	if (ch == 27) exit(0);  // NÚT ESC
	if (ch == 13) return 1; // NÚT ENTER
	if (ch == -32)
	{
		ch = _getch();
		if (ch == 80) if (i < 25)i = i + 6; else i = 19; // Xuống
		if (ch == 72) if (i > 19)i = i - 6; else i = 25; // Lên
		gotoxy(22, i);
	}
	return 0;
}

// Nhập số nguyên
void NhapSoNguyen(BigInt &BI, int NumOfBit)
{
	gotoxy(2, 13);
	ScanBigInt(BI, NumOfBit);
}

// Xuất số nguyên
void XuatSoNguyen(BigInt BI, int NumOfBit)
{
	ClearAt(2, 13);
	gotoxy(2, 4);
	PrintBigInt(BI, NumOfBit);
}

// Nhập thao tác chuyển đổi cho số nguyên
void NhapThaoTacChuyenDoiBI(int &chon)
{
	ClearMenuAt(22, 25);
	ClearMenuAt(22, 27);
	ClearMenuAt(22, 28);
	ClearMenuAt(22, 30);
	ClearMenuAt(26, 31);
	gotoxy(22, 26);
	cout << "Luu y: Chi nhap ma so tu 1 den 3";
	gotoxy(32, 23);
	cout << "3. Tro ve Menu";
	gotoxy(22, 24);
	cout << "Nhap ma so thao tac can thuc hien: ";
	do{
		gotoxy(57, 24);
		cin >> chon;
		if (chon >= 1 && chon <= 2){
			gotoxy(57, 24);
			cout << " ";
		}
		if (chon == 3)
			BoardMenu();
	} while (chon < 1 || chon > 3);
}

// Xử lý công việc chuyển đổi sang Bin hoặc Hex
void XuLyChuyenDoi(BigInt BI, int NumOfBit)
{
	int chon = 0;
	cBoard board;
	NhapThaoTacChuyenDoiBI(chon);
	do{
		gotoxy(57, 24);
		cout << " ";
		if (chon == 1){
			gotoxy(2, 6);
			cout << "Bin " << NumOfBit << " bit: ";
			gotoxy(2, 7);
			PrintBinaryBI(BI, NumOfBit);
			NhapSoNguyen(BI, NumOfBit);
			ClearAt(2, 4);
			ClearAt(2, 6);
			ClearAt(2, 7);
			ClearAt(2, 8);
			board.drawBoard(1, 2, 80, 9, 11, 14, "Ket qua:", 14);
			XuatSoNguyen(BI, NumOfBit);
			NhapThaoTacChuyenDoiBI(chon);
		}
		else if (chon == 2){
			gotoxy(2, 6);
			cout << "Hex " << NumOfBit << " bit: ";
			gotoxy(2, 7);
			PrintHexa(BI, NumOfBit);
			NhapSoNguyen(BI, NumOfBit);
			ClearAt(2, 4);
			ClearAt(2, 6);
			ClearAt(2, 7);
			ClearAt(2, 8);
			board.drawBoard(1, 2, 80, 9, 11, 14, "Ket qua:", 14);
			XuatSoNguyen(BI, NumOfBit);
			NhapThaoTacChuyenDoiBI(chon);
		}
	} while (chon);
}

// Nhập thao tác phép tính cần thực hiện
void NhapThaoTacPhepTinh(int &chon)
{
	ClearMenuAt(22, 19);
	ClearMenuAt(22, 21);
	ClearMenuAt(22, 25);
	ClearMenuAt(22, 27);
	ClearMenuAt(22, 28);
	ClearMenuAt(22, 30);
	ClearMenuAt(26, 31);
	gotoxy(22, 19);
	cout << "  Lam phep tinh: ";
	gotoxy(28, 21);
	cout << "1. Cong          3. Nhan";
	gotoxy(28, 22);
	cout << "2. Tru           4. Chia";
	gotoxy(32, 23);
	cout << "5. Tro ve Menu";
	gotoxy(22, 26);
	cout << "Luu y: Chi nhap ma so tu 1 den 5";
	gotoxy(22, 24);
	cout << "Nhap ma so thao tac can thuc hien: ";
	do{
		gotoxy(57, 24);
		cin >> chon;
		if (chon > 4 || chon < 1){
			gotoxy(57, 24);
			cout << " ";
		}
		if (chon == 5)
			BoardMenu();
	} while (chon > 5 || chon < 1);
}

// Kiểm tra kết quả phép tính có vượt ngưỡng giới hạn của BigInt hay không
void KiemTraKetQuaPhepTinh(string Result, int NumOfBit, bool &Error)
{
	if (Result.find('-') != -1){
		ClearAt(2, 4);
		ClearAt(2, 6);
		ClearAt(2, 7);
		gotoxy(2, 4);
		cout << "Chuong trinh khong thuc hien duoc voi so am! Thoat chuong trinh! ";
		gotoxy(2, 6);
		system("pause");
		exit(0);
	}
	if (NumOfBit == 64){
		if (Result.length() > 20){
			Error = true;
			ClearAt(2, 4);
			ClearAt(2, 6);
			ClearAt(2, 7);
			gotoxy(2, 4);
			cout << "Ket qua tinh da vuot qua gioi han cua so nguyen 8 byte!";
			gotoxy(2, 6);
			system("pause");
			BoardSoNguyen(NumOfBit);
		}
	}
	else{
		if (Result.length() > 38){
			Error = true;
			ClearAt(2, 4);
			ClearAt(2, 6);
			ClearAt(2, 7);
			gotoxy(2, 4);
			cout << "Ket qua tinh da vuot qua gioi han cua so nguyen 16 byte!";
			gotoxy(2, 6);
			system("pause");
			BoardSoNguyen(NumOfBit);
		}
	}
}

// Xử lý công việc tính toán +, -, x, : cho số nguyên
void XuLyPhepTinh(BigInt BI, int NumOfBit)
{
	int chon = 0;
	NhapThaoTacPhepTinh(chon);
	do{
		BigInt BI1;
		string Result;
		bool Error = false;
		ClearAt(2, 4);
		ClearAt(2, 6);
		ClearAt(2, 7);
		XuatSoNguyen(BI, NumOfBit);
		gotoxy(57, 24);
		cout << " ";
		if (chon == 1)
		{
			gotoxy(2, 6);
			cout << "+";
			NhapSoNguyen(BI1, NumOfBit);
			ClearAt(2, 13);
			gotoxy(4, 6);
			PrintBigInt(BI1, NumOfBit);
			Result = BigIntAdd(BI, BI1, NumOfBit);
			KiemTraKetQuaPhepTinh(Result, NumOfBit, Error);
			if (Error == false){
				gotoxy(2, 7);
				cout << "= " << Result;
				StrToBigInt(Result, BI, NumOfBit);
				NhapThaoTacPhepTinh(chon);
			}
		}
		else if (chon == 2)
		{
			gotoxy(2, 6);
			cout << "-";
			NhapSoNguyen(BI1, NumOfBit);
			ClearAt(2, 13);
			gotoxy(4, 6);
			PrintBigInt(BI1, NumOfBit);
			gotoxy(2, 7);
			Result = BigIntSub(BI, BI1, NumOfBit);
			KiemTraKetQuaPhepTinh(Result, NumOfBit, Error);
			if (Error == false){
				gotoxy(2, 7);
				cout << "= " << Result;
				StrToBigInt(Result, BI, NumOfBit);
				NhapThaoTacPhepTinh(chon);
			}
		}
		else if (chon == 3)
		{
			gotoxy(2, 6);
			cout << "X";
			NhapSoNguyen(BI1, NumOfBit);
			ClearAt(2, 13);
			gotoxy(4, 6);
			PrintBigInt(BI1, NumOfBit);
			gotoxy(2, 7);
			Result = BigIntMulti(BI, BI1, NumOfBit);
			KiemTraKetQuaPhepTinh(Result, NumOfBit, Error);
			if (Error == false){
				gotoxy(2, 7);
				cout << "= " << Result;
				StrToBigInt(Result, BI, NumOfBit);
				NhapThaoTacPhepTinh(chon);
			}
		}
		else if (chon == 4)
		{
			gotoxy(2, 6);
			cout << ":";
			NhapSoNguyen(BI1, NumOfBit);
			ClearAt(2, 13);
			gotoxy(4, 6);
			PrintBigInt(BI1, NumOfBit);
			if (BinToDec(BI1, NumOfBit) == "0")
			{
				gotoxy(2, 7);
				cout << "Math Error. Khong thuc hien duoc phep chia cho 0!";
				NhapThaoTacPhepTinh(chon);
			}
			else
			{
				gotoxy(2, 7);
				Result = BigIntDiv(BI, BI1, NumOfBit);
				KiemTraKetQuaPhepTinh(Result, NumOfBit, Error);
				if (Error == false){
					gotoxy(2, 7);
					cout << "= " << Result;
					StrToBigInt(Result, BI, NumOfBit);
					NhapThaoTacPhepTinh(chon);
				}
			}
		}
	} while (chon);
}

// Xử lý các thao tác trong board
void XuLyBoardSoNguyen(int NumOfBit)
{
	BigInt BI;
	NhapSoNguyen(BI, NumOfBit);
	XuatSoNguyen(BI, NumOfBit);
	int i = 19;
	gotoxy(22, 19);
	do{
		int chon;
		do{
			chon = KeyboardSoNguyen(i, NumOfBit);
		} while (chon == 0);
		if (i == 19)
			XuLyChuyenDoi(BI, NumOfBit);
		else if (i == 25)
			XuLyPhepTinh(BI, NumOfBit);
	} while (1);
}

// Đóng gói các hàm ở trên vào một hàm duy nhất
void BoardSoNguyen(int NumOfBit)
{
	system("cls");
	if (NumOfBit == 64)
		SetConsoleTitle(TEXT("So nguyen 8 byte"));
	else
		SetConsoleTitle(TEXT("So nguyen 16 byte"));
	VeBoardSoNguyen();
	XuLyBoardSoNguyen(NumOfBit);
}

