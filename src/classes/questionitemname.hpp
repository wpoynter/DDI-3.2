#ifndef QUESTIONITEMNAME_HPP
#define	QUESTIONITEMNAME_HPP

#include "basic.hpp"

#include "string.hpp"

class QuestionItemName;

typedef std::shared_ptr<QuestionItemName> QuestionItemNameShPtr;
typedef std::list<QuestionItemNameShPtr> QuestionItemNamePtrList;


class QuestionItemName : public Basic {
private:
   
   StringShPtr string;
   
   
public:
	QuestionItemName();
	~QuestionItemName() {}
	
	//Keep track of all objects 
	static std::list<QuestionItemNameShPtr> all;
	
	static QuestionItemNameShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* QUESTIONITEMNAME_HPP */
