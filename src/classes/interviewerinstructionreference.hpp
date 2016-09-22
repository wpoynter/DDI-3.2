#ifndef INTERVIEWERINSTRUCTIONREFERENCE_HPP
#define	INTERVIEWERINSTRUCTIONREFERENCE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "typeofobject.hpp"

class InterviewerInstructionReference;

typedef std::shared_ptr<InterviewerInstructionReference> InterviewerInstructionReferenceShPtr;
typedef std::list<InterviewerInstructionReferenceShPtr> InterviewerInstructionReferencePtrList;


class InterviewerInstructionReference : public Basic {
private:
   
   URNShPtr urn;
   TypeOfObjectShPtr type_of_object;
   
   
   BasicWkPtr parent;
public:
	InterviewerInstructionReference();
	~InterviewerInstructionReference() {}
	
	//Keep track of all objects 
	static std::list<InterviewerInstructionReferenceShPtr> all;
	static std::string type;
	
	static InterviewerInstructionReferenceShPtr create();
	static InterviewerInstructionReferenceShPtr create(BasicWkPtr);
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

#endif	/* INTERVIEWERINSTRUCTIONREFERENCE_HPP */
