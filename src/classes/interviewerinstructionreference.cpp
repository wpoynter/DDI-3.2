#include "interviewerinstructionreference.hpp"

std::list<InterviewerInstructionReferenceShPtr> InterviewerInstructionReference::all;
std::string InterviewerInstructionReference::type = "InterviewerInstructionReference";

InterviewerInstructionReference::InterviewerInstructionReference() :
Basic() {}

InterviewerInstructionReferenceShPtr InterviewerInstructionReference::create() {
	all.push_back(InterviewerInstructionReferenceShPtr(new InterviewerInstructionReference()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InterviewerInstructionReferenceShPtr InterviewerInstructionReference::create(BasicWkPtr _parent) {
	auto ptr = InterviewerInstructionReference::create();
	ptr->set_parent(_parent);
	return ptr;
}

void InterviewerInstructionReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InterviewerInstructionReference::destroy() {
	destroy(getID());
}

BasicWkPtr InterviewerInstructionReference::get_parent() {
	return parent;
}

void InterviewerInstructionReference::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string InterviewerInstructionReference::get_type() {
	return type;
}

URNShPtr InterviewerInstructionReference::get_urn() {
	return urn;
}
void InterviewerInstructionReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectShPtr InterviewerInstructionReference::get_type_of_object() {
	return type_of_object;
}
void InterviewerInstructionReference::set_type_of_object(TypeOfObjectShPtr _type_of_object) {
	type_of_object = _type_of_object;
}




void InterviewerInstructionReference::read_element(ticpp::Element* elem) {
	
	
	
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
