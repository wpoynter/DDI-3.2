#include "categoryreference.hpp"

std::list<CategoryReferenceShPtr> CategoryReference::all;
std::string CategoryReference::type = "CategoryReference";

CategoryReference::CategoryReference() :
Basic() {}

CategoryReferenceShPtr CategoryReference::create() {
	all.push_back(CategoryReferenceShPtr(new CategoryReference()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CategoryReferenceShPtr CategoryReference::create(BasicWkPtr _parent) {
	auto ptr = CategoryReference::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CategoryReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CategoryReference::destroy() {
	destroy(getID());
}

BasicWkPtr CategoryReference::get_parent() {
	return parent;
}

void CategoryReference::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CategoryReference::get_type() {
	return type;
}

URNShPtr CategoryReference::get_urn() {
	return urn;
}
void CategoryReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectShPtr CategoryReference::get_type_of_object() {
	return type_of_object;
}
void CategoryReference::set_type_of_object(TypeOfObjectShPtr _type_of_object) {
	type_of_object = _type_of_object;
}




void CategoryReference::read_element(ticpp::Element* elem) {
	
	
	
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
