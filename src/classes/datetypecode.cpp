#include "datetypecode.hpp"

std::list<DateTypeCodeShPtr> DateTypeCode::all;
std::string DateTypeCode::type = "DateTypeCode";

DateTypeCode::DateTypeCode() :
Basic() {}

DateTypeCodeShPtr DateTypeCode::create() {
	all.push_back(DateTypeCodeShPtr(new DateTypeCode()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

DateTypeCodeShPtr DateTypeCode::create(BasicWkPtr _parent) {
	auto ptr = DateTypeCode::create();
	ptr->set_parent(_parent);
	return ptr;
}

void DateTypeCode::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DateTypeCode::destroy() {
	destroy(getID());
}

BasicWkPtr DateTypeCode::get_parent() {
	return parent;
}

void DateTypeCode::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string DateTypeCode::get_type() {
	return type;
}



std::string DateTypeCode::get_content() {
	return content;
}
void DateTypeCode::set_content(std::string _content) {
	content = _content;
}
void DateTypeCode::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
