#ifndef LOOP_HPP
#define	LOOP_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "constructname.hpp"
#include "initialvalue.hpp"
#include "loopwhile.hpp"
#include "controlconstructreference.hpp"

class Loop;

typedef std::shared_ptr<Loop> LoopShPtr;
typedef std::list<LoopShPtr> LoopPtrList;


class Loop : public Basic {
private:
   
   URNShPtr urn;
   ConstructNamePtrList construct_names;
   InitialValuePtrList initial_values;
   LoopWhilePtrList loop_whiles;
   ControlConstructReferencePtrList control_construct_references;
   
   
   BasicWkPtr parent;
public:
	Loop();
	~Loop() {}
	
	//Keep track of all objects 
	static std::list<LoopShPtr> all;
	static std::string type;
	
	static LoopShPtr create();
	static LoopShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	ConstructNamePtrList get_construct_names();
	InitialValuePtrList get_initial_values();
	LoopWhilePtrList get_loop_whiles();
	ControlConstructReferencePtrList get_control_construct_references();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* LOOP_HPP */
