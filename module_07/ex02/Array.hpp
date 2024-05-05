#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <exception>

template<class T>
class Array {
public:
	Array() : size_(0), array_(NULL) {}

	Array(unsigned int n) : size_(n) {
		if (n != 0)
			array_ = new T[n];
		else
			array_ = NULL;
	}

	Array(const Array &other) : size_(other.size_) {
		if (other.size_ == 0) {
			array_ = NULL;
		} else {
			array_ = new T[other.size_];
			for (unsigned int i = 0; i < other.size_; ++i) {
				array_[i] = other.array_[i];
			}
		}
	}

	~Array() {
		delete[] array_;
	}

	Array<T> &operator=(const Array<T> &other) {
		if (this != &other) {
			size_ = other.size_;
			if (other.size_ == 0) {
				array_ = NULL;
			} else {
				delete[] array_;
				array_ = new T[other.size_];
				for (unsigned int i = 0; i < other.size_; ++i) {
					array_[i] = other.array_[i];
				}
			}
		}
		return *this;
	}

	const T &operator[](unsigned int index) const {
		if (index >= size_)
			throw std::exception();
		return array_[index];
	}

	T &operator[](unsigned int index) {
		if (index >= size_)
			throw std::exception();
		return array_[index];
	}

	unsigned int size() const {
		return size_;
	}

private:
	unsigned int size_;
	T *array_;
};

#endif
