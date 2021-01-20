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

#endif // INCLUDE_FSM_MOORE_H_