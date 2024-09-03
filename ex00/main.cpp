#include "easyfind.hpp"

int main()
{
	std::vector<int> intVector = {1, 2, 3, 4, 5};
	std::deque<int> intDeque = {6, 7, 8, 9, 10};

	try {
		std::cout << static_cast<int> (intVector, 3) << std::endl;
		std::cout << static_cast<int> (intVector, 6) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << static_cast<int> (intDeque, 8) << std::endl;
		std::cout << static_cast<int> (intVector, 11) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}