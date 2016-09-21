#ifndef INTERVIEWERINSTRUCTIONSCHEME_HPP
#define	INTERVIEWERINSTRUCTIONSCHEME_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "interviewerinstructionschemename.hpp"
#include "instruction.hpp"

class InterviewerInstructionScheme;

typedef std::shared_ptr<InterviewerInstructionScheme> InterviewerInstructionSchemeShPtr;
typedef std::list<InterviewerInstructionSchemeShPtr> InterviewerInstructionSchemePtrList;


class InterviewerInstructionScheme : public Basic {
private:
   
   URNShPtr urn;
   InterviewerInstructionSchemeNamePtrList interviewer_instruction_scheme_names;
   InstructionPtrList instructions;
   std::string version_date;
   
public:
	InterviewerInstructionScheme();
	~InterviewerInstructionScheme() {}
	
	//Keep track of all objects 
	static std::list<InterviewerInstructionSchemeShPtr> all;
	
	static InterviewerInstructionSchemeShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	InterviewerInstructionSchemeNamePtrList get_interviewer_instruction_scheme_names();
	InstructionPtrList get_instructions();
	
	std::string get_version_date();
	void set_version_date(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INTERVIEWERINSTRUCTIONSCHEME_HPP */
