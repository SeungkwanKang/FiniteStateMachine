#ifndef INCLUDE_STATE_H_
#define INCLUDE_STATE_H_

#include <iostream>
#include <string>
#include <vector>

#include "FSM.hpp"

template <typename inT, typename outT> class FSM;

template <typename inT, typename outT>
class State
{
private:
	State *pParent;
	int iKey;
	std::string sName;
	outT (*pFunc)(inT);

public:
	State();
	~State();
	State operator()(inT input);

	void setName(std::string name) { sName = name; };
	void setFunction(outT (*func)(inT)) { pFunc = func; };

	outT giveInput(inT input){ return pFunc(input); };
};

template <typename inT, typename outT>
State<inT, outT>::State()
{
	std::cout << "Constructor" << std::endl;
}

template <typename inT, typename outT>
State<inT, outT>::~State()
{
	std::cout << "Deconstructor" << std::endl;
}

#endif // INCLUDE_STATE_H_