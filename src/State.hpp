#ifndef INCLUDE_STATE_H_
#define INCLUDE_STATE_H_

#define DEBUG_

#include <iostream>
#include <string>
#include <vector>
#include <functional>

#include "FSM.hpp"

template <typename inT, typename outT> class FSM;

template <typename inT, typename outT>
class State
{
	template <typename T1, typename T2>
	friend class FSM;
	template <typename T1, typename T2>
	friend class FSM_Moore;
	template <typename T1, typename T2>
	friend class FSM_Mealy;

protected: // Internals
	State *pParent;

protected: // Identification related
	int iKey;
	std::string sName;
	bool isStartState;
	bool isEndState;

protected: // Function related
	// Transition function
	std::function<std::string(inT)> *pTransFunc;
	bool isLocked = false;

protected: // Input related
	virtual outT getOutput(inT input) = 0;
	void callStateByName(std::string name);

public: // Initialization related
	State();
	~State();
	void setName(std::string name);
	void setTransitionFunction(std::function<std::string(inT)> *);
	void setAsStartState();
	void setAsEndState();
};


/*
 * Constructor of State class
 * 
 * A templated State class constructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
State<inT, outT>::State()
{
#ifdef DEBUG_
	std::cout << "[State] Constructor" << std::endl;
#endif
	iKey = -1;
	sName = "";
	pTransFunc = nullptr;
	isStartState = false;
}

/*
 * Deconstructor of State class
 * 
 * A templated State class deconstructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
State<inT, outT>::~State()
{
#ifdef DEBUG_
	std::cout << "[State] Deconstructor" << std::endl;
#endif
}

/*
 * setName of State class
 * 
 * Checks whether the instance is locked and changes the name
 * 
 * @param std::string value of new name
 * @return void / prints out error if locked
 */
template <typename inT, typename outT>
void State<inT, outT>::setName(std::string name)
{
#ifdef DEBUG_
	std::cout << "[State] setName called: " << name << std::endl;
#endif
	if (!isLocked)
		sName = name;
	else
		std::cerr << "The state is locked. You should not modify the state after FSM running." << std::endl;
}

/*
 * setTransitionFunction of State class
 * 
 * Checks whether the instance is locked and changes the transition function
 * 
 * @param function pointer of new transition function
 * @return void / throws error if locked
 */
template <typename inT, typename outT>
void State<inT, outT>::setTransitionFunction(std::function<std::string(inT)> *func)
{
	if (!isLocked)
		pTransFunc = func;
	else
	{
		std::cerr << "The state is locked. You should not modify the state after FSM running." << std::endl;
		throw("[State] Modify after lock error");
	}
}

template <typename inT, typename outT>
void State<inT, outT>::setAsStartState()
{
	isStartState = true;
}

template <typename inT, typename outT>
void State<inT, outT>::setAsEndState()
{
	isEndState = true;
}

/*
 * calls the next state by name
 * 
 * Checks whether the parent (FSM) is set and modifies its next state
 * 
 * @param std::string value of name
 * @return void / throws error if parent not set
 */
template <typename inT, typename outT>
void State<inT, outT>::callStateByName(std::string name)
{
	{
		if (pParent != NULL)
			pParent->setNextStateByName(name);
		else
		{
			std::cerr << "Please load the state first." << std::endl;
			throw("[State] Call before set error");
		}
	}
}

#endif // INCLUDE_STATE_H_