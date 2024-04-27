#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const &materiaSource) {
	for (int i = 0; i < 4; i++)
		materias[i] = materiaSource.materias[i]->clone();
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++)
		delete materias[i];
}

MateriaSource &MateriaSource::operator=(MateriaSource const &materiaSource) {
	if (this != &materiaSource) {
		for (int i = 0; i < 4; i++) {
			delete materias[i];
			materias[i] = materiaSource.materias[i]->clone();
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *m) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] == NULL) {
			materias[i] = m;
			break;
		}
	}
}

AMateria *MateriaSource::createMateria(std::string const &type) {
	for (int i = 0; i < 4; i++) {
		if (materias[i] != NULL && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return NULL;
}
