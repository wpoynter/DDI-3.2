#ifndef INTERVIEWERINSTRUCTIONSCHEMENAME_HPP
#define	INTERVIEWERINSTRUCTIONSCHEMENAME_HPP

#include "basic.hpp"

#include "string.hpp"

class InterviewerInstructionSchemeName;

typedef std::shared_ptr<InterviewerInstructionSchemeName> InterviewerInstructionSchemeNameShPtr;
typedef std::list<InterviewerInstructionSchemeNameShPtr> InterviewerInstructionSchemeNamePtrList;


class InterviewerInstructionSchemeName : public Basic {
private:
   
   StringShPtr string;
   
   
public:
	InterviewerInstructionSchemeName();
	~InterviewerInstructionSchemeName() {}
	
	//Keep track of all objects 
	static std::list<InterviewerInstructionSchemeNameShPtr> all;
	
	static InterviewerInstructionSchemeNameShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INTERVIEWERINSTRUCTIONSCHEMENAME_HPP */
