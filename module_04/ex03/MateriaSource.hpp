#ifndef CPP_MODULES_MATERIASOURCE_HPP
#define CPP_MODULES_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
	AMateria *materias[4];

public:
	MateriaSource();
	MateriaSource(MateriaSource const &materiaSource);
	~MateriaSource();
	MateriaSource &operator=(MateriaSource const &materiaSource);
	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif
