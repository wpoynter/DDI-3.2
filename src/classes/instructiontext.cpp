#include "instructiontext.hpp"

std::list<InstructionTextShPtr> InstructionText::all;
std::string InstructionText::type = "InstructionText";

InstructionText::InstructionText() :
Basic() {}

InstructionTextShPtr InstructionText::create() {
	all.push_back(InstructionTextShPtr(new InstructionText()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InstructionTextShPtr InstructionText::create(BasicWkPtr _parent) {
	auto ptr = InstructionText::create();
	ptr->set_parent(_parent);
	return ptr;
}

void InstructionText::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InstructionText::destroy() {
	destroy(getID());
}

BasicWkPtr InstructionText::get_parent() {
	return parent;
}

void InstructionText::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string InstructionText::get_type() {
	return type;
}

LiteralTextShPtr InstructionText::get_literal_text() {
	return literal_text;
}
void InstructionText::set_literal_text(LiteralTextShPtr _literal_text) {
	literal_text = _literal_text;
}
std::string InstructionText::get_audience_language() {
	return audience_language;
}
void InstructionText::set_audience_language(std::string _audience_language) {
	audience_language = _audience_language;
}


void InstructionText::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "audienceLanguage", &audience_language, false);
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:LiteralText");
		literal_text = LiteralText::create(shared_from_this());
		literal_text->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
