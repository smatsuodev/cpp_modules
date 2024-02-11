#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain {
	static const int NUM_OF_IDEAS = 100;
	std::string ideas[NUM_OF_IDEAS];

public:
	Brain();
	Brain(const Brain &brain);
	~Brain();
	Brain &operator=(const Brain &brain);
};

#endif
