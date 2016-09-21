#include "interviewerinstructionreference.hpp"

std::list<InterviewerInstructionReferenceShPtr> InterviewerInstructionReference::all;

InterviewerInstructionReference::InterviewerInstructionReference() :
Basic() {}

InterviewerInstructionReferenceShPtr InterviewerInstructionReference::create() {
	all.push_back(InterviewerInstructionReferenceShPtr(new InterviewerInstructionReference()));
	return all.back();
}

void InterviewerInstructionReference::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InterviewerInstructionReference::destroy() {
	destroy(getID());
}

URNShPtr InterviewerInstructionReference::get_urn() {
	return urn;
}
void InterviewerInstructionReference::set_urn(URNShPtr _urn) {
	urn = _urn;
}
TypeOfObjectPtrList InterviewerInstructionReference::get_type_of_objects() {
	return type_of_objects;
}




void InterviewerInstructionReference::read_element(ticpp::Element* elem) {
	
	
	
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
