#ifndef QUESTIONSCHEME_HPP
#define	QUESTIONSCHEME_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "questionschemename.hpp"
#include "questionitem.hpp"
#include "questiongrid.hpp"

class QuestionScheme;

typedef std::shared_ptr<QuestionScheme> QuestionSchemeShPtr;
typedef std::list<QuestionSchemeShPtr> QuestionSchemePtrList;


class QuestionScheme : public Basic {
private:
   
   URNShPtr urn;
   QuestionSchemeNamePtrList question_scheme_names;
   QuestionItemPtrList question_items;
   QuestionGridPtrList question_grids;
   std::string version_date;
   
public:
	QuestionScheme();
	~QuestionScheme() {}
	
	//Keep track of all objects 
	static std::list<QuestionSchemeShPtr> all;
	
	static QuestionSchemeShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	QuestionSchemeNamePtrList get_question_scheme_names();
	QuestionItemPtrList get_question_items();
	QuestionGridPtrList get_question_grids();
	
	std::string get_version_date();
	void set_version_date(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* QUESTIONSCHEME_HPP */
