#include "controlconstructreference.hpp"

std::list<ControlConstructReferenceShPtr> ControlConstructReference::all;
std::string ControlConstructReference::type = "ControlConstructReference";

ControlConstructReference::ControlConstructReference() :
Basic() {}

ControlConstructReferenceShPtr ControlConstructReference::create() {
	all.push_back(ControlConstructReferenceShPtr(new ControlConstructReference()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ControlConstructReferenceShPtr ControlConstructReference::create(BasicWkPtr _parent) {
	auto ptr = ControlConstructReference::create();
	ptr->set_parent(_parent);
	return ptr;
}

void ControlConstructReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ControlConstructReference::destroy() {
	destroy(getID());
}

BasicWkPtr ControlConstructReference::get_parent() {
	return parent;
}

void ControlConstructReference::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string ControlConstructReference::get_type() {
	return type;
}

URNShPtr ControlConstructReference::get_urn() {
	return urn;
}
void ControlConstructReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectShPtr ControlConstructReference::get_type_of_object() {
	return type_of_object;
}
void ControlConstructReference::set_type_of_object(TypeOfObjectShPtr _type_of_object) {
	type_of_object = _type_of_object;
}




void ControlConstructReference::read_element(ticpp::Element* elem) {
	
	
	
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
