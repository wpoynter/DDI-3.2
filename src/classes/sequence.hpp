#ifndef SEQUENCE_HPP
#define	SEQUENCE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "constructname.hpp"
#include "controlconstructreference.hpp"

class Sequence;

typedef std::shared_ptr<Sequence> SequenceShPtr;
typedef std::list<SequenceShPtr> SequencePtrList;


class Sequence : public Basic {
private:
   
   URNShPtr urn;
   ConstructNamePtrList construct_names;
   ControlConstructReferencePtrList control_construct_references;
   
   
public:
	Sequence();
	~Sequence() {}
	
	//Keep track of all objects 
	static std::list<SequenceShPtr> all;
	
	static SequenceShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	ConstructNamePtrList get_construct_names();
	ControlConstructReferencePtrList get_control_construct_references();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* SEQUENCE_HPP */
