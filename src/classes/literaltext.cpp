#include "literaltext.hpp"

std::list<LiteralTextShPtr> LiteralText::all;

LiteralText::LiteralText() :
Basic() {}

LiteralTextShPtr LiteralText::create() {
	all.push_back(LiteralTextShPtr(new LiteralText()));
	return all.back();
}

void LiteralText::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void LiteralText::destroy() {
	destroy(getID());
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
		text = Text::create();
		text->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
