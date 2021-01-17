#ifndef INCLUDE_FSM_H_
#define INCLUDE_FSM_H_

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

private:
	bool isLocked;

private:
	State<inT, outT>* pCurrState;
	std::vector<State<inT, outT> *> vpState;

private: // Setting the next state
	void setNextStateByKey(int key);
	void convertNameToKey(std::string name);
	void setNextStateByName(std::string name);

public: // Initialization related
	FSM();
	~FSM();
	void addState(State<inT, outT> *state);

public:
	outT operator()(inT input);
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
}

/*
 * adds new State to FSM
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
	if (pstate->iKey != -1)
	{ // Addind same state again
		std::cerr << "Adding same State multiple times." << std::endl;
		throw("[FSM] Multiple addition of State instance");
	}

	pstate->isLocked = true;
	pstate->iKey = (int)vpState.size();
	vpState.push_back(pstate);
	if (pstate->isStartState)
		pCurrState = pstate;
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
outT FSM<inT, outT>::operator()(inT input)
{
	if (pCurrState == nullptr)
	{
		std::cerr << "There was no start State given. Add a start State." << std::endl;
		throw("No start State error");
	}
	return pCurrState->giveInput(input);
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
	pCurrState = vpState[key];
}

/*
 * sets the next State by name
 * 
 * the key value is the index in the State vector.
 * TODO
 * 
 * @param integer value of key
 * @return void / prints out error if out of bounds
 */
template <typename inT, typename outT>
void FSM<inT, outT>::convertNameToKey(std::string name)
{
	for (size_t key = 0; key < vpState.length(); key++)
	{
		if (name == vpState[key]->sName)
		{
			setNextStateByKey(key);
		}
	}
	std::cerr << "There is no State with such name." << std::endl;
}

template <typename inT, typename outT>
void FSM<inT, outT>::setNextStateByName(std::string name)
{
	return; // TODO
}

#endif // INCLUDE_FSM_H_