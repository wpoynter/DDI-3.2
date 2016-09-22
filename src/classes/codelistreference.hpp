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
   TypeOfObjectShPtr type_of_object;
   
   
   BasicWkPtr parent;
public:
	CodeListReference();
	~CodeListReference() {}
	
	//Keep track of all objects 
	static std::list<CodeListReferenceShPtr> all;
	static std::string type;
	
	static CodeListReferenceShPtr create();
	static CodeListReferenceShPtr create(BasicWkPtr);
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

#endif	/* CODELISTREFERENCE_HPP */
