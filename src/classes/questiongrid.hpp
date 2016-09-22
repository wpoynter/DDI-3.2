#ifndef QUESTIONGRID_HPP
#define	QUESTIONGRID_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "userattributepair.hpp"
#include "questiongridname.hpp"
#include "questiontext.hpp"
#include "griddimension.hpp"
#include "codedomain.hpp"
#include "structuredmixedgridresponsedomain.hpp"
#include "interviewerinstructionreference.hpp"
#include "numericdomain.hpp"
#include "textdomain.hpp"

class QuestionGrid;

typedef std::shared_ptr<QuestionGrid> QuestionGridShPtr;
typedef std::list<QuestionGridShPtr> QuestionGridPtrList;


class QuestionGrid : public Basic {
private:
   
   URNShPtr urn;
   UserAttributePairPtrList user_attribute_pairs;
   QuestionGridNamePtrList question_grid_names;
   QuestionTextPtrList question_texts;
   GridDimensionPtrList grid_dimensions;
   CodeDomainPtrList code_domains;
   StructuredMixedGridResponseDomainPtrList structured_mixed_grid_response_domains;
   InterviewerInstructionReferencePtrList interviewer_instruction_references;
   NumericDomainPtrList numeric_domains;
   TextDomainPtrList text_domains;
   
   
   BasicWkPtr parent;
public:
	QuestionGrid();
	~QuestionGrid() {}
	
	//Keep track of all objects 
	static std::list<QuestionGridShPtr> all;
	static std::string type;
	
	static QuestionGridShPtr create();
	static QuestionGridShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	UserAttributePairPtrList get_user_attribute_pairs();
	QuestionGridNamePtrList get_question_grid_names();
	QuestionTextPtrList get_question_texts();
	GridDimensionPtrList get_grid_dimensions();
	CodeDomainPtrList get_code_domains();
	StructuredMixedGridResponseDomainPtrList get_structured_mixed_grid_response_domains();
	InterviewerInstructionReferencePtrList get_interviewer_instruction_references();
	NumericDomainPtrList get_numeric_domains();
	TextDomainPtrList get_text_domains();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* QUESTIONGRID_HPP */
