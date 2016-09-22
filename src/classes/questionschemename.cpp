#include "questionschemename.hpp"

std::list<QuestionSchemeNameShPtr> QuestionSchemeName::all;
std::string QuestionSchemeName::type = "QuestionSchemeName";

QuestionSchemeName::QuestionSchemeName() :
Basic() {}

QuestionSchemeNameShPtr QuestionSchemeName::create() {
	all.push_back(QuestionSchemeNameShPtr(new QuestionSchemeName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

QuestionSchemeNameShPtr QuestionSchemeName::create(BasicWkPtr _parent) {
	auto ptr = QuestionSchemeName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void QuestionSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionSchemeName::destroy() {
	destroy(getID());
}

BasicWkPtr QuestionSchemeName::get_parent() {
	return parent;
}

void QuestionSchemeName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string QuestionSchemeName::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
