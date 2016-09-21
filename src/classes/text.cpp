#include "text.hpp"

std::list<TextShPtr> Text::all;

Text::Text() :
Basic() {}

TextShPtr Text::create() {
	all.push_back(TextShPtr(new Text()));
	return all.back();
}

void Text::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Text::destroy() {
	destroy(getID());
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
