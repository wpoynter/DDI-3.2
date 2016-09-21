#ifndef CODELISTREFERENCE_HPP
#define	CODELISTREFERENCE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "typeofobject.hpp"

class CodeListReference;

typedef std::shared_ptr<CodeListReference> CodeListReferenceShPtr;
typedef std::list<CodeListReferenceShPtr> CodeListReferencePtrList;


class CodeListReference : public Basic {
private:
   
   URNShPtr urn;
   TypeOfObjectPtrList type_of_objects;
   
   
public:
	CodeListReference();
	~CodeListReference() {}
	
	//Keep track of all objects 
	static std::list<CodeListReferenceShPtr> all;
	
	static CodeListReferenceShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	TypeOfObjectPtrList get_type_of_objects();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CODELISTREFERENCE_HPP */
