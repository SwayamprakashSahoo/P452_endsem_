#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double random(int N, int x);
int MLCG(int x, int a, int m);

void main()
{
	printf("_______________2D random walk for N=200 over 500 walks_________________\n");
	printf("Enter seed for random number generator :\n");
	int x = scanf("%d", &x);
	double Rms = random(200, x);
	printf("\n The rms value of distance over 500 walks is is %lf", Rms);
	printf("\n The sqrt value of the step count is %lf", sqrt(200));
}

int MLCG(int x, int a, int m)
{
	int xnew = (a * x) % m;
	return xnew;
}

double random(int N, int x)
{
	double X, Y;
	double R = 0;
	double rsum = 0, xsum = 0, ysum = 0;

	//generating random walk
	for (int i = 1; i <= 500; i++)
	{
		X = 0;
		Y = 0;
		int a = 572;
		int m = 16381;
		int temp = MLCG(x, a, m);
		for (int j = 1; j <= N; j++)
		{
			temp = MLCG(x, a, m);
			x = temp;
			//double random = ((double)temp / m);
			double random = ((double)temp / m) * 2 - 1;
			//double random = rand() / ((double)RAND_MAX);
			double num = (random * 22 * 2) / 7;
			X += cos(num);
			Y += sin(num);
		}
		double r = X * X + Y * Y;
		R = R + sqrt(r);
		rsum += (r);
		xsum += X;
		ysum += Y;
	}
	double Rrms = sqrt(rsum/500);
	return Rrms;
}

