#ifndef LITERALTEXT_HPP
#define	LITERALTEXT_HPP

#include "basic.hpp"

#include "text.hpp"

class LiteralText;

typedef std::shared_ptr<LiteralText> LiteralTextShPtr;
typedef std::list<LiteralTextShPtr> LiteralTextPtrList;


class LiteralText : public Basic {
private:
   
   TextShPtr text;
   
   
   BasicWkPtr parent;
public:
	LiteralText();
	~LiteralText() {}
	
	//Keep track of all objects 
	static std::list<LiteralTextShPtr> all;
	static std::string type;
	
	static LiteralTextShPtr create();
	static LiteralTextShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	TextShPtr get_text();
	void set_text(TextShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* LITERALTEXT_HPP */
