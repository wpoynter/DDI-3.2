#include "questionschemename.hpp"

std::list<QuestionSchemeNameShPtr> QuestionSchemeName::all;

QuestionSchemeName::QuestionSchemeName() :
Basic() {}

QuestionSchemeNameShPtr QuestionSchemeName::create() {
	all.push_back(QuestionSchemeNameShPtr(new QuestionSchemeName()));
	return all.back();
}

void QuestionSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionSchemeName::destroy() {
	destroy(getID());
}

StringShPtr QuestionSchemeName::get_string() {
	return string;
}
void QuestionSchemeName::set_string(StringShPtr _string) {
	string = _string;
}




void QuestionSchemeName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
