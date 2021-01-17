#ifndef INCLUDE_STATE_MOORE_H_
#define INCLUDE_STATE_MOORE_H_

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "FSM.hpp"
#include "FSM_Moore.hpp"
#include "State.hpp"

template <typename inT, typename outT> class FSM;
template <typename inT, typename outT> class FSM_Moore;
template <typename inT, typename outT> class State;

template <typename inT, typename outT>
class State_Moore : public State<inT, outT>
{
	template <typename T1, typename T2>
	friend class FSM_Moore;

private:
	outT oOutput;

private:
	std::function<outT(State<inT, outT> *)> *pOutFunc;
	outT getOutput(inT input);
	
public:
	void setOutput(outT output);
};

/*
 * setOutput of State_Moore class
 * 
 * Checks whether the instance is locked and changes the output
 * Moore Machine's output is binded with the State.
 * 
 * @param outT value of output
 * @return void / throws error if locked
 */
template <typename inT, typename outT>
void State_Moore<inT, outT>::setOutput(outT output)
{
	if (!this->isLocked)
		oOutput = output;
	else
	{
		std::cerr << "The state is locked. You should not modify the state after FSM running." << std::endl;
		throw("[State] Modify after lock error");
	}
}

/*
 * giveInput of State_Moore class
 * gets the input and returns the output
 * 
 * Moore Machine's output is independent to input.
 * The result returns the pre-defined result binded with the state.
 * 
 * @param integer value of input (not used)
 * @return outT value of pre-binded output of State
 */
template <typename inT, typename outT>
outT State_Moore<inT, outT>::getOutput(inT input)
{
	return oOutput;
}

#endif // INCLUDE_STATE_MOORE_H_