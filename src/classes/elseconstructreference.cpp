#include "elseconstructreference.hpp"

std::list<ElseConstructReferenceShPtr> ElseConstructReference::all;
std::string ElseConstructReference::type = "ElseConstructReference";

ElseConstructReference::ElseConstructReference() :
Basic() {}

ElseConstructReferenceShPtr ElseConstructReference::create() {
	all.push_back(ElseConstructReferenceShPtr(new ElseConstructReference()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ElseConstructReferenceShPtr ElseConstructReference::create(BasicWkPtr _parent) {
	auto ptr = ElseConstructReference::create();
	ptr->set_parent(_parent);
	return ptr;
}

void ElseConstructReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ElseConstructReference::destroy() {
	destroy(getID());
}

BasicWkPtr ElseConstructReference::get_parent() {
	return parent;
}

void ElseConstructReference::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string ElseConstructReference::get_type() {
	return type;
}

URNShPtr ElseConstructReference::get_urn() {
	return urn;
}
void ElseConstructReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectShPtr ElseConstructReference::get_type_of_object() {
	return type_of_object;
}
void ElseConstructReference::set_type_of_object(TypeOfObjectShPtr _type_of_object) {
	type_of_object = _type_of_object;
}




void ElseConstructReference::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:TypeOfObject");
		type_of_object = TypeOfObject::create(shared_from_this());
		type_of_object->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
