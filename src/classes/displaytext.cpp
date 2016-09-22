#include "displaytext.hpp"

std::list<DisplayTextShPtr> DisplayText::all;
std::string DisplayText::type = "DisplayText";

DisplayText::DisplayText() :
Basic() {}

DisplayTextShPtr DisplayText::create() {
	all.push_back(DisplayTextShPtr(new DisplayText()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

DisplayTextShPtr DisplayText::create(BasicWkPtr _parent) {
	auto ptr = DisplayText::create();
	ptr->set_parent(_parent);
	return ptr;
}

void DisplayText::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DisplayText::destroy() {
	destroy(getID());
}

BasicWkPtr DisplayText::get_parent() {
	return parent;
}

void DisplayText::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string DisplayText::get_type() {
	return type;
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
		literal_text = LiteralText::create(shared_from_this());
		literal_text->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
