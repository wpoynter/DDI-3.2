#include "instruction.hpp"

std::list<InstructionShPtr> Instruction::all;
std::string Instruction::type = "Instruction";

Instruction::Instruction() :
Basic() {}

InstructionShPtr Instruction::create() {
	all.push_back(InstructionShPtr(new Instruction()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InstructionShPtr Instruction::create(BasicWkPtr _parent) {
	auto ptr = Instruction::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Instruction::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Instruction::destroy() {
	destroy(getID());
}

BasicWkPtr Instruction::get_parent() {
	return parent;
}

void Instruction::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Instruction::get_type() {
	return type;
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
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InstructionText");
		while (true) {
			instruction_texts.push_back(InstructionText::create(shared_from_this()));
			instruction_texts.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:InstructionText");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
