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
   TypeOfObjectShPtr type_of_object;
   
   
   BasicWkPtr parent;
public:
	QuestionReference();
	~QuestionReference() {}
	
	//Keep track of all objects 
	static std::list<QuestionReferenceShPtr> all;
	static std::string type;
	
	static QuestionReferenceShPtr create();
	static QuestionReferenceShPtr create(BasicWkPtr);
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

#endif	/* QUESTIONREFERENCE_HPP */
