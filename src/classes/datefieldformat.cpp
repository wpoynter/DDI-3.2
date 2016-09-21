#include "datefieldformat.hpp"

std::list<DateFieldFormatShPtr> DateFieldFormat::all;

DateFieldFormat::DateFieldFormat() :
Basic() {}

DateFieldFormatShPtr DateFieldFormat::create() {
	all.push_back(DateFieldFormatShPtr(new DateFieldFormat()));
	return all.back();
}

void DateFieldFormat::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DateFieldFormat::destroy() {
	destroy(getID());
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
