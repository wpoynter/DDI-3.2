#include "interviewerinstructionschemename.hpp"

std::list<InterviewerInstructionSchemeNameShPtr> InterviewerInstructionSchemeName::all;
std::string InterviewerInstructionSchemeName::type = "InterviewerInstructionSchemeName";

InterviewerInstructionSchemeName::InterviewerInstructionSchemeName() :
Basic() {}

InterviewerInstructionSchemeNameShPtr InterviewerInstructionSchemeName::create() {
	all.push_back(InterviewerInstructionSchemeNameShPtr(new InterviewerInstructionSchemeName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InterviewerInstructionSchemeNameShPtr InterviewerInstructionSchemeName::create(BasicWkPtr _parent) {
	auto ptr = InterviewerInstructionSchemeName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void InterviewerInstructionSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InterviewerInstructionSchemeName::destroy() {
	destroy(getID());
}

BasicWkPtr InterviewerInstructionSchemeName::get_parent() {
	return parent;
}

void InterviewerInstructionSchemeName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string InterviewerInstructionSchemeName::get_type() {
	return type;
}

StringShPtr InterviewerInstructionSchemeName::get_string() {
	return string;
}
void InterviewerInstructionSchemeName::set_string(StringShPtr _string) {
	string = _string;
}




void InterviewerInstructionSchemeName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
