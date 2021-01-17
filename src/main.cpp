#include <string>
#include <functional>

#include "FSM_Moore.hpp"
#include "State_Moore.hpp"

int main(int argc, char *argv[])
{
	// An example FSM where it goes the following:
	// 1. Starts by asking for a number. (Output: Query of input)
	// 2. Reads the number
	// 	if number >= 0 print and goes to end State
	// 	if number <  0 goes back to start State

	FSM_Moore<int, std::string> fsm;

	State_Moore<int, std::string> s1;
	s1.setName(std::string("Start"));
	std::function<std::string(int)> tf1 = \
		[](int input) {
			if (input < 0)
				return std::string("Positive");
			else
				return std::string("Start");
		};
	s1.setOutput("Reading the input...");
	s1.setTransitionFunction(&tf1);
	s1.setAsStartState();

	State_Moore<int, std::string> s2;
	s2.setName(std::string("Positive"));
	std::function<std::string(int)> tf2 =
		[](int input) {
			if (input < 0)
				return std::string("Positive");
			else
				return std::string("Start");
		};
	s2.setOutput("The output was positive. Terminating...");
	s2.setTransitionFunction(&tf2);
	s2.setAsEndState();

	fsm.addState(&s1);
	fsm.addState(&s2);
	
	std::cout << fsm(-3) << std::endl;
	std::cout << fsm(-2) << std::endl;
	std::cout << fsm(-1) << std::endl;
	std::cout << fsm(3) << std::endl;

	return 0;
}