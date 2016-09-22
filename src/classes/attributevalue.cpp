#include "attributevalue.hpp"

std::list<AttributeValueShPtr> AttributeValue::all;
std::string AttributeValue::type = "AttributeValue";

AttributeValue::AttributeValue() :
Basic() {}

AttributeValueShPtr AttributeValue::create() {
	all.push_back(AttributeValueShPtr(new AttributeValue()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

AttributeValueShPtr AttributeValue::create(BasicWkPtr _parent) {
	auto ptr = AttributeValue::create();
	ptr->set_parent(_parent);
	return ptr;
}

void AttributeValue::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void AttributeValue::destroy() {
	destroy(getID());
}

BasicWkPtr AttributeValue::get_parent() {
	return parent;
}

void AttributeValue::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string AttributeValue::get_type() {
	return type;
}



std::string AttributeValue::get_content() {
	return content;
}
void AttributeValue::set_content(std::string _content) {
	content = _content;
}
void AttributeValue::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
