#include "questiongridname.hpp"

std::list<QuestionGridNameShPtr> QuestionGridName::all;
std::string QuestionGridName::type = "QuestionGridName";

QuestionGridName::QuestionGridName() :
Basic() {}

QuestionGridNameShPtr QuestionGridName::create() {
	all.push_back(QuestionGridNameShPtr(new QuestionGridName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

QuestionGridNameShPtr QuestionGridName::create(BasicWkPtr _parent) {
	auto ptr = QuestionGridName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void QuestionGridName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionGridName::destroy() {
	destroy(getID());
}

BasicWkPtr QuestionGridName::get_parent() {
	return parent;
}

void QuestionGridName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string QuestionGridName::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
