#include "datefieldformat.hpp"

std::list<DateFieldFormatShPtr> DateFieldFormat::all;
std::string DateFieldFormat::type = "DateFieldFormat";

DateFieldFormat::DateFieldFormat() :
Basic() {}

DateFieldFormatShPtr DateFieldFormat::create() {
	all.push_back(DateFieldFormatShPtr(new DateFieldFormat()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

DateFieldFormatShPtr DateFieldFormat::create(BasicWkPtr _parent) {
	auto ptr = DateFieldFormat::create();
	ptr->set_parent(_parent);
	return ptr;
}

void DateFieldFormat::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DateFieldFormat::destroy() {
	destroy(getID());
}

BasicWkPtr DateFieldFormat::get_parent() {
	return parent;
}

void DateFieldFormat::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string DateFieldFormat::get_type() {
	return type;
}



std::string DateFieldFormat::get_content() {
	return content;
}
void DateFieldFormat::set_content(std::string _content) {
	content = _content;
}
void DateFieldFormat::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
