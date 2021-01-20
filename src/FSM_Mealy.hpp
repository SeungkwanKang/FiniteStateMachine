#ifndef INCLUDE_FSM_MEALY_H_
#define INCLUDE_FSM_MEALY_H_

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "FSM.hpp"
#include "State.hpp"
#include "State_Mealy.hpp"

template <typename inT, typename outT>
class FSM;
template <typename inT, typename outT>
class State;
template <typename inT, typename outT>
class State_Mealy;

template <typename inT, typename outT>
class FSM_Mealy : public FSM<inT, outT>
{
	template <typename T1, typename T2>
	friend class State_Mealy;

public:
	FSM_Mealy();
	~FSM_Mealy();

public:
	outT operator()(inT input) override;
};

/*
 * Constructor of FSM_Mealy class
 * 
 * A templated FSM_Mealy class constructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
FSM_Mealy<inT, outT>::FSM_Mealy()
{
}

/*
 * Deconstructor of FSM_Mealy class
 * 
 * A templated FSM_Mealy class constructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
FSM_Mealy<inT, outT>::~FSM_Mealy()
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
outT FSM_Mealy<inT, outT>::operator()(inT input)
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

	this->setNextStateByName(this->pCurrState->pTransFunc->operator()(input));
	return this->pCurrState->getOutput(input);
}

#endif // INCLUDE_FSM_MEALY_H_