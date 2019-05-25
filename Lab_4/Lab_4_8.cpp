
#include <iostream>

using namespace std;
int main()
{
	double  fleft, fright, x, x1, fcentral, h, h1, f2;
	cout << ("x->");
	cin >> x;
	cout << ("\n");
	h = 12;
	h1 = 0.5;
	fleft = log(log(log(x * x))) - log(log(log(pow(x - h, 2)))) / h;
	fright = log(log(log(pow(x + h, 2)))) - log(log(log(pow(x, 2)))) / h;
	fcentral = log(log(log(pow(x + h, 2)))) - log(log(log(pow(x - h, 2)))) /  2 * h;
	f2 = (log(log(log(pow(x - h, 2)))) + 2 * log(log(log(pow(x, 2)))) + log(log(log(pow(x + h, 2))))) / pow(h, 2);
	cout << "fleft=" << fleft << "\n";
	cout << "fright=" << fright << "\n";
	cout << "fcentral=" << fcentral << "\n";
	cout << "f2=" << f2 << "\n";
	cout << ("x1->\n");
	cin >> x1;
	cout << ("\n");
	fleft = log(log(log(x * x))) - log(log(log(pow(x - h1, 2)))) / h1;
	fright = log(log(log(pow(x + h1, 2)))) - log(log(log(pow(x, 2)))) / h1;
	fcentral = log(log(log(pow(x + h1, 2)))) - log(log(log(pow(x - h1, 2)))) / 2 * h1;
	f2 = (log(log(log(pow(x - h, 2)))) + 2 * log(log(log(pow(x, 2)))) + log(log(log(pow(x + h, 2))))) / pow(h, 2);
	cout << "fleft=" << fleft << "\n";
	cout << "fright=" << fright << "\n";
	cout << "fcentral=" << fcentral << "\n";
	cout << "f2=" << f2 << "\n";
	double X[37];
	double Y[37];
	for (int i = 0; i < 37; i++)
	{
		X[i] = 1 + h1 * i;
		Y[i] = log(abs(log(abs(log(X[i] * X[i])))));
	}
	double I, s1 = 0, s2 = 0;
	for (int i = 1; i < 36; i++)
	{
		if (i % 2 == 0)
		{
			s1 = s1 + Y[i];
		}
		else
		{
			s2 = s2 + Y[i];
		}
	}
	I = h1 / 3 * (Y[0] + 2 * s1 + 4 * s2 + Y[36]);
	cout << "I=" << I << "\n";
	system("pause");
	return 0;
}
