#include "CalculatorX.h"

// Cài đặt các hàm cho số QFloat:

// Tách 1 chuỗi số thực ra phần nguyên và phần thập phân
void PartOfNumFloat(string Float, string &Nguyen, string &ThapPhan)
{
	int ViTriDauCham = Float.find('.');
	if (ViTriDauCham != -1)
	{
		Nguyen = Float.substr(0, ViTriDauCham);
		ThapPhan = Float.substr(ViTriDauCham + 1, Float.length() - 1 - ViTriDauCham);
		ThapPhan.insert(0, "0.");
	}
	else
	{
		Nguyen = Float;
		ThapPhan = "0";
	}
}

// Chuyển 1 chuỗi số thực thành kiểu QFloat
void StrToQFloat(string Float, QFloat &QF)
{
	BigInt SoNguyen;
	BigInt SoMu;
	string Nguyen = "";
	string ThapPhan = "";
	string BinNguyen = "";
	string BinThapPhan = "";
	string Exponent = "";
	string S = "0";
	string E = "";
	string M = "";
	string Bin = "";
	string SEM = "";
	double SoThapPhan = 0;
	int ViTriDauCham = 0;
	int DoDaiM = 0;
	PartOfNumFloat(Float, Nguyen, ThapPhan);
	if (Float.find('-') != -1)
	{
		Nguyen = Nguyen.substr(1, Nguyen.length() - 1);
		S = "1";
	}
	StrToBigInt(Nguyen, SoNguyen, 128);
	for (int i = SoNguyen.EndPos + 1; i < 128; i++)
		BinNguyen += to_string(GetBitBI(SoNguyen, i));
	SoThapPhan = stod(ThapPhan);
	if (SoThapPhan == 0)
		Bin = BinNguyen;
	else
	{
		do
		{
			if (BinThapPhan.length() == 15)
				break;
			SoThapPhan *= 2;
			if (SoThapPhan >= 1)
			{
				BinThapPhan += "1";
				SoThapPhan -= 1;
			}
			else if (SoThapPhan > 0)
			{
				BinThapPhan += "0";
			}
		} while (SoThapPhan != 0);
		Bin = BinNguyen + BinThapPhan;
	}
	if (Bin.find('1') == -1)
	{
		S = "0";
		for (int i = 0; i < 15; i++)
			E += "0";
		for (int i = 0; i < 112; i++)
			M += "0";
	}
	else
	{
		int FirstOne = Bin.find('1');
		QF.K += BinNguyen.length() - FirstOne - 1;
		Exponent = to_string(QF.K);
		StrToBigInt(Exponent, SoMu, 15);
		for (int i = SoMu.EndPos + 1; i < 15; i++)
			E += to_string(GetBitBI(SoMu, i));
		if (E.length() < 15)
		{
			for (int i = 0; i < 15 - E.length(); i++)
				E.insert(0, "0");
		}
		M = Bin.substr(FirstOne + 1, Bin.length() - FirstOne - 1);
		DoDaiM = M.length();
		for (int i = 0; i < 112 - DoDaiM; i++)
			M += "0";
	}
	SEM = S + E + M;
	SetZeroAllBitQF(QF);
	StrToBinQF(SEM, QF);
}

// Nhập số QFloat
void ScanQFloat(QFloat &QF)
{
	string Float = "";
	bool Error = false;
	cin >> Float;
	if (Float.length() > 1 && Float[0] == '0')
		Error = true;
	for (int i = 0; i < Float.length(); i++)
	{
		if ((Float[i] > '9' || Float[i] < '0') && Float[i] != '-' && Float[i] != '.'){
			Error = true;
			break;
		}
	}
	if (Error)
	{
		gotoxy(2, 4);
		cout << "So ban nhap khong phai la mot so thuc 16 byte!";
		gotoxy(2, 5);
		system("pause");
		BoardSoThuc();
	}
	StrToQFloat(Float, QF);
}

// In ra số QFloat dưới dạng số thực
void PrintQFloat(QFloat QF)
{
	string Result = BinToFloat(QF);
	cout << Result;
}