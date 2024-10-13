# ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <iterator>
#include <algorithm> 
#include <vector>

using std::cout;
using std::endl;

class NotFound : public std::exception
{
    const char *what() const throw()
    {
        return ("Value not found");
    } 
};

template<typename T>
typename T::iterator easyfind(T param, int toFind)
{
    typename T::iterator ret = find(param.begin(), param.end(), toFind);

    if (ret == param.end())
        throw NotFound();

    return ret;
};


# endif