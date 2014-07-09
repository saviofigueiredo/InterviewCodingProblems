#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <unordered_map>

std::list<std::string> getWordsFromString(std::string s)
{
	std::list<std::string> words;

	for (size_t i = 0; i < s.length(); ++i)
	{
		while (i < s.length() && s[i] == ' ')
		{
			++i;
		}

		bool isValidWord = true;
		std::string word;

		while (i < s.length() && s[i] != ' ')
		{
			if (isValidWord)
			{
				if (isalpha(s[i]) == false)
				{
					isValidWord = false;
				}
				else
				{
					word.push_back(tolower(s[i]));
				}
			}
			++i;
		}

		if (isValidWord)
		{
			words.push_back(word);
		}
	}

	return words;
}

bool isAnagram(std::string s1, std::string s2)
{
	if (s1.length() != s2.length())
	{
		return false;
	}

	std::unordered_map<char, int> lettersCount;

	for (size_t i = 0; i < s1.length(); ++i)
	{
		if (lettersCount.find(s1[i]) == lettersCount.end())
		{
			lettersCount.insert(std::make_pair(s1[i], 1));
		}
		else
		{
			lettersCount[s1[i]]++;
		}
	}

	for (size_t i = 0; i < s2.length(); ++i)
	{
		if (lettersCount.find(s2[i]) == lettersCount.end() || lettersCount[s2[i]] == 0)
		{
			return false;
		}
		
		lettersCount[s2[i]]--;
	}

	return true;
}

std::list<std::string> getAllAnagrams(std::string s)
{
	auto words = getWordsFromString(s);
	std::list<std::string> anagrams;

	while (words.empty() == false)
	{
		auto word = words.front();
		words.pop_front();

		bool currentWordIsAnagram = false;

		auto it = words.begin();
		while (it != words.end())
		{
			auto previousIt = it;
			++it;

			if (isAnagram(*previousIt, word))
			{
				currentWordIsAnagram = true;
				words.erase(previousIt);
			}
		}

		if (currentWordIsAnagram)
		{
			anagrams.push_back(word);
		}
	}

	return anagrams;
}

int main(int argc, char* argv[])
{
	auto anagrams = getAllAnagrams("O ator saca tua rota na casa o ator saca sua rota na casa");

	for (auto it = anagrams.begin(); it != anagrams.end(); ++it)
	{
		std::cout << *it << std::endl;
	}
}