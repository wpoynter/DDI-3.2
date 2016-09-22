#ifndef QUESTIONTEXT_HPP
#define	QUESTIONTEXT_HPP

#include "basic.hpp"

#include "literaltext.hpp"

class QuestionText;

typedef std::shared_ptr<QuestionText> QuestionTextShPtr;
typedef std::list<QuestionTextShPtr> QuestionTextPtrList;


class QuestionText : public Basic {
private:
   
   LiteralTextShPtr literal_text;
   std::string audience_language;
   
   BasicWkPtr parent;
public:
	QuestionText();
	~QuestionText() {}
	
	//Keep track of all objects 
	static std::list<QuestionTextShPtr> all;
	static std::string type;
	
	static QuestionTextShPtr create();
	static QuestionTextShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	LiteralTextShPtr get_literal_text();
	void set_literal_text(LiteralTextShPtr);
	
	
	std::string get_audience_language();
	void set_audience_language(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* QUESTIONTEXT_HPP */
