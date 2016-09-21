#include "instruction.hpp"

std::list<InstructionShPtr> Instruction::all;

Instruction::Instruction() :
Basic() {}

InstructionShPtr Instruction::create() {
	all.push_back(InstructionShPtr(new Instruction()));
	return all.back();
}

void Instruction::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Instruction::destroy() {
	destroy(getID());
}

URNShPtr Instruction::get_urn() {
	return urn;
}
void Instruction::set_urn(URNShPtr _urn) {
	urn = _urn;
}
InstructionTextPtrList Instruction::get_instruction_texts() {
	return instruction_texts;
}




void Instruction::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InstructionText");
		while (true) {
			instruction_texts.push_back(InstructionText::create());
			instruction_texts.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:InstructionText");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
