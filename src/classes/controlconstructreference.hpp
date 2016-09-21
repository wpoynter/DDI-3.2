#ifndef CONTROLCONSTRUCTREFERENCE_HPP
#define	CONTROLCONSTRUCTREFERENCE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "typeofobject.hpp"

class ControlConstructReference;

typedef std::shared_ptr<ControlConstructReference> ControlConstructReferenceShPtr;
typedef std::list<ControlConstructReferenceShPtr> ControlConstructReferencePtrList;


class ControlConstructReference : public Basic {
private:
   
   URNShPtr urn;
   TypeOfObjectPtrList type_of_objects;
   
   
public:
	ControlConstructReference();
	~ControlConstructReference() {}
	
	//Keep track of all objects 
	static std::list<ControlConstructReferenceShPtr> all;
	
	static ControlConstructReferenceShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	TypeOfObjectPtrList get_type_of_objects();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CONTROLCONSTRUCTREFERENCE_HPP */
