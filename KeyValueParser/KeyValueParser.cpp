#include <iostream>
#include <map>
#include <string>

std::map<int, int> parseKeyValue(std::string stringToParser)
{
	std::map<int, int> keyValues;

	for (int i = stringToParser.length() - 1; i >= 0; --i)
	{
		int value = 0;
		int factor = 1;

		if (i >= 0 && stringToParser[i] == ';')
		{
			--i;
		}

		while (i >= 0 && stringToParser[i] != '=')
		{
			value += (stringToParser[i--] - '0') * factor;
			factor *= 10;
		}
		--i;

		int key = 0;
		factor = 1;
		while (i >= 0 && stringToParser[i] != ';')
		{
			key += (stringToParser[i--] - '0') * factor;
			factor *= 10;
		}

		keyValues.insert(std::make_pair(key, value));
	}

	return keyValues;
}

int main(int argc, char* argv[])
{
	auto keyValues = parseKeyValue("1=2;");
	for (std::map<int, int>::iterator it = keyValues.begin(); it != keyValues.end(); ++it)
	{
		std::cout << (*it).first << " " << (*it).second << std::endl;
	}
}