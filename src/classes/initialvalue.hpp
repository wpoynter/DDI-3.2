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
   
   
   BasicWkPtr parent;
public:
	InitialValue();
	~InitialValue() {}
	
	//Keep track of all objects 
	static std::list<InitialValueShPtr> all;
	static std::string type;
	
	static InitialValueShPtr create();
	static InitialValueShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	CommandPtrList get_commands();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INITIALVALUE_HPP */
