#include "ifthenelse.hpp"

std::list<IfThenElseShPtr> IfThenElse::all;

IfThenElse::IfThenElse() :
Basic() {}

IfThenElseShPtr IfThenElse::create() {
	all.push_back(IfThenElseShPtr(new IfThenElse()));
	return all.back();
}

void IfThenElse::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void IfThenElse::destroy() {
	destroy(getID());
}

URNShPtr IfThenElse::get_urn() {
	return urn;
}
void IfThenElse::set_urn(URNShPtr _urn) {
	urn = _urn;
}
ConstructNamePtrList IfThenElse::get_construct_names() {
	return construct_names;
}
IfConditionPtrList IfThenElse::get_if_conditions() {
	return if_conditions;
}
ThenConstructReferencePtrList IfThenElse::get_then_construct_references() {
	return then_construct_references;
}
ElseConstructReferencePtrList IfThenElse::get_else_construct_references() {
	return else_construct_references;
}




void IfThenElse::read_element(ticpp::Element* elem) {
	
	
	
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
		ticpp::Element* child_elem = elem->FirstChildElement("d:IfCondition");
		while (true) {
			if_conditions.push_back(IfCondition::create());
			if_conditions.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:IfCondition");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ThenConstructReference");
		while (true) {
			then_construct_references.push_back(ThenConstructReference::create());
			then_construct_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ThenConstructReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ElseConstructReference");
		while (true) {
			else_construct_references.push_back(ElseConstructReference::create());
			else_construct_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ElseConstructReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
