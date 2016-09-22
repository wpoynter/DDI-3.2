#include "questionscheme.hpp"

std::list<QuestionSchemeShPtr> QuestionScheme::all;
std::string QuestionScheme::type = "QuestionScheme";

QuestionScheme::QuestionScheme() :
Basic() {}

QuestionSchemeShPtr QuestionScheme::create() {
	all.push_back(QuestionSchemeShPtr(new QuestionScheme()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

QuestionSchemeShPtr QuestionScheme::create(BasicWkPtr _parent) {
	auto ptr = QuestionScheme::create();
	ptr->set_parent(_parent);
	return ptr;
}

void QuestionScheme::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionScheme::destroy() {
	destroy(getID());
}

BasicWkPtr QuestionScheme::get_parent() {
	return parent;
}

void QuestionScheme::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string QuestionScheme::get_type() {
	return type;
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
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:QuestionSchemeName");
		while (true) {
			question_scheme_names.push_back(QuestionSchemeName::create(shared_from_this()));
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
			question_items.push_back(QuestionItem::create(shared_from_this()));
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
			question_grids.push_back(QuestionGrid::create(shared_from_this()));
			question_grids.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:QuestionGrid");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
