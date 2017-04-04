
#include <string>
#include <vector>
#include <stack>

using std::stack;
using std::string;
using std::vector;

#define DIGIT(c) ((c) - '0')

bool isNumber(char ch)
{
	return '0' <= ch && ch <= '9';
}

double getNumber(const string &expStr, int *idx)
{
	double res = DIGIT(expStr[*idx]);
	*idx += 1;
	while (isNumber(expStr[*idx]))
	{
		res = res * 10 + DIGIT(expStr[*idx]);
		*idx += 1;
	}
	return res;
}
int weight(char op)
{
	int weight = -1;
	switch (op)
	{
	case '+':
	case '-':
		weight = 1;
		break;
	case '*':
	case '/':
		weight = 2;
		break;
	}
	return weight;
}

bool isOperator(char ch)
{
	return ch == '*' || ch == '-' || ch == '+' || ch == '/';
}

int hasHigherPrecedence(char op1, char op2)
{
	return weight(op1) > weight(op2) ;
}

double eval(double operand1, double operand2, char op)
{
	switch (op)
	{
	case '+': return operand1 + operand2;
	case '-': return operand1 - operand2;
	case '*': return operand1 * operand2;
	case '/': return operand1 / operand2;
	default: return 0;
	}
}

void ecvalLastExp(stack<double> &numbers, stack<char> &ops)
{
	double operand2 = numbers.top(); 
	numbers.pop();
	double operand1 = numbers.top(); 
	numbers.pop();
	numbers.push(eval(operand1, operand2, ops.top()));
	ops.pop();
}

double eval(const string &expStr)
{
	stack<double> numbers;
	stack<char> ops;
	int i = 0;
	while (i<expStr.size())
	{
		if (isNumber(expStr[i]))
		{
			double number = getNumber(expStr, &i);
			numbers.push(number);
		}
		else if (isOperator(expStr[i]))
		{
			while (!ops.empty() && hasHigherPrecedence(ops.top(), expStr[i]))			
				ecvalLastExp(numbers, ops);
			ops.push(expStr[i++]);
		}
	}
	while (!ops.empty())	
		ecvalLastExp(numbers, ops);
	
	return numbers.top();
}
