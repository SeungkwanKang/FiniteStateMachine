#ifndef INCLUDE_FSM_MOORE_H_
#define INCLUDE_FSM_MOORE_H_

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "FSM.hpp"
#include "State.hpp"
#include "State_Moore.hpp"

template <typename inT, typename outT> class FSM;
template <typename inT, typename outT> class State;
template <typename inT, typename outT> class State_Moore;

template <typename inT, typename outT>
class FSM_Moore : public FSM<inT, outT>
{
	template <typename T1, typename T2>
	friend class State_Moore;

public:
	FSM_Moore();
	~FSM_Moore();

public:
	outT operator()(inT input) override;
};

/*
 * Constructor of FSM_Moore class
 * 
 * A templated FSM_Moore class constructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
FSM_Moore<inT, outT>::FSM_Moore()
{
}

/*
 * Deconstructor of FSM_Moore class
 * 
 * A templated FSM_Moore class constructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
FSM_Moore<inT, outT>::~FSM_Moore()
{
}

/*
* operator() for FSM
* 
* passes the input to pCurrState
* 1. Gets result
* 2. Gets next state
* 
* @param input value of type inT
* @return output of type outT
*/
template <typename inT, typename outT>
outT FSM_Moore<inT, outT>::operator()(inT input)
{
	if (this->pCurrState == nullptr)
	{
		std::cerr << "There was no start State given. Add a start State." << std::endl;
		throw("[FSM] No start State error");
	}
	if (this->pCurrState->pTransFunc == nullptr)
	{
		std::cerr << "There was no transfer function given." << std::endl;
		throw("[FSM] No tranfer function error");
	}

	outT result = this->pCurrState->getOutput(input);
	std::string sNextName = this->pCurrState->pTransFunc->operator()(input);

	this->setNextStateByName(sNextName);
	return  result;
}

#endif // INCLUDE_FSM_MOORE_H_