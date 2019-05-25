#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
const int N = 20;
int main()
{
	double sx = 0, sy = 0, sxy = 0, sx2 = 0, a, b;
	double x[N];
	double k = 0.1;
	for (int i = 0; i < N; i++)
	{
		x[i] = k;
		k = k + 0.2;
	}
	double y[N] = {12.28, 12.53, 12.50, 12.50, 12.53, 12.75, 12.85, 12.77, 12.76,  12.73, 12.85, 12.51, 12.34, 12.22, 11.84, 11.67, 11.27, 11.06, 10.73, 10.35 };
	for (int i = 0; i < N; i++)
	{
		sx = sx + x[i];
		sy = sy + y[i];
		sxy = sxy + x[i] * y[i];
		sx2 = sx2 + x[i] * x[i];
	}

	a = (N*sxy - sx * sy) / (N*sx2 - sx * sx);
	b = (sy - a * sx) / N;

	cout << "a=" << a;
	cout << "\n";
	cout << "b=" << b;
	system("pause");
	return 0;
}
