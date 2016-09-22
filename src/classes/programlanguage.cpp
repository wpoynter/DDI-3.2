#include "programlanguage.hpp"

std::list<ProgramLanguageShPtr> ProgramLanguage::all;
std::string ProgramLanguage::type = "ProgramLanguage";

ProgramLanguage::ProgramLanguage() :
Basic() {}

ProgramLanguageShPtr ProgramLanguage::create() {
	all.push_back(ProgramLanguageShPtr(new ProgramLanguage()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ProgramLanguageShPtr ProgramLanguage::create(BasicWkPtr _parent) {
	auto ptr = ProgramLanguage::create();
	ptr->set_parent(_parent);
	return ptr;
}

void ProgramLanguage::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ProgramLanguage::destroy() {
	destroy(getID());
}

BasicWkPtr ProgramLanguage::get_parent() {
	return parent;
}

void ProgramLanguage::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string ProgramLanguage::get_type() {
	return type;
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
