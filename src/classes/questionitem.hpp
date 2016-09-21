#ifndef QUESTIONITEM_HPP
#define	QUESTIONITEM_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "userattributepair.hpp"
#include "questionitemname.hpp"
#include "questiontext.hpp"
#include "codedomain.hpp"
#include "structuredmixedresponsedomain.hpp"
#include "numericdomain.hpp"
#include "datetimedomain.hpp"
#include "interviewerinstructionreference.hpp"
#include "textdomain.hpp"

class QuestionItem;

typedef std::shared_ptr<QuestionItem> QuestionItemShPtr;
typedef std::list<QuestionItemShPtr> QuestionItemPtrList;


class QuestionItem : public Basic {
private:
   
   URNShPtr urn;
   UserAttributePairPtrList user_attribute_pairs;
   QuestionItemNamePtrList question_item_names;
   QuestionTextPtrList question_texts;
   CodeDomainPtrList code_domains;
   StructuredMixedResponseDomainPtrList structured_mixed_response_domains;
   NumericDomainPtrList numeric_domains;
   DateTimeDomainPtrList date_time_domains;
   InterviewerInstructionReferencePtrList interviewer_instruction_references;
   TextDomainPtrList text_domains;
   
   
public:
	QuestionItem();
	~QuestionItem() {}
	
	//Keep track of all objects 
	static std::list<QuestionItemShPtr> all;
	
	static QuestionItemShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	UserAttributePairPtrList get_user_attribute_pairs();
	QuestionItemNamePtrList get_question_item_names();
	QuestionTextPtrList get_question_texts();
	CodeDomainPtrList get_code_domains();
	StructuredMixedResponseDomainPtrList get_structured_mixed_response_domains();
	NumericDomainPtrList get_numeric_domains();
	DateTimeDomainPtrList get_date_time_domains();
	InterviewerInstructionReferencePtrList get_interviewer_instruction_references();
	TextDomainPtrList get_text_domains();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* QUESTIONITEM_HPP */
