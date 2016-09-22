#include "ifthenelse.hpp"

std::list<IfThenElseShPtr> IfThenElse::all;
std::string IfThenElse::type = "IfThenElse";

IfThenElse::IfThenElse() :
Basic() {}

IfThenElseShPtr IfThenElse::create() {
	all.push_back(IfThenElseShPtr(new IfThenElse()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

IfThenElseShPtr IfThenElse::create(BasicWkPtr _parent) {
	auto ptr = IfThenElse::create();
	ptr->set_parent(_parent);
	return ptr;
}

void IfThenElse::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void IfThenElse::destroy() {
	destroy(getID());
}

BasicWkPtr IfThenElse::get_parent() {
	return parent;
}

void IfThenElse::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string IfThenElse::get_type() {
	return type;
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
		ticpp::Element* child_elem = elem->FirstChildElement("d:IfCondition");
		while (true) {
			if_conditions.push_back(IfCondition::create(shared_from_this()));
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
			then_construct_references.push_back(ThenConstructReference::create(shared_from_this()));
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
			else_construct_references.push_back(ElseConstructReference::create(shared_from_this()));
			else_construct_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ElseConstructReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
