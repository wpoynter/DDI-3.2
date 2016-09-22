#include "thenconstructreference.hpp"

std::list<ThenConstructReferenceShPtr> ThenConstructReference::all;
std::string ThenConstructReference::type = "ThenConstructReference";

ThenConstructReference::ThenConstructReference() :
Basic() {}

ThenConstructReferenceShPtr ThenConstructReference::create() {
	all.push_back(ThenConstructReferenceShPtr(new ThenConstructReference()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ThenConstructReferenceShPtr ThenConstructReference::create(BasicWkPtr _parent) {
	auto ptr = ThenConstructReference::create();
	ptr->set_parent(_parent);
	return ptr;
}

void ThenConstructReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ThenConstructReference::destroy() {
	destroy(getID());
}

BasicWkPtr ThenConstructReference::get_parent() {
	return parent;
}

void ThenConstructReference::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string ThenConstructReference::get_type() {
	return type;
}

URNShPtr ThenConstructReference::get_urn() {
	return urn;
}
void ThenConstructReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectShPtr ThenConstructReference::get_type_of_object() {
	return type_of_object;
}
void ThenConstructReference::set_type_of_object(TypeOfObjectShPtr _type_of_object) {
	type_of_object = _type_of_object;
}




void ThenConstructReference::read_element(ticpp::Element* elem) {
	
	
	
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
