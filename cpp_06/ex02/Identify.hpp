# ifndef IDENTIFY_HPP
# define IDENTIFY_HPP

#include <cstdlib>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <exception>

using std::string;
using std::cout;
using std::endl;


class Base
{
	public:
		virtual ~Base();
};

class A : public Base
{	
};

class B : public Base
{	
};

class C : public Base
{	
};

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

# endif