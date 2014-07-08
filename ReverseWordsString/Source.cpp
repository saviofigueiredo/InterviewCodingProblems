#include <iostream>
#include <string>

void reverse(std::string& s)
{
	for (auto i = 0; i < s.length()/2; ++i)
	{
		auto temp = s[i];
		s[i] = s[s.length() - i - 1];
		s[s.length() - i - 1] = temp;
	}

	for (int posInicio = 0, i = 0; i < s.length(); ++i)
	{
		while (i < s.length() && s[i] == ' ')
		{
			++i;
		}

		posInicio = i;

		while (i < s.length() && s[i] != ' ')
		{
			++i;
		}

		int posFim = i;

		for (int j = posInicio; j < posInicio + (posFim - posInicio)/2; ++j)
		{
			char temp = s[j];
			s[j] = s[posInicio + posFim - j - 1];
			s[posInicio + posFim - j - 1] = temp;
		}
	}
}

int main(int argc, char* argv[])
{
	std::string s = "Meu time eh o flamengo";

	reverse(s);

	std::cout << s << std::endl;
}