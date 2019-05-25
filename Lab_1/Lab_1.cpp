/*
 * Code created by @shockbyte
 */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace  std;

double lab_fun(double a, double phi, double l)
{
	return  a * tan(phi) + l * sin(phi);
}

double d_lab_func(double a, double phi, double l)
{
	return a / pow(cos(phi), 2) + l * cos(phi);
}

double force(double c, double alpha, double rho, double v, double S)
{
	return  c * alpha * rho * pow(v, 2) * S;
}

struct DATA
{
	struct
	{
		double c;
		double d_c;
		double alpha;
		double d_alpha;
		double rho;
		double d_rho;
		double v;
		double d_v;
		double s;
		double d_s;
	} t_0;

	struct
	{
		double a;
		double d_a;

		double phi;
		double d_phi;

		double l;
		double d_l;

	} t_1[3];
};

DATA START_INFO = 
{
	{
		0.005,
		0.001,
		15,
		0.01,
		0.99,
		0.01,
		200,
		2,
		15,
		0.001
	},

	{
		// part 1
		{
			3.88,
			0.01,
			0.643,
			0.0005,
			0.8454,
			0.0002
		},

		//part 2

		{
			145.5,
			0.08,
			28.6,
			0.01,
			0.1736,
			0.0005
		},


		//part 3
		{
			27.3,
			0.04,
			1.73,
			0.03,
			0.93,
			0.01
		}
	}
};

void calc_t0()
{
	const double df = START_INFO.t_0.d_c + START_INFO.t_0.d_alpha + START_INFO.t_0.d_rho + START_INFO.t_0.d_v * 2;
	const double f = START_INFO.t_0.c * START_INFO.t_0.alpha + START_INFO.t_0.rho * pow(START_INFO.t_0.v, 2) * START_INFO.t_0.s;

	printf_s("F = %lf\r\n", f);
	printf_s("dF = %lf\r\n\r\n", df);
}

void calc_t1()
{
	for(int i = 0; i < 3; i++)
	{
		double f = lab_fun(START_INFO.t_1[i].a, START_INFO.t_1[i].phi, START_INFO.t_1[i].l);
		double df = lab_fun(
			START_INFO.t_1[i].a * START_INFO.t_1[i].d_a, 
			START_INFO.t_1[i].phi * START_INFO.t_1[i].d_phi, 
			START_INFO.t_1[i].l * START_INFO.t_1[i].d_l
		);

		double df2 = 
			START_INFO.t_1[i].a * START_INFO.t_1[i].d_a * df / f +
			START_INFO.t_1[i].phi * START_INFO.t_1[i].d_phi * df / f +
			START_INFO.t_1[i].l * START_INFO.t_1[i].d_l * df / f +

		printf_s("F[%d] = %lf\r\n", i, f);
		printf_s("dF[%d] = %lf\r\n", i, df);
		printf_s("aF[%i] = %lf\r\n----\r\n\r\n", i, f * df);
	}
}

int main(void)
{
	calc_t0();
	calc_t1();
}