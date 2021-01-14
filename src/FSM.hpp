#ifndef INCLUDE_FSM_H_
#define INCLUDE_FSM_H_

#include "State.hpp"

template <typename inT, typename outT> class State;

template <typename inT, typename outT>
class FSM
{
	friend State<inT, outT>;

private:
	std::vector<State<inT, outT>*> vStates;
	void setNext(int iKey);
public:
	FSM();
	~FSM();
};

#endif // INCLUDE_FSM_H_