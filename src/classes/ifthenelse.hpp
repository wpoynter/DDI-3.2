#ifndef IFTHENELSE_HPP
#define	IFTHENELSE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "constructname.hpp"
#include "ifcondition.hpp"
#include "thenconstructreference.hpp"
#include "elseconstructreference.hpp"

class IfThenElse;

typedef std::shared_ptr<IfThenElse> IfThenElseShPtr;
typedef std::list<IfThenElseShPtr> IfThenElsePtrList;


class IfThenElse : public Basic {
private:
   
   URNShPtr urn;
   ConstructNamePtrList construct_names;
   IfConditionPtrList if_conditions;
   ThenConstructReferencePtrList then_construct_references;
   ElseConstructReferencePtrList else_construct_references;
   
   
public:
	IfThenElse();
	~IfThenElse() {}
	
	//Keep track of all objects 
	static std::list<IfThenElseShPtr> all;
	
	static IfThenElseShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	ConstructNamePtrList get_construct_names();
	IfConditionPtrList get_if_conditions();
	ThenConstructReferencePtrList get_then_construct_references();
	ElseConstructReferencePtrList get_else_construct_references();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* IFTHENELSE_HPP */
