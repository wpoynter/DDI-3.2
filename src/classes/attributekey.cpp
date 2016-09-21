#include "attributekey.hpp"

std::list<AttributeKeyShPtr> AttributeKey::all;

AttributeKey::AttributeKey() :
Basic() {}

AttributeKeyShPtr AttributeKey::create() {
	all.push_back(AttributeKeyShPtr(new AttributeKey()));
	return all.back();
}

void AttributeKey::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void AttributeKey::destroy() {
	destroy(getID());
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
