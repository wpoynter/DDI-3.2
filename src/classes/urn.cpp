#include "urn.hpp"

std::list<URNShPtr> URN::all;

URN::URN() :
Basic() {}

URNShPtr URN::create() {
	all.push_back(URNShPtr(new URN()));
	return all.back();
}

void URN::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void URN::destroy() {
	destroy(getID());
}



std::string URN::get_content() {
	return content;
}
void URN::set_content(std::string _content) {
	content = _content;
}
void URN::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
