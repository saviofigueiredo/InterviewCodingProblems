#include <iostream>
#include <math.h>

double f(double x)
{
	return -pow(x, 3) + 2 * pow(x, 2) + x - 1;
}

float bisseccao(double a, double b, double rodadas, double margemErro)
{
	double meio = a + (b - a) / 2;

	double fa = f(a);
	double fb = f(b);

	if (fa*fb > 0)
	{
		std::cout << "A multiplicacao de f de a por f de b é maior que zero" << std::endl;
		throw;
	}

	double fMeio = f(meio);

	if (fMeio == 0 || rodadas == 0 || (b - a) / 2 < margemErro)
	{
		return meio;
	}
	else if (fa*fMeio < 0)
	{
		return bisseccao(a, meio, rodadas - 1, margemErro);
	}
	else
	{
		return bisseccao(b, meio, rodadas - 1, margemErro);
	}
}

int main()
{
	std::cout << bisseccao(0.1, 1, 100, 0.00001);
}