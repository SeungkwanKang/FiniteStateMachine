#ifndef INCLUDE_STATE_H_
#define INCLUDE_STATE_H_

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

private: // Internals
	State *pParent;

private: // Identification related
	int iKey;
	std::string sName;
	bool isStartState;

private: // Function related
	std::function<std::string(State<int, std::string> *, int)> *pFunc;
	bool isLocked = false;

private: // Input related
	outT giveInput(inT input);
	void callStateByKey(int key);
	void callStateByName(std::string name);

public: // Initialization related
	State();
	~State();
	void setName(std::string name);
	void setFunction(std::function<std::string(State<int, std::string> *, int)> *);
	void setAsStartState();
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
	iKey = -1;
	sName = "";
	isStartState = false;
	std::cout << "Constructor" << std::endl;
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
	std::cout << "Deconstructor" << std::endl;
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
	if (!isLocked)
		sName = name;
	else
		std::cerr << "The state is locked. You should not modify the state after FSM running." << std::endl;
}

/*
 * setFunction of State class
 * 
 * Checks whether the instance is locked and changes the function
 * 
 * @param function pointer of new function
 * @return void / prints out error if locked
 */
template <typename inT, typename outT>
void State<inT, outT>::setFunction(std::function<std::string(State<int, std::string> *, int)> *func)
{
	if (!isLocked)
		pFunc = func;
	else
		std::cerr << "The state is locked. You should not modify the state after FSM running." << std::endl;
}

template <typename inT, typename outT>
void State<inT, outT>::setAsStartState()
{
	isStartState = true;
}

template <typename inT, typename outT>
outT State<inT, outT>::giveInput(inT input)
{
	return pFunc->operator()(this, input);
};

/*
 * calls the next state by key
 * 
 * Checks whether the parent (FSM) is set and modifies its next state
 * 
 * @param integer value of key
 * @return void / prints out error if parent not set
 */
template <typename inT, typename outT>
void State<inT, outT>::callStateByKey(int key)
{
	if (pParent != NULL)
		pParent->setNextStateByKey(key);
	else
		std::cerr << "Please load the state first." << std::endl;
	
}

/*
 * calls the next state by name
 * 
 * Checks whether the parent (FSM) is set and modifies its next state
 * 
 * @param std::string value of name
 * @return void / prints out error if parent not set
 */
template <typename inT, typename outT>
void State<inT, outT>::callStateByName(std::string name)
{
	{
		if (pParent != NULL)
			pParent->setNextStateByName(name);
		else
			std::cerr << "Please load the state first." << std::endl;
	}
}

#endif // INCLUDE_STATE_H_