#include "datetypecode.hpp"

std::list<DateTypeCodeShPtr> DateTypeCode::all;

DateTypeCode::DateTypeCode() :
Basic() {}

DateTypeCodeShPtr DateTypeCode::create() {
	all.push_back(DateTypeCodeShPtr(new DateTypeCode()));
	return all.back();
}

void DateTypeCode::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DateTypeCode::destroy() {
	destroy(getID());
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
