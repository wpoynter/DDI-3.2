#include "codelistreference.hpp"

std::list<CodeListReferenceShPtr> CodeListReference::all;

CodeListReference::CodeListReference() :
Basic() {}

CodeListReferenceShPtr CodeListReference::create() {
	all.push_back(CodeListReferenceShPtr(new CodeListReference()));
	return all.back();
}

void CodeListReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CodeListReference::destroy() {
	destroy(getID());
}

URNShPtr CodeListReference::get_urn() {
	return urn;
}
void CodeListReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectPtrList CodeListReference::get_type_of_objects() {
	return type_of_objects;
}




void CodeListReference::read_element(ticpp::Element* elem) {
	
	
	
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
