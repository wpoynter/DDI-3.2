#include "questionitemname.hpp"

std::list<QuestionItemNameShPtr> QuestionItemName::all;

QuestionItemName::QuestionItemName() :
Basic() {}

QuestionItemNameShPtr QuestionItemName::create() {
	all.push_back(QuestionItemNameShPtr(new QuestionItemName()));
	return all.back();
}

void QuestionItemName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionItemName::destroy() {
	destroy(getID());
}

StringShPtr QuestionItemName::get_string() {
	return string;
}
void QuestionItemName::set_string(StringShPtr _string) {
	string = _string;
}




void QuestionItemName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
