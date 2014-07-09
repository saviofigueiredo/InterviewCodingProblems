/*
The method is applicable for solving the equation f(x) = 0 for the real variable x, where f is a continuous function defined on an interval [a, b] and f(a) and f(b) have opposite signs.
In this case a and b are said to bracket a root since, by the intermediate value theorem, the continuous function f must have at least one root in the interval (a, b).
At each step the method divides the interval in two by computing the midpoint c = (a+b) / 2 of the interval and the value of the function f(c) at that point.
Unless c is itself a root (which is very unlikely, but possible) there are now two possibilities: either f(a) and f(c) have opposite signs and bracket a root,
or f(c) and f(b) have opposite signs and bracket a root. The method selects the subinterval that is a bracket as a new interval to be used in the next step.
In this way the interval that contains a zero of f is reduced in width by 50% at each step. The process is continued until the interval is sufficiently small.
Explicitly, if f(a) and f(c) are opposite signs, then the method sets c as the new value for b, and if f(b) and f(c) are opposite signs then the method sets c as the new a.
(If f(c)=0 then c may be taken as the solution and the process stops.) In both cases, the new f(a) and f(b) have opposite signs, so the method is applicable to this smaller interval
*/
#include <iostream>
#include <math.h>

// Any function, just to test the method.
double f(double x)
{
	return -pow(x, 3) + 2 * pow(x, 2) + x - 1;
}

double bissection(double a, double b, double numberOfExecutions, double errorTolerance)
{
	double middle = a + (b - a) / 2;

	double fa = f(a);
	double fb = f(b);

	if (fa*fb > 0)
	{
		std::cout << "A multiplicacao de f de a por f de b é maior que zero" << std::endl;
		throw;
	}

	double fMiddle = f(middle);

	if (fMiddle == 0 || numberOfExecutions == 0 || (b - a) / 2 < errorTolerance)
	{
		return middle;
	}
	else if (fa*fMiddle < 0)
	{
		return bissection(a, middle, numberOfExecutions - 1, errorTolerance);
	}
	else
	{
		return bissection(b, middle, numberOfExecutions - 1, errorTolerance);
	}
}

int main(int argc, char* argv[])
{
	std::cout << bissection(0.1, 1, 100, 0.00001);

	return EXIT_SUCCESS;
}