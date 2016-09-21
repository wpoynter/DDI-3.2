#include "displaytext.hpp"

std::list<DisplayTextShPtr> DisplayText::all;

DisplayText::DisplayText() :
Basic() {}

DisplayTextShPtr DisplayText::create() {
	all.push_back(DisplayTextShPtr(new DisplayText()));
	return all.back();
}

void DisplayText::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DisplayText::destroy() {
	destroy(getID());
}

LiteralTextShPtr DisplayText::get_literal_text() {
	return literal_text;
}
void DisplayText::set_literal_text(LiteralTextShPtr _literal_text) {
	literal_text = _literal_text;
}
std::string DisplayText::get_audience_language() {
	return audience_language;
}
void DisplayText::set_audience_language(std::string _audience_language) {
	audience_language = _audience_language;
}


void DisplayText::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "audienceLanguage", &audience_language, false);
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:LiteralText");
		literal_text = LiteralText::create();
		literal_text->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
