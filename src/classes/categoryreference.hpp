#ifndef CATEGORYREFERENCE_HPP
#define	CATEGORYREFERENCE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "typeofobject.hpp"

class CategoryReference;

typedef std::shared_ptr<CategoryReference> CategoryReferenceShPtr;
typedef std::list<CategoryReferenceShPtr> CategoryReferencePtrList;


class CategoryReference : public Basic {
private:
   
   URNShPtr urn;
   TypeOfObjectPtrList type_of_objects;
   
   
public:
	CategoryReference();
	~CategoryReference() {}
	
	//Keep track of all objects 
	static std::list<CategoryReferenceShPtr> all;
	
	static CategoryReferenceShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	TypeOfObjectPtrList get_type_of_objects();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CATEGORYREFERENCE_HPP */
