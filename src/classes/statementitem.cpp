#include "statementitem.hpp"

std::list<StatementItemShPtr> StatementItem::all;

StatementItem::StatementItem() :
Basic() {}

StatementItemShPtr StatementItem::create() {
	all.push_back(StatementItemShPtr(new StatementItem()));
	return all.back();
}

void StatementItem::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void StatementItem::destroy() {
	destroy(getID());
}

URNShPtr StatementItem::get_urn() {
	return urn;
}
void StatementItem::set_urn(URNShPtr _urn) {
	urn = _urn;
}
ConstructNamePtrList StatementItem::get_construct_names() {
	return construct_names;
}
DisplayTextPtrList StatementItem::get_display_texts() {
	return display_texts;
}




void StatementItem::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ConstructName");
		while (true) {
			construct_names.push_back(ConstructName::create());
			construct_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ConstructName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:DisplayText");
		while (true) {
			display_texts.push_back(DisplayText::create());
			display_texts.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:DisplayText");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
