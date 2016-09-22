#include "interviewerinstructionscheme.hpp"

std::list<InterviewerInstructionSchemeShPtr> InterviewerInstructionScheme::all;
std::string InterviewerInstructionScheme::type = "InterviewerInstructionScheme";

InterviewerInstructionScheme::InterviewerInstructionScheme() :
Basic() {}

InterviewerInstructionSchemeShPtr InterviewerInstructionScheme::create() {
	all.push_back(InterviewerInstructionSchemeShPtr(new InterviewerInstructionScheme()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InterviewerInstructionSchemeShPtr InterviewerInstructionScheme::create(BasicWkPtr _parent) {
	auto ptr = InterviewerInstructionScheme::create();
	ptr->set_parent(_parent);
	return ptr;
}

void InterviewerInstructionScheme::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InterviewerInstructionScheme::destroy() {
	destroy(getID());
}

BasicWkPtr InterviewerInstructionScheme::get_parent() {
	return parent;
}

void InterviewerInstructionScheme::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string InterviewerInstructionScheme::get_type() {
	return type;
}

URNShPtr InterviewerInstructionScheme::get_urn() {
	return urn;
}
void InterviewerInstructionScheme::set_urn(URNShPtr _urn) {
	urn = _urn;
}
InterviewerInstructionSchemeNamePtrList InterviewerInstructionScheme::get_interviewer_instruction_scheme_names() {
	return interviewer_instruction_scheme_names;
}
InstructionPtrList InterviewerInstructionScheme::get_instructions() {
	return instructions;
}
std::string InterviewerInstructionScheme::get_version_date() {
	return version_date;
}
void InterviewerInstructionScheme::set_version_date(std::string _version_date) {
	version_date = _version_date;
}


void InterviewerInstructionScheme::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "versionDate", &version_date, false);
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InterviewerInstructionSchemeName");
		while (true) {
			interviewer_instruction_scheme_names.push_back(InterviewerInstructionSchemeName::create(shared_from_this()));
			interviewer_instruction_scheme_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:InterviewerInstructionSchemeName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:Instruction");
		while (true) {
			instructions.push_back(Instruction::create(shared_from_this()));
			instructions.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:Instruction");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
