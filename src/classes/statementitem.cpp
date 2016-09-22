#include "statementitem.hpp"

std::list<StatementItemShPtr> StatementItem::all;
std::string StatementItem::type = "StatementItem";

StatementItem::StatementItem() :
Basic() {}

StatementItemShPtr StatementItem::create() {
	all.push_back(StatementItemShPtr(new StatementItem()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

StatementItemShPtr StatementItem::create(BasicWkPtr _parent) {
	auto ptr = StatementItem::create();
	ptr->set_parent(_parent);
	return ptr;
}

void StatementItem::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void StatementItem::destroy() {
	destroy(getID());
}

BasicWkPtr StatementItem::get_parent() {
	return parent;
}

void StatementItem::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string StatementItem::get_type() {
	return type;
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
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ConstructName");
		while (true) {
			construct_names.push_back(ConstructName::create(shared_from_this()));
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
			display_texts.push_back(DisplayText::create(shared_from_this()));
			display_texts.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:DisplayText");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
