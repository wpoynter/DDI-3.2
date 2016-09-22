#include "text.hpp"

std::list<TextShPtr> Text::all;
std::string Text::type = "Text";

Text::Text() :
Basic() {}

TextShPtr Text::create() {
	all.push_back(TextShPtr(new Text()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

TextShPtr Text::create(BasicWkPtr _parent) {
	auto ptr = Text::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Text::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Text::destroy() {
	destroy(getID());
}

BasicWkPtr Text::get_parent() {
	return parent;
}

void Text::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Text::get_type() {
	return type;
}



std::string Text::get_content() {
	return content;
}
void Text::set_content(std::string _content) {
	content = _content;
}
void Text::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
