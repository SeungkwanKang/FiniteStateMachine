#include <string>
#include <functional>
#include "State.hpp"

int main(int argc, char *argv[])
{
	State<int, std::string> s;

	std::function<std::string(State<int, std::string>*, int)> f = \
		[](State<int, std::string>* pThis, int input) {
			if (input < 0)
				std::cout << "under-zero: " << input << std::endl;
			else
				std::cout << "over-zero: " << input << std::endl;
			return std::to_string(input);
		};

	s.setFunction(&f);

	s.giveInput(3);

	return 0;
}