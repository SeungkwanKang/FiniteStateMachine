#include <string>
#include <functional>

#include "FSM_Moore.hpp"
#include "State_Moore.hpp"

int main(int argc, char *argv[])
{
	// An example FSM where it goes the following:
	// 1. Reads a number
	// 	if number > 0 return "Positive"
	// 	if number < 0 return "Negative"
	//	if number = 0 return "Zero", terminate

	FSM_Moore<int, std::string> fsm;

	State_Moore<int, std::string> s0;
	s0.setName(std::string("Start"));
	std::function<std::string(int)> tf0 = \
		[](int input) {
			if (input > 0)
				return std::string("Positive");
			else if (input == 0)
				return std::string("Zero");
			else
				return std::string("Negative");
		};
	s0.setOutput(""); // Start-only state doesn't require return value
	s0.setTransitionFunction(&tf0);
	s0.setAsStartState();


	State_Moore<int, std::string> s1;
	s1.setName(std::string("Positive"));
	std::function<std::string(int)> tf1 =
		[](int input) {
			if (input > 0)
				return std::string("Positive");
			else if (input == 0)
				return std::string("Zero");
			else
				return std::string("Negative");
		};
	s1.setOutput("The output was positive.");
	s1.setTransitionFunction(&tf1);


	State_Moore<int, std::string> s2;
	s2.setName(std::string("Negative"));
	std::function<std::string(int)> tf2 =
		[](int input) {
			if (input > 0)
				return std::string("Positive");
			else if (input == 0)
				return std::string("Zero");
			else
				return std::string("Negative");
		};
	s2.setOutput("The output was negative.");
	s2.setTransitionFunction(&tf2);


	State_Moore<int, std::string> s3;
	s3.setName(std::string("Zero"));
	std::function<std::string(int)> tf3 =
		[](int input) {
			return std::string("");
		}; // End state's transition function not needed
	s3.setOutput("The output was zero. Terminate");
	s3.setTransitionFunction(&tf3);
	s3.setAsEndState();


	fsm.addState(&s0);
	fsm.addState(&s1);
	fsm.addState(&s2);
	fsm.addState(&s3);


	std::cout << fsm(-3) << std::endl;
	std::cout << fsm(2) << std::endl;
	std::cout << fsm(-1) << std::endl;
	std::cout << fsm(3) << std::endl;
	std::cout << fsm(0) << std::endl;

	return 0;
}