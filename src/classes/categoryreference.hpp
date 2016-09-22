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
   TypeOfObjectShPtr type_of_object;
   
   
   BasicWkPtr parent;
public:
	CategoryReference();
	~CategoryReference() {}
	
	//Keep track of all objects 
	static std::list<CategoryReferenceShPtr> all;
	static std::string type;
	
	static CategoryReferenceShPtr create();
	static CategoryReferenceShPtr create(BasicWkPtr);
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

#endif	/* CATEGORYREFERENCE_HPP */
