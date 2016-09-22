#include "value.hpp"

std::list<ValueShPtr> Value::all;
std::string Value::type = "Value";

Value::Value() :
Basic() {}

ValueShPtr Value::create() {
	all.push_back(ValueShPtr(new Value()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ValueShPtr Value::create(BasicWkPtr _parent) {
	auto ptr = Value::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Value::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Value::destroy() {
	destroy(getID());
}

BasicWkPtr Value::get_parent() {
	return parent;
}

void Value::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Value::get_type() {
	return type;
}



std::string Value::get_content() {
	return content;
}
void Value::set_content(std::string _content) {
	content = _content;
}
void Value::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
