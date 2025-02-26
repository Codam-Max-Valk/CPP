#pragma once

#include <iostream>
#include <ostream>
#include <exception>

class OutOfBounds : public std::exception{
	private:
		const char *_msg = "Out of Bounds";
	public:
		const char *what() const noexcept{
			return _msg;
		};
};

template <typename T>
class Array{
	private:
		T *_array;
		size_t _size;
	public:
		Array() : _array(NULL), _size(0) {};
		Array(size_t n) : _array(new T[n]), _size(n) {};
		Array(const Array &other) : _array(new T[other._size]), _size(other._size) {
			for (size_t i = 0; i < _size; i++)
				_array[i] = other._array[i];
		};
		~Array() {delete[] _array;};
		Array &operator=(const Array &other) {
			if (this != &other) {
				delete[] _array;
				_array = new T[other._size];
				_size = other._size;
				for (size_t i = 0; i < _size; i++)
					_array[i] = other._array[i];
			}
			return *this;
		};
		T &operator[](size_t index) const{
			if (index < 0 || index >= _size)
				throw OutOfBounds();
			return _array[index];
		};
		size_t size() const {return _size;};
};
