#include "CalculatorX.h"

// Cài đặt thuật toán chia hai chuỗi số:

// So sánh độ lớn của hai số chia và số bị chia
bool Sosanh(int *a, int *b, int n, int d)
{
	int i = 0;
	if ((a[d - 1] != 0) && (d>0))
		return true;
	for (i = 0; i < n; i++)
	if (a[i + d] > b[i])
		return true;
	else
	if (a[i + d] < b[i])
		return false;
	return true;
}

// Thao tác trừ khi chia
void Tru(int *&a, int *b, int n, int d)
{
	int i = 0, nho = 0;
	for (i = n - 1; i >= 0; i--)
	if (a[i + d] - nho < b[i])
	{
		a[i + d] = a[i + d] + 10 - nho - b[i];
		nho = 1;
	}
	else
	{
		a[i + d] = a[i + d] - nho - b[i];
		nho = 0;
	}
	if (nho == 1)
		a[d - 1]--;
}

// Kiểm tra trường hợp chia cho số 0
void Ktraso0(int *&a, int *&b, int &m, int &n, bool &duoc)
{
	duoc = true;
	int j = 0, k;
	while ((b[j] == 0) && (j<n))
		j++;
	if (j == n)
		duoc = false;
	else
	{
		for (k = j; k<n; k++)
			b[k - j] = b[k];
		n -= j;
	}
	j = 0;
	while ((a[j] == 0) && (j<m))
		j++;
	if (j == m)
	{
		m = 1; a[0] = 0;
	}
	else
	{
		for (k = j; k<m; k++)
			a[k - j] = a[k];
		m -= j;
	}
}

// Phép chia sử dụng thêm một mảng để chứa thương
void Chia(int *a, int *b, int *&c, int m, int n, int &Tam, int &d, int &i, int &t)
{
	if (m >= n)
	{
		if (!Sosanh(a, b, n, d))
			d++;
		while (d <= m - n)
		{
			Tam = 0;
			while (Sosanh(a, b, n, d))
			{
				Tam++;
				Tru(a, b, n, d);
			}
			c[t++] = Tam;
			d++;
			if (a[i] == 0)
				i++;
		}
		if (t == 0)
			c[t++] = 0;
	}
	else
		c[t++] = 0;
	while ((a[i] == 0) && (i<m))
		i++;
	if (i == m)
		a[--i] = 0;
}

// Hàm chia hai chuỗi số
string StrDiv(string A, string B)
{
	string temp = "";
	bool duoc = true;
	int d = 0, i = 0, t = 0, Tam = 0;
	int m = A.length();
	int n = B.length();
	int *a = new int[m];
	int *b = new int[n];
	int *c = new int[m];
	for (int i = 0; i < m; i++){
		string s = A.substr(i, 1);
		a[i] = stoi(s);
	}
	for (int i = 0; i < n; i++){
		string s = B.substr(i, 1);
		b[i] = stoi(s);
	}
	if (duoc){
		Chia(a, b, c, m, n, Tam, d, i, t);
		Tru(a, b, n, d);
		Ktraso0(a, b, m, n, duoc);
	}
	for (int i = 0; i < t; i++){
		temp += to_string(c[i]);
	}
	return temp;
	delete a;
	delete b;
	delete c;
}

// Hàm chia một chuỗi số cho 2
string StrDiv2(string X)
{
	string temp = "";
	bool duoc = true;
	int d = 0, i = 0, t = 0, Tam = 0;
	int m = X.length();
	int n = 1;
	int *a = new int[m];
	int *b = new int[n];
	int *c = new int[m];
	for (int i = 0; i < m; i++){
		string s = X.substr(i, 1);
		a[i] = stoi(s);
	}
	b[0] = 2;
	if (duoc){
		Chia(a, b, c, m, n, Tam, d, i, t);
		Tru(a, b, n, d);
		Ktraso0(a, b, m, n, duoc);
	}
	for (int i = 0; i < t; i++){
		temp += to_string(c[i]);
	}
	return temp;
	delete a;
	delete b;
	delete c;
}