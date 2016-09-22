#include "string.hpp"

std::list<StringShPtr> String::all;
std::string String::type = "String";

String::String() :
Basic() {}

StringShPtr String::create() {
	all.push_back(StringShPtr(new String()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

StringShPtr String::create(BasicWkPtr _parent) {
	auto ptr = String::create();
	ptr->set_parent(_parent);
	return ptr;
}

void String::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void String::destroy() {
	destroy(getID());
}

BasicWkPtr String::get_parent() {
	return parent;
}

void String::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string String::get_type() {
	return type;
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
