#include <iostream>
using namespace std;
const int n = 8, m = 2;

int main()
{
	double a;
	cin >> a;
	double b[m][n];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];
	double R1[n - 1];
	for (int i = 1; i < n; i++)
		R1[i - 1] = (b[1][i] - b[1][i - 1]) / (b[0][i] - b[0][i - 1]);
	double R2[n - 2];
	for (int i = 1; i < n - 1; i++)
		R2[i - 1] = (R1[i] - R1[i - 1]) / (b[0][i + 1] - b[0][i - 1]);
	double R3[n - 3];
	for (int i = 1; i < n - 2; i++)
		R3[i - 1] = (R2[i] - R2[i - 1]) / (b[0][i + 2] - b[0][i - 1]);
	double R4[n - 4];
	for (int i = 1; i < n - 3; i++)
		R4[i - 1] = (R3[i] - R3[i - 1]) / (b[0][i + 3] - b[0][i - 1]);
	double R5[n - 5];
	for (int i = 1; i < n - 4; i++)
		R5[i - 1] = (R4[i] - R4[i - 1]) / (b[0][i + 4] - b[0][i - 1]);
	double R6[n - 6];
	for (int i = 1; i < n - 5; i++)
		R6[i - 1] = (R5[i] - R5[i - 1]) / (b[0][i + 5] - b[0][i - 1]);
	double R7 = (R6[1] - R6[0]) / (b[0][n - 1] - b[0][0]);
	double r[7] = { R1[0],R2[0],R3[0],R4[0],R5[0],R6[0],R7 };
	double p = 1;
	double k = b[1][0];
	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
			p = p * (a - b[0][j]);
		k = k + r[i - 1] * p;
		p = 1;
	}
	cout << k;
	system("pause");
	return 0;
}
