#include <iostream>

void removeCharICharA(char* s)
{
	int i, posToFill;
	for (i = 0, posToFill = 0; s[i] != '\0'; ++i, ++posToFill)
	{
		while ((s[i] == 'I' || s[i] == 'A') && s[i] != '\0')
		{
			++i;
		}

		if (s[i] != '\0' && i != posToFill)
		{
			s[posToFill] = s[i];
		}

		if (s[i] == '\0')
		{
			--i;
		}
	}

	s[posToFill] = '\0';
}

int main()
{
	char s[] = "AMAZONIA";

	removeCharICharA(s);

	std::cout << s << std::endl;
}