#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
	_stack = copy.getStack();
	return *this;
}

stack<int> RPN::getStack() const
{
	return _stack;
}

void RPN::isInputValid(string input)
{
	if (input.empty() || input[0] == ' ' || input[input.size() - 1] == ' ') {
        throw invalidInput();
    }

    for (std::size_t i = 0; i < input.size(); ++i)
	{
        if (i % 2 == 0)
		{
            if (!(input[i] >= '0' && input[i] <= '9') &&
                input[i] != '+' && input[i] != '-' &&
                input[i] != '*' && input[i] != '/')
                throw invalidInput();
        }
		else
		{
            if (input[i] != ' ')
                throw invalidInput();
        }
    }
}

void RPN::runRPN(string input)
{
	int intCounter = 0;
	try
	{
		isInputValid(input);
		for (int i = 0; i < (int)input.size(); i++)
		{
			switch(input[i])
			{
				case '0' ... '9':
					_stack.push(input[i] - '0');
					++intCounter;
					break ;
				case '+': case '-': case '/': case '*':
					if (intCounter <= 1)
						throw invalidInput();
					--intCounter;
					runOperation(input[i]);
					break ;
				case ' ':
					break ;
			}
		}

		if (_stack.size() != 1)
			throw invalidInput();
		else
			cout << _stack.top() << endl;
	}
	catch(std::exception &e)
	{
		cout << e.what() << endl;
	}
}

int RPN::operate(char operation, int a, int b) {
    switch(operation) {
        case '+': return a + b;
        case '-': return a - b;
        case '/': return a / b;
        case '*': return a * b;
        default: return 0;
    }
}

void RPN::runOperation(char operation)
{
	int tmp1 = _stack.top();
    _stack.pop();
    int tmp2 = _stack.top();
    _stack.pop();
    _stack.push(operate(operation, tmp2, tmp1));
}
