#include "attributevalue.hpp"

std::list<AttributeValueShPtr> AttributeValue::all;

AttributeValue::AttributeValue() :
Basic() {}

AttributeValueShPtr AttributeValue::create() {
	all.push_back(AttributeValueShPtr(new AttributeValue()));
	return all.back();
}

void AttributeValue::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void AttributeValue::destroy() {
	destroy(getID());
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
