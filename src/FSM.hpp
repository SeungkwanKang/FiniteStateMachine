#ifndef INCLUDE_FSM_H_
#define INCLUDE_FSM_H_

#define DEBUG_

#include "State.hpp"

template <typename inT, typename outT> class State;

template <typename inT, typename outT>
class FSM
{
	template <typename T1, typename T2>
	friend class State;
	template <typename T1, typename T2>
	friend class State_Moore;
	template <typename T1, typename T2>
	friend class State_Mealy;

protected:
	bool isLocked;

protected:
	State<inT, outT>* pCurrState;
	std::vector<State<inT, outT> *> vpState;
	bool checkDuplicateStateName(std::string name);

protected: // Setting the next state
	void setNextStateByKey(int key);
	void setNextStateByName(std::string name);

public: // Initialization related
	FSM();
	~FSM();
	void addState(State<inT, outT> *state);

public: // Execution related
	virtual outT operator()(inT input) = 0;
};

/*
 * Constructor of FSM class
 * 
 * A templated FSM class constructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
FSM<inT, outT>::FSM()
{
#ifdef DEBUG_
	std::cout << "[FSM] Constructor" << std::endl;
#endif
	isLocked = false;
	pCurrState = nullptr;
}

/*
 * Deconstructor of FSM class
 * 
 * A templated FSM class constructor.
 * Template holds the input and output type.
 */
template <typename inT, typename outT>
FSM<inT, outT>::~FSM()
{
#ifdef DEBUG_
	std::cout << "[FSM] Deconstructor" << std::endl;
#endif
}

/*
 * adds new State to FSM
 * 
 * checks for locks (FSM and State)
 * grabs start State if any
 * 
 * @param pointer to the new State
 * @return void / throws error if locked
 */
template <typename inT, typename outT>
void FSM<inT, outT>::addState(State<inT, outT>* pstate)
{
	if (isLocked)
	{ // Modification after lock
		std::cerr << "FSM is locked. Do not modify FSM after it's running." << std::endl;
		throw("[FSM] Modify after lock error");
	}
	if ((pstate->isLocked) || (pstate->iKey != -1))
	{ // Adding same state again
		std::cerr << "Adding same State multiple times." << std::endl;
		throw("[FSM] Multiple addition of State instance");
	}
	if (pstate->sName == "")
	{ // No name given
		std::cerr << "No name given for State." << std::endl;
		throw("[FMS] Received no-name State instance");
	}
	if (checkDuplicateStateName(pstate->sName))
	{ // Duplicate name
		std::cerr << "Duplicate name for State." << std::endl;
		throw("[FMS] Received duplicate State instance");
	}

	pstate->isLocked = true;
	pstate->iKey = (int)vpState.size();
	vpState.push_back(pstate);
	if (pstate->isStartState)
	{
		if (pCurrState == nullptr)
			pCurrState = pstate;
		else
		{
			std::cerr << "Received multiple start states." << std::endl;
			throw("[FSM] Received multiple start states");
		}
	}
}

/*
 * TODO
 */
template <typename inT, typename outT>
bool FSM<inT, outT>::checkDuplicateStateName(std::string name)
{
	return false;
}

/*
 * sets the next State by key
 * 
 * the key value is the index in the State vector.
 * Check the index bound and change the current State
 * 
 * @param integer value of key
 * @return void / prints out error if out of bounds
 */
template <typename inT, typename outT>
void FSM<inT, outT>::setNextStateByKey(int key)
{
#ifdef DEBUG_
	std::cout << "[FSM] setNextStateByKey called: " << key << std::endl;
#endif
	pCurrState = vpState[key];
}

/*
 * sets the next State by name
 * 
 * the key value is the index in the State vector.
 * 
 * @param integer value of key
 * @return void / throws error if no such name
 */
template <typename inT, typename outT>
void FSM<inT, outT>::setNextStateByName(std::string name)
{
#ifdef DEBUG_
	std::cout << "[FSM] setNextStateByName called: " << name << std::endl;
#endif
	for (size_t key = 0; key < vpState.size(); key++)
	{
		if (name == vpState[key]->sName)
		{
			setNextStateByKey(key);
			return;
		}
	}
	std::cerr << "There is no State with such name." << std::endl;
	throw("[FSM] Non-valid name for State");
}

#endif // INCLUDE_FSM_H_