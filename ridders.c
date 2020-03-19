#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

#define EQUATION(middle) (middle) * (middle) * sin(middle) - 5 * (middle) + 7

typedef double (*f_sign)(double x);

double ridders(double lbrace , double rbrace , f_sign f);
double fsgn(double x);

int main()
{
	f_sign f = fsgn;
	double res = ridders(-3 , 3 , f);
	printf("%f\n" , res);
	return 0;
}

double ridders(double lbrace , double rbrace , f_sign f)
{
	double xmid , fr , fl , fm , xnew;
	xnew = -3;
	while (fabs(EQUATION(xnew)) > 0.00001)
	{
		xmid = lbrace + (rbrace - lbrace) / 2;
		fr = EQUATION(rbrace);
		fl = EQUATION(lbrace);
		fm = EQUATION(xmid);
		xnew = xmid + (xmid - lbrace) * f(fl - fr) * fm / sqrt(fm * fm - fl * fr);
		if (EQUATION(xnew) > 0)
			rbrace = xnew;
		else
			lbrace = xnew;
	};
	return xnew;
};

double fsgn(double x)
{
	if (x < 0)
		return -1;
	else 
		return 1;
};
