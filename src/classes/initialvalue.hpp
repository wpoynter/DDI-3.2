#ifndef INITIALVALUE_HPP
#define	INITIALVALUE_HPP

#include "basic.hpp"

#include "command.hpp"

class InitialValue;

typedef std::shared_ptr<InitialValue> InitialValueShPtr;
typedef std::list<InitialValueShPtr> InitialValuePtrList;


class InitialValue : public Basic {
private:
   
   CommandPtrList commands;
   
   
public:
	InitialValue();
	~InitialValue() {}
	
	//Keep track of all objects 
	static std::list<InitialValueShPtr> all;
	
	static InitialValueShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	CommandPtrList get_commands();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INITIALVALUE_HPP */
