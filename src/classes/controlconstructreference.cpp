#include "controlconstructreference.hpp"

std::list<ControlConstructReferenceShPtr> ControlConstructReference::all;

ControlConstructReference::ControlConstructReference() :
Basic() {}

ControlConstructReferenceShPtr ControlConstructReference::create() {
	all.push_back(ControlConstructReferenceShPtr(new ControlConstructReference()));
	return all.back();
}

void ControlConstructReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ControlConstructReference::destroy() {
	destroy(getID());
}

URNShPtr ControlConstructReference::get_urn() {
	return urn;
}
void ControlConstructReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectPtrList ControlConstructReference::get_type_of_objects() {
	return type_of_objects;
}




void ControlConstructReference::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:TypeOfObject");
		while (true) {
			type_of_objects.push_back(TypeOfObject::create());
			type_of_objects.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:TypeOfObject");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
