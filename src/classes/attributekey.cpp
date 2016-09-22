#include "attributekey.hpp"

std::list<AttributeKeyShPtr> AttributeKey::all;
std::string AttributeKey::type = "AttributeKey";

AttributeKey::AttributeKey() :
Basic() {}

AttributeKeyShPtr AttributeKey::create() {
	all.push_back(AttributeKeyShPtr(new AttributeKey()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

AttributeKeyShPtr AttributeKey::create(BasicWkPtr _parent) {
	auto ptr = AttributeKey::create();
	ptr->set_parent(_parent);
	return ptr;
}

void AttributeKey::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void AttributeKey::destroy() {
	destroy(getID());
}

BasicWkPtr AttributeKey::get_parent() {
	return parent;
}

void AttributeKey::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string AttributeKey::get_type() {
	return type;
}



std::string AttributeKey::get_content() {
	return content;
}
void AttributeKey::set_content(std::string _content) {
	content = _content;
}
void AttributeKey::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
