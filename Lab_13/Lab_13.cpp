#include <iostream>
#include <cmath>

using namespace std;
int main()
{
	double h = 0.1, n = 40, a = 0;
	double x[50], y1[50], y2[50], y3[50];
	x[0] = a;
	y1[0] = 0.2;
	y2[0] = 0;
	y3[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		x[i] = a + i * h;
		y1[i] =y1[i - 1] + h * (y1[i - 1] +  y2[i - 1] * y3[i - 1]);
		y2[i] = y2[i - 1] + h * (y1[i - 1] * y2[i - 1] * y3[i - 1] + y1[i - 1] * y1[i - 1]);
		y3[i] = y3[i - 1] + h * (x[i] * y1[i - 1] + y2[i - 1] - y3[i - 1] * y3[i - 1]);
	}

	for (int i = 0; i <= n; i++)
	{
		cout << x[i] << " " << y1[i] << " " << y2[i] << " " << y3[i] << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
