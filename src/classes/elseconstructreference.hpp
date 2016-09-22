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
   TypeOfObjectShPtr type_of_object;
   
   
   BasicWkPtr parent;
public:
	ElseConstructReference();
	~ElseConstructReference() {}
	
	//Keep track of all objects 
	static std::list<ElseConstructReferenceShPtr> all;
	static std::string type;
	
	static ElseConstructReferenceShPtr create();
	static ElseConstructReferenceShPtr create(BasicWkPtr);
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

#endif	/* ELSECONSTRUCTREFERENCE_HPP */
