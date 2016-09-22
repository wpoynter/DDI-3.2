#include "urn.hpp"

std::list<URNShPtr> URN::all;
std::string URN::type = "URN";

URN::URN() :
Basic() {}

URNShPtr URN::create() {
	all.push_back(URNShPtr(new URN()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

URNShPtr URN::create(BasicWkPtr _parent) {
	auto ptr = URN::create();
	ptr->set_parent(_parent);
	return ptr;
}

void URN::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void URN::destroy() {
	destroy(getID());
}

BasicWkPtr URN::get_parent() {
	return parent;
}

void URN::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string URN::get_type() {
	return type;
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
