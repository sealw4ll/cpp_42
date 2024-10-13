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

	cout << "6 value shortest span: "<< sp.shortestSpan() << endl;
	cout << "6 balue longest span: "<< sp.longestSpan() << endl;

    try
    {
        sp.addNumber(10); // should fail
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << endl;
    }
    
    std::srand(static_cast<unsigned int>(time(0)));    // Create a vector to store the random values
    Span span = Span(10000);
    // Loop to add 10,000 random values
    for (size_t i = 0; i < 10000; ++i) {
        // Generate a random value between 0 and UINT_MAX
        unsigned int randomValue = static_cast<unsigned int>(std::rand());
        span.addNumber(randomValue);
    }
    cout << "10k value shortest span: "<< span.shortestSpan() << endl;
	cout << "10k balue longest span: "<< span.longestSpan() << endl;
}