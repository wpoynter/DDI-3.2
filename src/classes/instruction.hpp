#ifndef INSTRUCTION_HPP
#define	INSTRUCTION_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "instructiontext.hpp"

class Instruction;

typedef std::shared_ptr<Instruction> InstructionShPtr;
typedef std::list<InstructionShPtr> InstructionPtrList;


class Instruction : public Basic {
private:
   
   URNShPtr urn;
   InstructionTextPtrList instruction_texts;
   
   
   BasicWkPtr parent;
public:
	Instruction();
	~Instruction() {}
	
	//Keep track of all objects 
	static std::list<InstructionShPtr> all;
	static std::string type;
	
	static InstructionShPtr create();
	static InstructionShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	InstructionTextPtrList get_instruction_texts();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INSTRUCTION_HPP */
