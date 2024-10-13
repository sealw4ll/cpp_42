#include "Span.hpp"

Span::Span(): N(0)
{
}

Span::Span(unsigned int size): N(size)
{
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span & Span::operator=(const Span &copy)
{
    this->N = copy.N;
    this->vct = copy.vct;
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(unsigned int val)
{
    if (vct.size() >= N)
        throw Full();
    vct.push_back(val);
}

void Span::addMulti(std::vector<unsigned int> input)
{
    if (input.size() + this->vct.size() > N)
        throw Full();
    for (vector<unsigned int>::iterator i = input.begin(); i < input.end(); i++)
			addNumber(*i);
}

int Span::shortestSpan()
{
    if (vct.size() <= 1)
        throw NoSpan();

    std::sort(vct.begin(), vct.end());

    unsigned int lowestSpan = vct[1] - vct[0];
    for (long unsigned int i = 1; i < vct.size() - 1; i++)
    {
        if (vct[i + 1] - vct[i] < lowestSpan)
            lowestSpan = vct[i + 1] - vct[i];
    }
    return lowestSpan;
}

int Span::longestSpan()
{
    if (vct.size() <= 1)
        throw NoSpan();

    return *(std::max_element(vct.begin(), vct.end())) - *(std::min_element(vct.begin(), vct.end()));
}

unsigned int Span::getN() const
{
    return this->N;
}

void Span::setN(unsigned int newN)
{
    this->N = newN;
}