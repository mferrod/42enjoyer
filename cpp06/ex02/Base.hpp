#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <stdint.h>

class Base {
	public:
		virtual ~Base();
		static Base * generate(void);
		static void identify(Base *p);
		static void identify(Base &p);
};

#endif