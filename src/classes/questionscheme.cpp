#include "questionscheme.hpp"

std::list<QuestionSchemeShPtr> QuestionScheme::all;

QuestionScheme::QuestionScheme() :
Basic() {}

QuestionSchemeShPtr QuestionScheme::create() {
	all.push_back(QuestionSchemeShPtr(new QuestionScheme()));
	return all.back();
}

void QuestionScheme::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionScheme::destroy() {
	destroy(getID());
}

URNShPtr QuestionScheme::get_urn() {
	return urn;
}
void QuestionScheme::set_urn(URNShPtr _urn) {
	urn = _urn;
}
QuestionSchemeNamePtrList QuestionScheme::get_question_scheme_names() {
	return question_scheme_names;
}
QuestionItemPtrList QuestionScheme::get_question_items() {
	return question_items;
}
QuestionGridPtrList QuestionScheme::get_question_grids() {
	return question_grids;
}
std::string QuestionScheme::get_version_date() {
	return version_date;
}
void QuestionScheme::set_version_date(std::string _version_date) {
	version_date = _version_date;
}


void QuestionScheme::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "versionDate", &version_date, false);
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:QuestionSchemeName");
		while (true) {
			question_scheme_names.push_back(QuestionSchemeName::create());
			question_scheme_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:QuestionSchemeName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:QuestionItem");
		while (true) {
			question_items.push_back(QuestionItem::create());
			question_items.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:QuestionItem");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:QuestionGrid");
		while (true) {
			question_grids.push_back(QuestionGrid::create());
			question_grids.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:QuestionGrid");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
