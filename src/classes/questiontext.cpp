#include "questiontext.hpp"

std::list<QuestionTextShPtr> QuestionText::all;

QuestionText::QuestionText() :
Basic() {}

QuestionTextShPtr QuestionText::create() {
	all.push_back(QuestionTextShPtr(new QuestionText()));
	return all.back();
}

void QuestionText::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionText::destroy() {
	destroy(getID());
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
		literal_text = LiteralText::create();
		literal_text->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
