#include "elseconstructreference.hpp"

std::list<ElseConstructReferenceShPtr> ElseConstructReference::all;

ElseConstructReference::ElseConstructReference() :
Basic() {}

ElseConstructReferenceShPtr ElseConstructReference::create() {
	all.push_back(ElseConstructReferenceShPtr(new ElseConstructReference()));
	return all.back();
}

void ElseConstructReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ElseConstructReference::destroy() {
	destroy(getID());
}

URNShPtr ElseConstructReference::get_urn() {
	return urn;
}
void ElseConstructReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectPtrList ElseConstructReference::get_type_of_objects() {
	return type_of_objects;
}




void ElseConstructReference::read_element(ticpp::Element* elem) {
	
	
	
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
