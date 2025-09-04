#ifndef WHATEVER_HPP
#define WHATEVER_HPP

class Whatever {
public:
	Whatever();
	Whatever(const Whatever &other);
	~Whatever();
	Whatever &operator=(const Whatever &other);
	
};

#endif