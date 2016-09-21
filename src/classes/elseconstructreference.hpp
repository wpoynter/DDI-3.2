#ifndef ELSECONSTRUCTREFERENCE_HPP
#define	ELSECONSTRUCTREFERENCE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "typeofobject.hpp"

class ElseConstructReference;

typedef std::shared_ptr<ElseConstructReference> ElseConstructReferenceShPtr;
typedef std::list<ElseConstructReferenceShPtr> ElseConstructReferencePtrList;


class ElseConstructReference : public Basic {
private:
   
   URNShPtr urn;
   TypeOfObjectPtrList type_of_objects;
   
   
public:
	ElseConstructReference();
	~ElseConstructReference() {}
	
	//Keep track of all objects 
	static std::list<ElseConstructReferenceShPtr> all;
	
	static ElseConstructReferenceShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	TypeOfObjectPtrList get_type_of_objects();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* ELSECONSTRUCTREFERENCE_HPP */
