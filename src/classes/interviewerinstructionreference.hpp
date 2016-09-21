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
   TypeOfObjectPtrList type_of_objects;
   
   
public:
	InterviewerInstructionReference();
	~InterviewerInstructionReference() {}
	
	//Keep track of all objects 
	static std::list<InterviewerInstructionReferenceShPtr> all;
	
	static InterviewerInstructionReferenceShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	TypeOfObjectPtrList get_type_of_objects();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INTERVIEWERINSTRUCTIONREFERENCE_HPP */
