#include <iostream>
#include <string>

bool isRotatedString(std::string s1, std::string s2)
{
	if (s1.length() != s2.length())
	{
		return false;
	}

	s1 = s1 + s1;

	int isFound = s1.find(s2);

	return isFound > 0;
}

int main(int argc, char* argv[])
{
	std::string s1 = "Meu time eh o flamengo";
	std::string s2 = "flamengoMeu time eh o ";

	std::cout << "String s1 = " << s1 << " String s2 = " << s2 << " IsRotatedString returned " << isRotatedString(s1, s2) << std::endl;

	std::string s3 = "Meu time eh o flamengo";
	std::string s4 = "Meu time eh o vasco   ";

	std::cout << "String s1 = " << s3 << " String s2 = " << s4 << " IsRotatedString returned " << isRotatedString(s3, s4) << std::endl;
}