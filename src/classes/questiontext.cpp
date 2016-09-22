#include "questiontext.hpp"

std::list<QuestionTextShPtr> QuestionText::all;
std::string QuestionText::type = "QuestionText";

QuestionText::QuestionText() :
Basic() {}

QuestionTextShPtr QuestionText::create() {
	all.push_back(QuestionTextShPtr(new QuestionText()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

QuestionTextShPtr QuestionText::create(BasicWkPtr _parent) {
	auto ptr = QuestionText::create();
	ptr->set_parent(_parent);
	return ptr;
}

void QuestionText::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionText::destroy() {
	destroy(getID());
}

BasicWkPtr QuestionText::get_parent() {
	return parent;
}

void QuestionText::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string QuestionText::get_type() {
	return type;
}

LiteralTextShPtr QuestionText::get_literal_text() {
	return literal_text;
}
void QuestionText::set_literal_text(LiteralTextShPtr _literal_text) {
	literal_text = _literal_text;
}
std::string QuestionText::get_audience_language() {
	return audience_language;
}
void QuestionText::set_audience_language(std::string _audience_language) {
	audience_language = _audience_language;
}


void QuestionText::read_element(ticpp::Element* elem) {
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
