#include "codelistreference.hpp"

std::list<CodeListReferenceShPtr> CodeListReference::all;
std::string CodeListReference::type = "CodeListReference";

CodeListReference::CodeListReference() :
Basic() {}

CodeListReferenceShPtr CodeListReference::create() {
	all.push_back(CodeListReferenceShPtr(new CodeListReference()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CodeListReferenceShPtr CodeListReference::create(BasicWkPtr _parent) {
	auto ptr = CodeListReference::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CodeListReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CodeListReference::destroy() {
	destroy(getID());
}

BasicWkPtr CodeListReference::get_parent() {
	return parent;
}

void CodeListReference::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CodeListReference::get_type() {
	return type;
}

URNShPtr CodeListReference::get_urn() {
	return urn;
}
void CodeListReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectShPtr CodeListReference::get_type_of_object() {
	return type_of_object;
}
void CodeListReference::set_type_of_object(TypeOfObjectShPtr _type_of_object) {
	type_of_object = _type_of_object;
}




void CodeListReference::read_element(ticpp::Element* elem) {
	
	
	
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
