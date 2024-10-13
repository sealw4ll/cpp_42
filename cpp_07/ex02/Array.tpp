# ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(): length(0)
{
	this->array = new T[0];
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->array;
}

template <typename T>
Array<T>::Array(unsigned int size): length(size)
{
	this->array = new T[size];
}

template <typename T>
Array<T>::Array(const Array &copy)
{
	*this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &copy)
{
	if (this != &copy) 
	{
        delete[] this->array;
        length = copy.length;
        array = new T[copy.length];
        for (unsigned int i = 0; i < copy.length; i++)
            array[i] = copy.array[i];
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= length)
        throw Array::OutOfBound();
    return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->length;
}

# endif

