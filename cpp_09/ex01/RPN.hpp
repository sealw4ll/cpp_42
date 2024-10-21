# ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

using std::cout;
using std::endl;
using std::string;
using std::stack;

class invalidInput : public std::exception{
	public:
		const char *what() const throw(){
			return ("Error: invalid RPN\nvalid ex: ./RPN \"2 3 * 8 * 2 / 3 * 8 9 - - 4 -\"");
		}
};



class RPN
{
	public:
		RPN();
		~RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		stack<int> getStack() const;
		void isInputValid(string input);
		void runRPN(string input);
		void runOperation(char operation);
		int operate(char operation, int a, int b);
		
	private:
		stack<int> _stack;
};

# endif
