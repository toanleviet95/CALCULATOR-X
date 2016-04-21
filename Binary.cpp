#include "CalculatorX.h"

// Cài đặt các hàm cho số BigInt và QFloat dưới dạng Binary:

// Chuyển 1 chuỗi Binary thành BigInt
void StrToBinBI(string Bin, BigInt &BI, int NumOfBit)
{
	int Pos = NumOfBit - 1; // bắt đầu set bit tại vị trí cuối cùng
	for (int i = Bin.length() - 1; i >= 0; i--){
		if (Bin[i] == '1')
			SetBitBI(BI, 1, Pos);
		else
			SetBitBI(BI, 0, Pos);
		Pos--;
	}
	BI.EndPos = Pos;
}

// Chuyển 1 chuỗi Binary thành QFloat
void StrToBinQF(string Bin, QFloat &QF)
{
	for (int i = 0; i < 128; i++)
	{
		if (Bin[i] == '1')
			SetBitQF(QF, 1, i);
		else
			SetBitQF(QF, 0, i);
	}
}

// Đổi 1 số BigInt dưới dạng Binary thành số thập phân
string BinToDec(BigInt BI, int NumOfBit)
{
	int Pos = NumOfBit - 1;
	string Result = "0";
	while (Pos > BI.EndPos)
	{
		bool aPos = GetBitBI(BI, Pos);
		string StraPos = to_string(aPos);
		string k = StrMulti(StraPos, Str2PowerX((NumOfBit - 1) - Pos));
		Result = StrAdd(Result, k);
		Pos--;
	}
	return Result;
}

// Đổi 1 số QFloat dưới dạng Binary thành số thực
string BinToFloat(QFloat QF)
{
	BigInt Mu;
	BigInt SoNguyen;
	string Result = "";
	string S = "";
	string E = "";
	string M = "";
	string Dau = "";
	string Nguyen = "";
	string ThapPhan = "";
	int SoMu = 0;
	bool Sbit = GetBitQF(QF, 0);
	int ViTriSo1 = 0;
	int ViTriDauCham = 0;
	int DoDaiThapPhan = 0;
	double TongThapPhan = 0;
	S = to_string(Sbit);
	for (int i = 1; i < 16; i++)
	{
		bool Ebit = GetBitQF(QF, i);
		E += to_string(Ebit);
	}
	for (int i = 16; i < 128; i++)
	{
		bool Mbit = GetBitQF(QF, i);
		M += to_string(Mbit);
	}
	if (E.find('1') == -1 && M.find('1') == -1)
	{
		Result = "0";
		return Result;
	}
	if (S == "1")
		Dau = "-";
	StrToBinBI(E, Mu, 15);
	E = BinToDec(Mu, 15);
	SoMu = stoi(E);
	SoMu -= QF.K;
	M.insert(0, "1");
	M.insert(SoMu + 1, ".");
	ViTriDauCham = M.find('.');
	ViTriSo1 = M.find('1', ViTriDauCham + 1);
	if (ViTriSo1 == -1)
	{
		Nguyen = M.substr(0, ViTriDauCham);
		StrToBinBI(Nguyen, SoNguyen, 128);
		Nguyen = BinToDec(SoNguyen, 128);
		ThapPhan = "";
	}
	else
	{
		M = M.substr(0, ViTriSo1 + 2);
		PartOfNumFloat(M, Nguyen, ThapPhan);
		DoDaiThapPhan = ThapPhan.length();
		ThapPhan = ThapPhan.substr(2, DoDaiThapPhan - 2);
		StrToBinBI(Nguyen, SoNguyen, 128);
		Nguyen = BinToDec(SoNguyen, 128);
		for (int i = 0; i < ThapPhan.length(); i++)
		{
			if (ThapPhan[i] == '1')
				TongThapPhan += pow(2, -(i + 1));
			else
				TongThapPhan += 0;
		}
			ThapPhan = to_string(TongThapPhan);
			ThapPhan = ThapPhan.substr(1, ThapPhan.length() - 1);
			int ViTriKhac0 = 0;
			for (int i = ThapPhan.length() - 1; i >= 0; i--)
			{
				if (ThapPhan[i] != '0')
				{
					ViTriKhac0 = i;
					break;
				}
			}
			ThapPhan = ThapPhan.substr(0, ViTriKhac0 + 1);
	}
	Result = Dau + Nguyen + ThapPhan;
	return Result;
}

// Đổi 1 số BigInt dưới dạng Bin thành số thập lục phân
string BinToHex(BigInt BI, int NumOfBit)
{
	string Bit = "";
	string Result = "";
	for (int i = 0; i < NumOfBit; i++)
		Bit += to_string(GetBitBI(BI, i));
	for (int i = 0; i < Bit.length(); i = i + 4){
		string FourBit = Bit.substr(i, 4);
		if (FourBit == "0000")
			Result += "0";
		else if (FourBit == "0001")
			Result += "1";
		else if (FourBit == "0010")
			Result += "2";
		else if (FourBit == "0011")
			Result += "3";
		else if (FourBit == "0100")
			Result += "4";
		else if (FourBit == "0101")
			Result += "5";
		else if (FourBit == "0110")
			Result += "6";
		else if (FourBit == "0111")
			Result += "7";
		else if (FourBit == "1000")
			Result += "8";
		else if (FourBit == "1001")
			Result += "9";
		else if (FourBit == "1010")
			Result += "A";
		else if (FourBit == "1011")
			Result += "B";
		else if (FourBit == "1100")
			Result += "C";
		else if (FourBit == "1101")
			Result += "D";
		else if (FourBit == "1110")
			Result += "E";
		else if (FourBit == "1111")
			Result += "F";
	}
	return Result;
}

// Nhập số BigInt dưới dạng Binary
void ScanBinaryBI(BigInt &BI, int NumOfBit)
{
	string Bin = "";
	bool Error = false;
	SetZeroAllBitBI(BI, NumOfBit);
	cin >> Bin;
	for (int i = 0; i < Bin.length(); i++){
		if (Bin[i] != '0' && Bin[i] != '1')
		{
			Error = true;
			break;
		}
	}
	if (Bin.length() > NumOfBit || Error){
		ClearAt(2, 4);
		ClearAt(2, 5);
		ClearAt(2, 6);
		ClearAt(2, 7);
		gotoxy(2, 4);
		cout << "So ban nhap vao khong phai la day nhi phan " << NumOfBit << " bit!";
		gotoxy(2, 5);
		system("pause");
		BoardNhiPhan(NumOfBit);
	}
	int OnPos;
	if (Bin.length() > 1){
		OnPos = Bin.find('1', 1);
		if (OnPos == -1)
			Bin = "0";
		else if (Bin[0] == '0')
			Bin = Bin.substr(OnPos, Bin.length() - OnPos);
	}
	StrToBinBI(Bin, BI, NumOfBit);
}

// Nhập số QFloat dưới dạng Binary
void ScanBinaryQF(QFloat &QF)
{
	BigInt Mu;
	string Bin = "";
	string S = "";
	string E = "";
	string M = "";
	string MU = "";
	int SoMu = 0;
	bool Error = false;
	SetZeroAllBitQF(QF);
	gotoxy(14, 12);
	cin >> S;
	gotoxy(14, 14);
	cin >> E;
	gotoxy(29, 16);
	cin >> M;
	if (E.find('1') == -1 && M.find('1') != -1)
		Error = true;
	if (E.find('0') == -1)
		Error = true;
	if (S.length() > 1 || E.length() > 15 || E.length() > 112)
		Error = true;
	if (M.length() < 112)
	{
		for (int i = M.length() - 1; i < 112; i++)
			M += "0";
	}
	Bin = S + E + M;
	for (int i = 0; i < Bin.length(); i++)
	{
		if (Bin[i] != '0' && Bin[i] != '1')
		{
			Error = true;
			break;
		}
	}
	StrToBinBI(E, Mu, 15);
	MU = BinToDec(Mu, 15);
	SoMu = stoi(MU);
	if (SoMu < QF.K)
		Error = true;
	if (Error)
	{
		gotoxy(2, 4);
		cout << "So ban nhap vao khong phai la day nhi phan 128 bit!";
		gotoxy(2, 5);
		system("pause");
		BoardSoThuc();
	}
	StrToBinQF(Bin, QF);
}

// Xuất chuỗi Binary cho BigInt
void PrintBinaryBI(BigInt BI, int NumOfBit)
{
	string Result = "";
	for (int i = 0; i < NumOfBit; i++)
		Result += to_string(GetBitBI(BI, i));
	cout << Result;
}

// Xuất chuỗi Binary cho QFloat
void PrintBinaryQF(QFloat QF)
{
	string Result = "";
	for (int i = 0; i < 128; i++)
		Result += to_string(GetBitQF(QF, i));
	cout << Result[0] << " ";
	for (int i = 1; i < 16; i++)
		cout << Result[i];
	cout << " ";
	for (int i = 16; i < 128; i++)
		cout << Result[i];
}

// Xuất chuỗi Hexa cho BigInt
void PrintHexa(BigInt BI, int NumOfBit)
{
	string Result = BinToHex(BI, NumOfBit);
	cout << Result << endl;
}