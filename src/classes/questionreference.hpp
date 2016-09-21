#ifndef QUESTIONREFERENCE_HPP
#define	QUESTIONREFERENCE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "typeofobject.hpp"

class QuestionReference;

typedef std::shared_ptr<QuestionReference> QuestionReferenceShPtr;
typedef std::list<QuestionReferenceShPtr> QuestionReferencePtrList;


class QuestionReference : public Basic {
private:
   
   URNShPtr urn;
   TypeOfObjectPtrList type_of_objects;
   
   
public:
	QuestionReference();
	~QuestionReference() {}
	
	//Keep track of all objects 
	static std::list<QuestionReferenceShPtr> all;
	
	static QuestionReferenceShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	TypeOfObjectPtrList get_type_of_objects();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* QUESTIONREFERENCE_HPP */
