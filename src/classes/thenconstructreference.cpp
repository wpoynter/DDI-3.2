#include "thenconstructreference.hpp"

std::list<ThenConstructReferenceShPtr> ThenConstructReference::all;

ThenConstructReference::ThenConstructReference() :
Basic() {}

ThenConstructReferenceShPtr ThenConstructReference::create() {
	all.push_back(ThenConstructReferenceShPtr(new ThenConstructReference()));
	return all.back();
}

void ThenConstructReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ThenConstructReference::destroy() {
	destroy(getID());
}

URNShPtr ThenConstructReference::get_urn() {
	return urn;
}
void ThenConstructReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectPtrList ThenConstructReference::get_type_of_objects() {
	return type_of_objects;
}




void ThenConstructReference::read_element(ticpp::Element* elem) {
	
	
	
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
