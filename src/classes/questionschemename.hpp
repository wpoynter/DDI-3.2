#ifndef QUESTIONSCHEMENAME_HPP
#define	QUESTIONSCHEMENAME_HPP

#include "basic.hpp"

#include "string.hpp"

class QuestionSchemeName;

typedef std::shared_ptr<QuestionSchemeName> QuestionSchemeNameShPtr;
typedef std::list<QuestionSchemeNameShPtr> QuestionSchemeNamePtrList;


class QuestionSchemeName : public Basic {
private:
   
   StringShPtr string;
   
   
   BasicWkPtr parent;
public:
	QuestionSchemeName();
	~QuestionSchemeName() {}
	
	//Keep track of all objects 
	static std::list<QuestionSchemeNameShPtr> all;
	static std::string type;
	
	static QuestionSchemeNameShPtr create();
	static QuestionSchemeNameShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* QUESTIONSCHEMENAME_HPP */
