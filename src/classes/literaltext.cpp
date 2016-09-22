#include "literaltext.hpp"

std::list<LiteralTextShPtr> LiteralText::all;
std::string LiteralText::type = "LiteralText";

LiteralText::LiteralText() :
Basic() {}

LiteralTextShPtr LiteralText::create() {
	all.push_back(LiteralTextShPtr(new LiteralText()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

LiteralTextShPtr LiteralText::create(BasicWkPtr _parent) {
	auto ptr = LiteralText::create();
	ptr->set_parent(_parent);
	return ptr;
}

void LiteralText::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void LiteralText::destroy() {
	destroy(getID());
}

BasicWkPtr LiteralText::get_parent() {
	return parent;
}

void LiteralText::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string LiteralText::get_type() {
	return type;
}

TextShPtr LiteralText::get_text() {
	return text;
}
void LiteralText::set_text(TextShPtr _text) {
	text = _text;
}




void LiteralText::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:Text");
		text = Text::create(shared_from_this());
		text->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
