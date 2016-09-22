#include "responseunit.hpp"

std::list<ResponseUnitShPtr> ResponseUnit::all;
std::string ResponseUnit::type = "ResponseUnit";

ResponseUnit::ResponseUnit() :
Basic() {}

ResponseUnitShPtr ResponseUnit::create() {
	all.push_back(ResponseUnitShPtr(new ResponseUnit()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ResponseUnitShPtr ResponseUnit::create(BasicWkPtr _parent) {
	auto ptr = ResponseUnit::create();
	ptr->set_parent(_parent);
	return ptr;
}

void ResponseUnit::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ResponseUnit::destroy() {
	destroy(getID());
}

BasicWkPtr ResponseUnit::get_parent() {
	return parent;
}

void ResponseUnit::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string ResponseUnit::get_type() {
	return type;
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
