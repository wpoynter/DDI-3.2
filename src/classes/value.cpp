#include "value.hpp"

std::list<ValueShPtr> Value::all;

Value::Value() :
Basic() {}

ValueShPtr Value::create() {
	all.push_back(ValueShPtr(new Value()));
	return all.back();
}

void Value::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Value::destroy() {
	destroy(getID());
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
