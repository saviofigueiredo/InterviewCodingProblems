#include <iostream>
#include <string>

bool isPalindrome(const char* s)
{
	int endPos = 0;

	while (s[endPos] != '\0')
	{
		++endPos;
	}

	--endPos;

	for (int startPos = 0; startPos < endPos; ++startPos, --endPos)
	{
		char cStartPos, cEndPos;

		while (s[startPos] != '\0' && (s[startPos] < 'A' || s[startPos] > 'z'))
		{
			++startPos;
		}

		while (endPos > 0 && (s[endPos] < 'A' || s[endPos] > 'z'))
		{
			--endPos;
		}

		cStartPos = s[startPos];
		cEndPos = s[endPos];

		if (cStartPos >= 'a' && cStartPos <= 'z')
		{
			cStartPos = cStartPos - ('a' - 'A');
		}
		if (cEndPos >= 'a' && cEndPos <= 'z')
		{
			cEndPos = s[endPos] - ('a' - 'A');
		}

		if (startPos < endPos && cStartPos != cEndPos)
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	std::string s1 = "Madam, I'm Adam!";
	std::string s2 = "";
	std::string s3 = "   ";
	std::string s4 = "fuluf ";
	std::string s5 = "full";


	std::cout << s1 << " isPalindrome returned " << isPalindrome(s1.c_str()) << std::endl;
	std::cout << s2 << " isPalindrome returned " << isPalindrome(s2.c_str()) << std::endl;
	std::cout << s3 << " isPalindrome returned " << isPalindrome(s3.c_str()) << std::endl;
	std::cout << s4 << " isPalindrome returned " << isPalindrome(s4.c_str()) << std::endl;
	std::cout << s5 << " isPalindrome returned " << isPalindrome(s5.c_str()) << std::endl;
}