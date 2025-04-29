#pragma once

#include <algorithm>
// #include <exception>
#include <stdexcept>
// #include <string>

// class NotFoundException : public std::exception{
// 	private:
// 		std::string _msg = "Element not found";
// 	public:
// 		const char *what() const noexcept{
// 			return _msg.c_str();
// 		}
// };

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error("Element not found");
	return it;
}
