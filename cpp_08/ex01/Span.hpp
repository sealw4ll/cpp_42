# ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using std::cout;
using std::endl;
using std::vector;

class Full : public std::exception
{
    const char *what() const throw(){
        return ("Error: Full");
    }
};

class NoSpan : public std::exception
{
    const char *what() const throw(){
        return ("Error: Has 1 or less values");
    }
};

class Span{
	public:
        Span();
		Span(unsigned int size);
		Span(const Span &copy);
		Span &operator=(const Span &copy);
		~Span();

		void addNumber(unsigned int val);
		void addMulti(std::vector<unsigned int> input);
		int shortestSpan();
		int longestSpan();

		unsigned int getN() const;
		void setN(unsigned int newN);

	private:
		unsigned int N;
		std::vector<unsigned int> vct;
};

# endif