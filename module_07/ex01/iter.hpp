#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template<class T, class U>
void iter(T *array, std::size_t size, U f) {
	for (std::size_t i = 0; i < size; ++i) {
		f(array[i]);
	}
}

#endif
