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

#endif // INCLUDE_FSM_MEALY_H_