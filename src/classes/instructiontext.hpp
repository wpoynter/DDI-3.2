#ifndef INSTRUCTIONTEXT_HPP
#define	INSTRUCTIONTEXT_HPP

#include "basic.hpp"

#include "literaltext.hpp"

class InstructionText;

typedef std::shared_ptr<InstructionText> InstructionTextShPtr;
typedef std::list<InstructionTextShPtr> InstructionTextPtrList;


class InstructionText : public Basic {
private:
   
   LiteralTextShPtr literal_text;
   std::string audience_language;
   
public:
	InstructionText();
	~InstructionText() {}
	
	//Keep track of all objects 
	static std::list<InstructionTextShPtr> all;
	
	static InstructionTextShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	LiteralTextShPtr get_literal_text();
	void set_literal_text(LiteralTextShPtr);
	
	
	std::string get_audience_language();
	void set_audience_language(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INSTRUCTIONTEXT_HPP */
