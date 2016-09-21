#include "questiongrid.hpp"

std::list<QuestionGridShPtr> QuestionGrid::all;

QuestionGrid::QuestionGrid() :
Basic() {}

QuestionGridShPtr QuestionGrid::create() {
	all.push_back(QuestionGridShPtr(new QuestionGrid()));
	return all.back();
}

void QuestionGrid::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionGrid::destroy() {
	destroy(getID());
}

URNShPtr QuestionGrid::get_urn() {
	return urn;
}
void QuestionGrid::set_urn(URNShPtr _urn) {
	urn = _urn;
}
UserAttributePairPtrList QuestionGrid::get_user_attribute_pairs() {
	return user_attribute_pairs;
}
QuestionGridNamePtrList QuestionGrid::get_question_grid_names() {
	return question_grid_names;
}
QuestionTextPtrList QuestionGrid::get_question_texts() {
	return question_texts;
}
GridDimensionPtrList QuestionGrid::get_grid_dimensions() {
	return grid_dimensions;
}
CodeDomainPtrList QuestionGrid::get_code_domains() {
	return code_domains;
}
StructuredMixedGridResponseDomainPtrList QuestionGrid::get_structured_mixed_grid_response_domains() {
	return structured_mixed_grid_response_domains;
}
InterviewerInstructionReferencePtrList QuestionGrid::get_interviewer_instruction_references() {
	return interviewer_instruction_references;
}
NumericDomainPtrList QuestionGrid::get_numeric_domains() {
	return numeric_domains;
}
TextDomainPtrList QuestionGrid::get_text_domains() {
	return text_domains;
}




void QuestionGrid::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:UserAttributePair");
		while (true) {
			user_attribute_pairs.push_back(UserAttributePair::create());
			user_attribute_pairs.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:UserAttributePair");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:QuestionGridName");
		while (true) {
			question_grid_names.push_back(QuestionGridName::create());
			question_grid_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:QuestionGridName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:QuestionText");
		while (true) {
			question_texts.push_back(QuestionText::create());
			question_texts.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:QuestionText");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:GridDimension");
		while (true) {
			grid_dimensions.push_back(GridDimension::create());
			grid_dimensions.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:GridDimension");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:CodeDomain");
		while (true) {
			code_domains.push_back(CodeDomain::create());
			code_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:CodeDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:StructuredMixedGridResponseDomain");
		while (true) {
			structured_mixed_grid_response_domains.push_back(StructuredMixedGridResponseDomain::create());
			structured_mixed_grid_response_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:StructuredMixedGridResponseDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InterviewerInstructionReference");
		while (true) {
			interviewer_instruction_references.push_back(InterviewerInstructionReference::create());
			interviewer_instruction_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:InterviewerInstructionReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:NumericDomain");
		while (true) {
			numeric_domains.push_back(NumericDomain::create());
			numeric_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:NumericDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:TextDomain");
		while (true) {
			text_domains.push_back(TextDomain::create());
			text_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:TextDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
