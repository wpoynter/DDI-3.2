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
   TypeOfObjectShPtr type_of_object;
   
   
   BasicWkPtr parent;
public:
	ControlConstructReference();
	~ControlConstructReference() {}
	
	//Keep track of all objects 
	static std::list<ControlConstructReferenceShPtr> all;
	static std::string type;
	
	static ControlConstructReferenceShPtr create();
	static ControlConstructReferenceShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	
	TypeOfObjectShPtr get_type_of_object();
	void set_type_of_object(TypeOfObjectShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CONTROLCONSTRUCTREFERENCE_HPP */
