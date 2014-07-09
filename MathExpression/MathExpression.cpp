#include <iostream>
#include <string>
#include <stack>

bool isValid(std::string expression)
{
	std::stack<char> stk;

	for (size_t i = 0; i < expression.length(); ++i)
	{
		auto c = expression.at(i);

		if (c == '{' || c == '[' || c == '(')
		{
			stk.push(c);
		}
		else
		{
			if (stk.size() == 0)
			{
				return false;
			}
			else if ((c == '}' && stk.top() == '{')
				|| (c == ']' && stk.top() == '[')
				|| (c == '(' && stk.top() == ')'))
			{
				stk.pop();
			}
			else
			{
				return false;
			}
		}
	}

	return stk.size() == 0;
}

int main(int argc, char* argv[])
{
	/*
	Still need to finish the isValid method.
	*/
}