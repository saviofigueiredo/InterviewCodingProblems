#include <iostream>

void compress(char s[])
{
	int posToFill = 0;

	for (int i = 0; s[i] != '\0'; ++i)
	{
		int count = 0;
		char c = s[i];

		while (s[i + count] == c)
		{
			++count;
		}

		s[posToFill] = c;

		if (count > 1)
		{
			auto r = 10;
			while (r <= count)
			{
				r *= 10;
			}

			while (r > 1)
			{
				auto d = r / 10;
				s[++posToFill] = '0' + count%r / d;
				r /= 10;
			}
		}
		posToFill += 1;
		i += count - 1;
	}

	s[posToFill] = '\0';
}

int main(int argc, char* argv[])
{
	char anyString[] = "aaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcddeeeeffff";

	std::cout << anyString << std::endl;

	compress(anyString);

	std::cout << anyString << std::endl;

	return EXIT_SUCCESS;
}