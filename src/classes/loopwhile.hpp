#ifndef LOOPWHILE_HPP
#define	LOOPWHILE_HPP

#include "basic.hpp"

#include "command.hpp"

class LoopWhile;

typedef std::shared_ptr<LoopWhile> LoopWhileShPtr;
typedef std::list<LoopWhileShPtr> LoopWhilePtrList;


class LoopWhile : public Basic {
private:
   
   CommandPtrList commands;
   
   
public:
	LoopWhile();
	~LoopWhile() {}
	
	//Keep track of all objects 
	static std::list<LoopWhileShPtr> all;
	
	static LoopWhileShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	CommandPtrList get_commands();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* LOOPWHILE_HPP */
