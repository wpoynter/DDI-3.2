#include "low.hpp"

std::list<LowShPtr> Low::all;

Low::Low() :
Basic() {}

LowShPtr Low::create() {
	all.push_back(LowShPtr(new Low()));
	return all.back();
}

void Low::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Low::destroy() {
	destroy(getID());
}



std::string Low::get_content() {
	return content;
}
void Low::set_content(std::string _content) {
	content = _content;
}
void Low::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
