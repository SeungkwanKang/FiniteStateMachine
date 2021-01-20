#ifndef INCLUDE_STATE_MEALY_H_
#define INCLUDE_STATE_MEALY_H_

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "FSM.hpp"
#include "FSM_Mealy.hpp"
#include "State.hpp"

template <typename inT, typename outT>
class FSM;
template <typename inT, typename outT>
class FSM_Mealy;
template <typename inT, typename outT>
class State;

template <typename inT, typename outT>
class State_Mealy : public State<inT, outT>
{
	template <typename T1, typename T2>
	friend class FSM_Mealy;

private:
	std::function<outT(inT)> *pOutFunc;
	outT getOutput(inT input);

public:
	void setOutputFunction(std::function<outT(inT)> *pfunc);
};

/*
 * setOutputFunction of State_Mealy class
 * 
 * Checks whether the instance is locked and changes the output function
 * Mealy Machine's output is binded with the State.
 * 
 * @param std::function<outT(inT)>* pointer to std::function
 * @return void / throws error if locked
 */
template <typename inT, typename outT>
void State_Mealy<inT, outT>::setOutputFunction(std::function<outT(inT)> *pfunc)
{
	if (!(this->isLocked))
		pOutFunc = pfunc;
	else
	{
		std::cerr << "The state is locked. You should not modify the state after FSM running." << std::endl;
		throw("[State] Modify after lock error");
	}
}

/*
 * getOutput of State_Mealy class
 * gets the input and returns the output
 * 
 * Mealy Machine's output is the result of output function
 * The result returns result of the output function.
 * 
 * @param integer value of input
 * @return outT value of Output Function's return value
 */
template <typename inT, typename outT>
outT State_Mealy<inT, outT>::getOutput(inT input)
{
	return pOutFunc->operator()(input);
}

#endif // INCLUDE_STATE_MEALY_H_