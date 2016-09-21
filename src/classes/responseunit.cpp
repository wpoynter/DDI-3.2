#include "responseunit.hpp"

std::list<ResponseUnitShPtr> ResponseUnit::all;

ResponseUnit::ResponseUnit() :
Basic() {}

ResponseUnitShPtr ResponseUnit::create() {
	all.push_back(ResponseUnitShPtr(new ResponseUnit()));
	return all.back();
}

void ResponseUnit::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ResponseUnit::destroy() {
	destroy(getID());
}



std::string ResponseUnit::get_content() {
	return content;
}
void ResponseUnit::set_content(std::string _content) {
	content = _content;
}
void ResponseUnit::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
