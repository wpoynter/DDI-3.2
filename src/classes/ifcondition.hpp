#ifndef IFCONDITION_HPP
#define	IFCONDITION_HPP

#include "basic.hpp"

#include "command.hpp"

class IfCondition;

typedef std::shared_ptr<IfCondition> IfConditionShPtr;
typedef std::list<IfConditionShPtr> IfConditionPtrList;


class IfCondition : public Basic {
private:
   
   CommandPtrList commands;
   
   
   BasicWkPtr parent;
public:
	IfCondition();
	~IfCondition() {}
	
	//Keep track of all objects 
	static std::list<IfConditionShPtr> all;
	static std::string type;
	
	static IfConditionShPtr create();
	static IfConditionShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	CommandPtrList get_commands();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* IFCONDITION_HPP */
