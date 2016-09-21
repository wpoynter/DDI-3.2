#include "programlanguage.hpp"

std::list<ProgramLanguageShPtr> ProgramLanguage::all;

ProgramLanguage::ProgramLanguage() :
Basic() {}

ProgramLanguageShPtr ProgramLanguage::create() {
	all.push_back(ProgramLanguageShPtr(new ProgramLanguage()));
	return all.back();
}

void ProgramLanguage::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ProgramLanguage::destroy() {
	destroy(getID());
}



std::string ProgramLanguage::get_content() {
	return content;
}
void ProgramLanguage::set_content(std::string _content) {
	content = _content;
}
void ProgramLanguage::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
