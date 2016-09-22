#include "content.hpp"

std::list<ContentShPtr> Content::all;
std::string Content::type = "Content";

Content::Content() :
Basic() {}

ContentShPtr Content::create() {
	all.push_back(ContentShPtr(new Content()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ContentShPtr Content::create(BasicWkPtr _parent) {
	auto ptr = Content::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Content::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Content::destroy() {
	destroy(getID());
}

BasicWkPtr Content::get_parent() {
	return parent;
}

void Content::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Content::get_type() {
	return type;
}

std::string Content::get_lang() {
	return lang;
}
void Content::set_lang(std::string _lang) {
	lang = _lang;
}
std::string Content::get_content() {
	return content;
}
void Content::set_content(std::string _content) {
	content = _content;
}
void Content::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "lang", &lang, false);
	elem->GetText(&content, false);
	
}
