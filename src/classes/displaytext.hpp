#ifndef DISPLAYTEXT_HPP
#define	DISPLAYTEXT_HPP

#include "basic.hpp"

#include "literaltext.hpp"

class DisplayText;

typedef std::shared_ptr<DisplayText> DisplayTextShPtr;
typedef std::list<DisplayTextShPtr> DisplayTextPtrList;


class DisplayText : public Basic {
private:
   
   LiteralTextShPtr literal_text;
   std::string audience_language;
   
   BasicWkPtr parent;
public:
	DisplayText();
	~DisplayText() {}
	
	//Keep track of all objects 
	static std::list<DisplayTextShPtr> all;
	static std::string type;
	
	static DisplayTextShPtr create();
	static DisplayTextShPtr create(BasicWkPtr);
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

#endif	/* DISPLAYTEXT_HPP */
