#include "questionreference.hpp"

std::list<QuestionReferenceShPtr> QuestionReference::all;
std::string QuestionReference::type = "QuestionReference";

QuestionReference::QuestionReference() :
Basic() {}

QuestionReferenceShPtr QuestionReference::create() {
	all.push_back(QuestionReferenceShPtr(new QuestionReference()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

QuestionReferenceShPtr QuestionReference::create(BasicWkPtr _parent) {
	auto ptr = QuestionReference::create();
	ptr->set_parent(_parent);
	return ptr;
}

void QuestionReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionReference::destroy() {
	destroy(getID());
}

BasicWkPtr QuestionReference::get_parent() {
	return parent;
}

void QuestionReference::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string QuestionReference::get_type() {
	return type;
}

URNShPtr QuestionReference::get_urn() {
	return urn;
}
void QuestionReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectShPtr QuestionReference::get_type_of_object() {
	return type_of_object;
}
void QuestionReference::set_type_of_object(TypeOfObjectShPtr _type_of_object) {
	type_of_object = _type_of_object;
}




void QuestionReference::read_element(ticpp::Element* elem) {
	
	
	
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
