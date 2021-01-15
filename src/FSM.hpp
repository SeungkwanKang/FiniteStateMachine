#ifndef INCLUDE_FSM_H_
#define INCLUDE_FSM_H_

#include "State.hpp"

template <typename inT, typename outT> class State;

template <typename inT, typename outT>
class FSM
{
	friend State<inT, outT>;

private:
	State<inT, outT>* pCurrState;
	std::vector<State<inT, outT> *> vpState;

private: // Setting the next state
	void setNextStateByKey(int key);
	void convertNameToKey(std::string name);
	void setNextStateByName(std::string name);

public : FSM();
	~FSM();
};

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