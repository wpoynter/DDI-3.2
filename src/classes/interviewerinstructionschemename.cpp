#include "interviewerinstructionschemename.hpp"

std::list<InterviewerInstructionSchemeNameShPtr> InterviewerInstructionSchemeName::all;

InterviewerInstructionSchemeName::InterviewerInstructionSchemeName() :
Basic() {}

InterviewerInstructionSchemeNameShPtr InterviewerInstructionSchemeName::create() {
	all.push_back(InterviewerInstructionSchemeNameShPtr(new InterviewerInstructionSchemeName()));
	return all.back();
}

void InterviewerInstructionSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InterviewerInstructionSchemeName::destroy() {
	destroy(getID());
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
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
