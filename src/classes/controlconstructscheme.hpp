#ifndef CONTROLCONSTRUCTSCHEME_HPP
#define	CONTROLCONSTRUCTSCHEME_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "controlconstructschemename.hpp"
#include "sequence.hpp"
#include "statementitem.hpp"
#include "questionconstruct.hpp"
#include "ifthenelse.hpp"
#include "loop.hpp"

class ControlConstructScheme;

typedef std::shared_ptr<ControlConstructScheme> ControlConstructSchemeShPtr;
typedef std::list<ControlConstructSchemeShPtr> ControlConstructSchemePtrList;


class ControlConstructScheme : public Basic {
private:
   
   URNShPtr urn;
   ControlConstructSchemeNamePtrList control_construct_scheme_names;
   SequencePtrList sequences;
   StatementItemPtrList statement_items;
   QuestionConstructPtrList question_constructs;
   IfThenElsePtrList if_then_elses;
   LoopPtrList loops;
   
   
public:
	ControlConstructScheme();
	~ControlConstructScheme() {}
	
	//Keep track of all objects 
	static std::list<ControlConstructSchemeShPtr> all;
	
	static ControlConstructSchemeShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	ControlConstructSchemeNamePtrList get_control_construct_scheme_names();
	SequencePtrList get_sequences();
	StatementItemPtrList get_statement_items();
	QuestionConstructPtrList get_question_constructs();
	IfThenElsePtrList get_if_then_elses();
	LoopPtrList get_loops();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CONTROLCONSTRUCTSCHEME_HPP */
