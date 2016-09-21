#include "string.hpp"

std::list<StringShPtr> String::all;

String::String() :
Basic() {}

StringShPtr String::create() {
	all.push_back(StringShPtr(new String()));
	return all.back();
}

void String::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void String::destroy() {
	destroy(getID());
}

std::string String::get_lang() {
	return lang;
}
void String::set_lang(std::string _lang) {
	lang = _lang;
}
std::string String::get_content() {
	return content;
}
void String::set_content(std::string _content) {
	content = _content;
}
void String::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "lang", &lang, false);
	elem->GetText(&content, false);
	
}
