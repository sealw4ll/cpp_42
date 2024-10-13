# ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>
// #include <string>
// #include <iostream>

// using std::cout;
// using std::endl;
// using std::string;

template <typename T>
class Array
{
    public:
        Array();
        Array(unsigned int size);
        Array(const Array &copy);
        Array &operator=(const Array &copy);
        ~Array();

        T& operator[](unsigned int);
        unsigned int size() const;

        class OutOfBound : public std::exception
        {
            virtual const char *what() const throw()
			{
				return "out of bound";
			}
        };

    private:
        T *array;  // Dynamically allocated array
        unsigned int length;  // Size of the array
};

#include "Array.tpp"

# endif