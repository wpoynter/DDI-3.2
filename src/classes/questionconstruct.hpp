#ifndef QUESTIONCONSTRUCT_HPP
#define	QUESTIONCONSTRUCT_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "constructname.hpp"
#include "label.hpp"
#include "questionreference.hpp"
#include "responseunit.hpp"

class QuestionConstruct;

typedef std::shared_ptr<QuestionConstruct> QuestionConstructShPtr;
typedef std::list<QuestionConstructShPtr> QuestionConstructPtrList;


class QuestionConstruct : public Basic {
private:
   
   URNShPtr urn;
   ConstructNamePtrList construct_names;
   LabelPtrList labels;
   QuestionReferencePtrList question_references;
   ResponseUnitPtrList response_units;
   
   
public:
	QuestionConstruct();
	~QuestionConstruct() {}
	
	//Keep track of all objects 
	static std::list<QuestionConstructShPtr> all;
	
	static QuestionConstructShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	ConstructNamePtrList get_construct_names();
	LabelPtrList get_labels();
	QuestionReferencePtrList get_question_references();
	ResponseUnitPtrList get_response_units();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* QUESTIONCONSTRUCT_HPP */
