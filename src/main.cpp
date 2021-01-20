#include <string>
#include <functional>

#include "FSM_Moore.hpp"
#include "State_Moore.hpp"
#include "FSM_Mealy.hpp"
#include "State_Mealy.hpp"

void TestMoore();
void TestMealy();

int main(int argc, char *argv[])
{
	// An example FSM where it goes the following:
	// 1. Reads a number
	// 	if number > 0 return "Positive"
	// 	if number < 0 return "Negative"
	//	if number = 0 return "Zero", terminate

	std::cout << "========= Start of TestMoore() =========" << std::endl;
	TestMoore();
	std::cout << "========= End of TestMoore() =========" << std::endl;
	std::cout << "========= Start of TestMealy() =========" << std::endl;
	TestMealy();
	std::cout << "========= End of TestMealy() =========" << std::endl;

	return 0;
}

void TestMoore()
{
	FSM_Moore<int, std::string> fsm;

	State_Moore<int, std::string> s0;
	s0.setName(std::string("Start"));
	std::function<std::string(int)> tf0 =
		[](int input) {
			if (input > 0)
				return std::string("Positive");
			else if (input == 0)
				return std::string("Zero");
			else
				return std::string("Negative");
		};
	s0.setTransitionFunction(&tf0);
	s0.setOutput(""); // Start-only state doesn't require return value
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
	s1.setTransitionFunction(&tf1);
	s1.setOutput("The output was positive.");

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
	s2.setTransitionFunction(&tf2);
	s2.setOutput("The output was negative.");

	State_Moore<int, std::string> s3;
	s3.setName(std::string("Zero"));
	std::function<std::string(int)> tf3 =
		[](int input) {
			return std::string("");
		}; // End state doesn't require transition function
	s3.setTransitionFunction(&tf3);
	s3.setOutput("The output was zero. Terminate");
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
}

void TestMealy()
{
	FSM_Mealy<int, std::string> fsm;

	State_Mealy<int, std::string> s0;
	s0.setName(std::string("Start"));
	std::function<std::string(int)> tf0 =
		[](int input) {
			if (input > 0)
				return std::string("Positive");
			else if (input == 0)
				return std::string("Zero");
			else
				return std::string("Negative");
		};
	s0.setTransitionFunction(&tf0);
	std::function<std::string(int)> of0 =
		[](int input) {
			if (input > 0)
				return std::string("The output was positive.");
			else if (input == 0)
				return std::string("The output was zero. Terminate");
			else
				return std::string("The output was negative.");
		};
	s0.setOutputFunction(&of0);
	s0.setAsStartState();

	State_Mealy<int, std::string> s1;
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
	s1.setTransitionFunction(&tf1);
	std::function<std::string(int)> of1 =
		[](int input) {
			if (input > 0)
				return std::string("The output was positive.");
			else if (input == 0)
				return std::string("The output was zero. Terminate");
			else
				return std::string("The output was negative.");
		};
	s1.setOutputFunction(&of1);

	State_Mealy<int, std::string> s2;
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
	s2.setTransitionFunction(&tf2);
	std::function<std::string(int)> of2 =
		[](int input) {
			if (input > 0)
				return std::string("The output was positive.");
			else if (input == 0)
				return std::string("The output was zero. Terminate");
			else
				return std::string("The output was negative.");
		};
	s2.setOutputFunction(&of2);

	State_Mealy<int, std::string> s3;
	s3.setName(std::string("Zero"));
	std::function<std::string(int)> tf3 =
		[](int input) {
			return std::string("");
		}; // End state doesn't require transition function
	s3.setTransitionFunction(&tf3);
	std::function<std::string(int)> of3 =
		[](int input) {
			if (input > 0)
				return std::string("The output was positive.");
			else if (input == 0)
				return std::string("The output was zero. Terminate");
			else
				return std::string("The output was negative.");
		};
	s3.setOutputFunction(&of3);
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
}