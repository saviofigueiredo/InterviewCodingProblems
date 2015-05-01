#include <iostream>
#include <stack>

char evaluateExpression(char _booleanOperator, char _leftValue, char _rightValue)
{
	char result;

	if (_booleanOperator == '&')
	{
		if (_leftValue == 't' && _rightValue == 't')
		{
			return 't';
		}
		else
		{
			return 'f';
		}
	}
	else
	{
		if (_leftValue == 't' || _rightValue == 't')
		{
			return 't';
		}
		else
		{
			return 'f';
		}
	}
	return 'f';
}

bool evaluate(std::string _expression)
{
	std::stack<char> values;

	for (auto i = 0; i < _expression.length(); ++i)
	{
		if (_expression[i] == '(' || _expression[i] == '&' || _expression[i] == '|' || _expression[i] == 't' || _expression[i] == 'f')
		{
			values.push(_expression[i]);
		}
		else if (_expression[i] == ')')
		{
			std::stack<char> valuesRightOrder;

			while (values.top() != '(')
			{
				valuesRightOrder.push(values.top());
				values.pop();
			}
			values.pop();

			char result = valuesRightOrder.top();
			while (valuesRightOrder.size() > 1)
			{
				auto rightValue = valuesRightOrder.top();
				valuesRightOrder.pop();

				auto booleanOperator = valuesRightOrder.top();
				valuesRightOrder.pop();

				auto leftValue = valuesRightOrder.top();
				valuesRightOrder.pop();

				auto result = evaluateExpression(booleanOperator, leftValue, rightValue);
				valuesRightOrder.push(result);
			}

			values.push(result);
		}
	}

	return values.top();
}


int main(char argc, char* argv[])
{
	char expression[] = "(((f | t & f) | f) | f)";
	auto result = evaluate(expression);

	std::cout << "Expression " << expression << " has been evaluated to " << result << std::endl;
}