#include "Span.hpp"

int main()
{
	Span sp = Span(6);
	vector<unsigned int> vec;

	sp.addNumber(1);

    vec.push_back(3);
    vec.push_back(9);
    vec.push_back(12);
    vec.push_back(14);
    vec.push_back(9999);

	sp.addMulti(vec);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}