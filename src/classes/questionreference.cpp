#include "questionreference.hpp"

std::list<QuestionReferenceShPtr> QuestionReference::all;

QuestionReference::QuestionReference() :
Basic() {}

QuestionReferenceShPtr QuestionReference::create() {
	all.push_back(QuestionReferenceShPtr(new QuestionReference()));
	return all.back();
}

void QuestionReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionReference::destroy() {
	destroy(getID());
}

URNShPtr QuestionReference::get_urn() {
	return urn;
}
void QuestionReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectPtrList QuestionReference::get_type_of_objects() {
	return type_of_objects;
}




void QuestionReference::read_element(ticpp::Element* elem) {
	
	
	
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
