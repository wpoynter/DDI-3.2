#include "numerictypecode.hpp"

std::list<NumericTypeCodeShPtr> NumericTypeCode::all;
std::string NumericTypeCode::type = "NumericTypeCode";

NumericTypeCode::NumericTypeCode() :
Basic() {}

NumericTypeCodeShPtr NumericTypeCode::create() {
	all.push_back(NumericTypeCodeShPtr(new NumericTypeCode()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

NumericTypeCodeShPtr NumericTypeCode::create(BasicWkPtr _parent) {
	auto ptr = NumericTypeCode::create();
	ptr->set_parent(_parent);
	return ptr;
}

void NumericTypeCode::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void NumericTypeCode::destroy() {
	destroy(getID());
}

BasicWkPtr NumericTypeCode::get_parent() {
	return parent;
}

void NumericTypeCode::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string NumericTypeCode::get_type() {
	return type;
}



std::string NumericTypeCode::get_content() {
	return content;
}
void NumericTypeCode::set_content(std::string _content) {
	content = _content;
}
void NumericTypeCode::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
