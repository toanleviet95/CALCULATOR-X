#include "CalculatorX.h"

// Cài đặt thuật toán trừ hai chuỗi số:

// Dùng lại hàm thêm số 0 của phép cộng
void ThemSo0(int *&a, int *&b, int &m, int &n);

// So sánh hai số trước khi trừ
bool SoSanh(int *a, int *b, int m)
{
	int i = m - 1;
	while ((a[i] == b[i]) && (i >= 0))
		i--;
	if ((i<0) || (a[i]>b[i]))
		return true;
	else
		return false;
}

// Hoán vị hai số nếu số đầu nhỏ hơn số sau
void HoanVi(int *&a, int *&b, int m, int n, string &temp)
{
	if (!SoSanh(a, b, m))
	{
		temp += "-";
		for (int i = 0; i < n; i++)
		{
			int tam = a[i];
			a[i] = b[i];
			b[i] = tam;
		}
	}
}

// Phép trừ có biến nhớ
void Tru(int *a, int *b, int *&c, int nho, int &m)
{
	for (int i = 0; i < m; i++){
		if (a[i] - nho >= b[i])
		{
			c[i] = (a[i] - b[i] - nho) % 10;
			nho = 0;
		}
		else
		{
			c[i] = (a[i] + 10 - b[i] - nho) % 10;
			nho = 1;
		}
	}
	while (c[m - 1] == 0)
		m--;
	if (m == 0)c[m++] = 0;
}

// Hàm trừ hai chuỗi số
string StrSub(string A, string B)
{
	string temp = "";
	int m = A.length();
	int n = B.length();
	int nho = 0;
	int *a = new int[50];
	int *b = new int[50];
	int *c = new int[50];
	for (int i = 0; i < m; i++){
		string s = A.substr(m - 1 - i, 1);
		a[i] = stoi(s);
	}
	for (int i = 0; i < n; i++){
		string s = B.substr(n - 1 - i, 1);
		b[i] = stoi(s);
	}
	ThemSo0(a, b, m, n);
	HoanVi(a, b, m, n, temp);
	Tru(a, b, c, nho, m);
	for (int i = m - 1; i >= 0; i--){
		temp += to_string(c[i]);
	}
	return temp;
	delete a;
	delete b;
	delete c;
}