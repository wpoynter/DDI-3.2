#include "content.hpp"

std::list<ContentShPtr> Content::all;

Content::Content() :
Basic() {}

ContentShPtr Content::create() {
	all.push_back(ContentShPtr(new Content()));
	return all.back();
}

void Content::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Content::destroy() {
	destroy(getID());
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
