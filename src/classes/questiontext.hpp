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
   
public:
	QuestionText();
	~QuestionText() {}
	
	//Keep track of all objects 
	static std::list<QuestionTextShPtr> all;
	
	static QuestionTextShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	LiteralTextShPtr get_literal_text();
	void set_literal_text(LiteralTextShPtr);
	
	
	std::string get_audience_language();
	void set_audience_language(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* QUESTIONTEXT_HPP */
