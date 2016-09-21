#include "questiongridname.hpp"

std::list<QuestionGridNameShPtr> QuestionGridName::all;

QuestionGridName::QuestionGridName() :
Basic() {}

QuestionGridNameShPtr QuestionGridName::create() {
	all.push_back(QuestionGridNameShPtr(new QuestionGridName()));
	return all.back();
}

void QuestionGridName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionGridName::destroy() {
	destroy(getID());
}

StringShPtr QuestionGridName::get_string() {
	return string;
}
void QuestionGridName::set_string(StringShPtr _string) {
	string = _string;
}




void QuestionGridName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
