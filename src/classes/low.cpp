#include "low.hpp"

std::list<LowShPtr> Low::all;
std::string Low::type = "Low";

Low::Low() :
Basic() {}

LowShPtr Low::create() {
	all.push_back(LowShPtr(new Low()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

LowShPtr Low::create(BasicWkPtr _parent) {
	auto ptr = Low::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Low::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Low::destroy() {
	destroy(getID());
}

BasicWkPtr Low::get_parent() {
	return parent;
}

void Low::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Low::get_type() {
	return type;
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
