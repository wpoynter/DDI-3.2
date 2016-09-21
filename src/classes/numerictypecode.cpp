#include "numerictypecode.hpp"

std::list<NumericTypeCodeShPtr> NumericTypeCode::all;

NumericTypeCode::NumericTypeCode() :
Basic() {}

NumericTypeCodeShPtr NumericTypeCode::create() {
	all.push_back(NumericTypeCodeShPtr(new NumericTypeCode()));
	return all.back();
}

void NumericTypeCode::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void NumericTypeCode::destroy() {
	destroy(getID());
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
