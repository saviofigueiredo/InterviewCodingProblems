/*
	Write a function that should receive an integer as parameter and should return a string that represents the integer.
*/

#include <string>
#include <list>
#include <string>
#include <iostream>

typedef struct Dictionary
{
	static const std::string units[22];

	static const std::string firstDigit[10];

	static const std::string tens[10];

	static const std::string secondDigit[10];
}Dictionary;

const std::string Dictionary::units[22] = { "hundred", "thousand", "million", "billion", "trillion", "quadrillion", "quintillion", "sextillion", "septillion", "octillion", "nonillion", "decillion",
"undecillion", "duodecillion", "tredecillion", "quattuordecillion", "quindecillion", "sexdecillion", "septendecillion", "octodecillion", "novemdecillion", "vigintillion" };

const std::string Dictionary::firstDigit[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

const std::string Dictionary::tens[10] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

const std::string  Dictionary::secondDigit[10] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };


typedef struct NumberConverter
{
	Dictionary* dictionary;

	NumberConverter()
	{
		dictionary = new Dictionary();
	}

	void getListOfDigitsFromNumber(std::list<int>& listOfDigits, int number)
	{
		while (number != 0)
		{
			listOfDigits.push_back(number % 10);
			number /= 10;
		}
	}

	void popThreeDigits(std::list<int>& listOfDigits, int digits[3])
	{
		digits[0] = digits[1] = digits[2] = 0;

		int count = 0;

		while (listOfDigits.empty() == false && count < 3)
		{
			digits[count++] = listOfDigits.front();
			listOfDigits.pop_front();
		}
	}

	std::string convertNumber(int threeDigits[3])
	{
		std::string result;

		if (threeDigits[1] == 1)
		{
			result = dictionary->tens[threeDigits[0]];
		}
		else
		{
			if (threeDigits[0] != 0)
			{
				result = dictionary->firstDigit[threeDigits[0]];
			}
			if (threeDigits[1] != 0)
			{
				result = dictionary->secondDigit[threeDigits[1]] + " " + result;
			}
		}

		if (threeDigits[2] != 0)
		{
			auto s = dictionary->firstDigit[threeDigits[2]] + " hundred";
			
			if (result.empty() == false)
			{
				result = s + " " + result;
			}
		}

		return result;
	}

	std::string convertNumber(int number)
	{
		std::list<int> listOfDigits;

		int threeDigits[3];

		std::string convertedNumber;

		getListOfDigitsFromNumber(listOfDigits, number);
		
		int unitIndex = 0;
		
		while (listOfDigits.empty() == false)
		{
			popThreeDigits(listOfDigits, threeDigits);

			std::string convertedTreeDigitsNumber = convertNumber(threeDigits);

			if (unitIndex > 0)
			{
				convertedTreeDigitsNumber += " " + dictionary->units[unitIndex];

				if (convertedNumber.empty() == false)
				{
					convertedTreeDigitsNumber += ", ";
				}
			}

			convertedNumber = convertedTreeDigitsNumber + convertedNumber;
			++unitIndex;
		}

		return convertedNumber;
	}
}NumberConverter;

void test(int number)
{
	auto numberConverter = new NumberConverter();
	std::cout << number << " " + numberConverter->convertNumber(number) << std::endl;
}

int main(int argc, char* argv[])
{
	test(2);
	test(13);
	test(49);
	test(215);
	test(1876);
	test(689212);
}