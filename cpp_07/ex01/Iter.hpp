# ifndef ITER_HPP
# define ITER_HPP

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

template <typename T, typename R>
void iter(T *array, int length, R (*func)(T &))
{
	for (int i = 0; i < length; i++)
		func(array[i]);
}

# endif