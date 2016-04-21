#include "CalculatorX.h"

// Cài đặt thuật toán cộng hai chuỗi số:

// Thêm số 0 để cân bằng số lượng phần tử cho hai số
void ThemSo0(int *&a, int *&b, int &m, int &n)
{
	if (m < n)
	for (int i = 1; i <= n - m; i++)
		a[m - 1 + i] = 0;
	else
	for (int i = 1; i <= m - n; i++)
		b[n - 1 + i] = 0;
	if (m < n)
		m = n;
	else
		n = m;
}

// Phép cộng có biến nhớ
void Cong(int *a, int *b, int *&c, int nho, int &m)
{
	for (int i = 0; i < m; i++)
	{
		c[i] = (a[i] + b[i] + nho) % 10;
		nho = (a[i] + b[i] + nho) / 10;
	}
	if (nho > 0)
		c[m++] = nho;
}

// Hàm cộng hai chuỗi số
string StrAdd(string A, string B)
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
	Cong(a, b, c, nho, m);
	for (int i = m - 1; i >= 0; i--){
		temp += to_string(c[i]);
	}
	return temp;
	delete a;
	delete b;
	delete c;
}