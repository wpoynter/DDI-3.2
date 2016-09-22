#ifndef QUESTIONGRIDNAME_HPP
#define	QUESTIONGRIDNAME_HPP

#include "basic.hpp"

#include "string.hpp"

class QuestionGridName;

typedef std::shared_ptr<QuestionGridName> QuestionGridNameShPtr;
typedef std::list<QuestionGridNameShPtr> QuestionGridNamePtrList;


class QuestionGridName : public Basic {
private:
   
   StringShPtr string;
   
   
   BasicWkPtr parent;
public:
	QuestionGridName();
	~QuestionGridName() {}
	
	//Keep track of all objects 
	static std::list<QuestionGridNameShPtr> all;
	static std::string type;
	
	static QuestionGridNameShPtr create();
	static QuestionGridNameShPtr create(BasicWkPtr);
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

#endif	/* QUESTIONGRIDNAME_HPP */
