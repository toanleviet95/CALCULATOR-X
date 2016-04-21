#include "CalculatorX.h"

// Cài đặt thuật toán nhân hai chuỗi số:

// Thêm số 0 để cân bằng số lượng phần tử cho hai số
void ThemSo0(int *&a, int *&b, int m, int n, int chdaichung)
{
	for (int i = m; i < chdaichung; i++)
		a[i] = 0;
	for (int i = n; i < chdaichung; i++)
		b[i] = 0;
}

// Phép nhân có biến nhớ
void Nhan(int *a, int *b, int *&c, int m, int n, int &chdaichung, int nho)
{
	for (int i = 0; i < chdaichung; i++)
	{
		int s = 0;
		for (int j = 0; j <= i; j++)
			s += a[j] * b[i - j];
		c[i] = (s + nho) % 10;
		nho = (s + nho) / 10;
	}
	if (nho > 0)
		c[chdaichung++] = nho;
}

// Hàm nhân hai chuỗi số
string StrMulti(string A, string B)
{
	string temp = "";
	int m = A.length();
	int n = B.length();
	int nho = 0;
	int chdaichung = m + n - 1;
	int *a = new int[chdaichung];
	int *b = new int[chdaichung];
	int *c = new int[50];
	for (int i = 0; i < m; i++){
		string s = A.substr(m - 1 - i, 1);
		a[i] = stoi(s);
	}
	for (int i = 0; i < n; i++){
		string s = B.substr(n - 1 - i, 1);
		b[i] = stoi(s);
	}
	ThemSo0(a, b, m, n, chdaichung);
	Nhan(a, b, c, m, n, chdaichung, nho);
	for (int i = chdaichung - 1; i >= 0; i--){
		temp += to_string(c[i]);
	}
	return temp;
	delete a;
	delete b;
	delete c;
}

// Hàm 2^x 
string Str2PowerX(int X)
{
	string temp = "1";
	for (int i = 0; i < X; i++){
		temp = StrMulti(temp, "2");
	}
	return temp;
}