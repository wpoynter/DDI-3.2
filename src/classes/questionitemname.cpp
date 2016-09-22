#include "questionitemname.hpp"

std::list<QuestionItemNameShPtr> QuestionItemName::all;
std::string QuestionItemName::type = "QuestionItemName";

QuestionItemName::QuestionItemName() :
Basic() {}

QuestionItemNameShPtr QuestionItemName::create() {
	all.push_back(QuestionItemNameShPtr(new QuestionItemName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

QuestionItemNameShPtr QuestionItemName::create(BasicWkPtr _parent) {
	auto ptr = QuestionItemName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void QuestionItemName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionItemName::destroy() {
	destroy(getID());
}

BasicWkPtr QuestionItemName::get_parent() {
	return parent;
}

void QuestionItemName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string QuestionItemName::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
