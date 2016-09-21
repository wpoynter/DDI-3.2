#include "questionitem.hpp"

std::list<QuestionItemShPtr> QuestionItem::all;

QuestionItem::QuestionItem() :
Basic() {}

QuestionItemShPtr QuestionItem::create() {
	all.push_back(QuestionItemShPtr(new QuestionItem()));
	return all.back();
}

void QuestionItem::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionItem::destroy() {
	destroy(getID());
}

URNShPtr QuestionItem::get_urn() {
	return urn;
}
void QuestionItem::set_urn(URNShPtr _urn) {
	urn = _urn;
}
UserAttributePairPtrList QuestionItem::get_user_attribute_pairs() {
	return user_attribute_pairs;
}
QuestionItemNamePtrList QuestionItem::get_question_item_names() {
	return question_item_names;
}
QuestionTextPtrList QuestionItem::get_question_texts() {
	return question_texts;
}
CodeDomainPtrList QuestionItem::get_code_domains() {
	return code_domains;
}
StructuredMixedResponseDomainPtrList QuestionItem::get_structured_mixed_response_domains() {
	return structured_mixed_response_domains;
}
NumericDomainPtrList QuestionItem::get_numeric_domains() {
	return numeric_domains;
}
DateTimeDomainPtrList QuestionItem::get_date_time_domains() {
	return date_time_domains;
}
InterviewerInstructionReferencePtrList QuestionItem::get_interviewer_instruction_references() {
	return interviewer_instruction_references;
}
TextDomainPtrList QuestionItem::get_text_domains() {
	return text_domains;
}




void QuestionItem::read_element(ticpp::Element* elem) {
	
	
	
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
		ticpp::Element* child_elem = elem->FirstChildElement("d:QuestionItemName");
		while (true) {
			question_item_names.push_back(QuestionItemName::create());
			question_item_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:QuestionItemName");
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
		ticpp::Element* child_elem = elem->FirstChildElement("d:StructuredMixedResponseDomain");
		while (true) {
			structured_mixed_response_domains.push_back(StructuredMixedResponseDomain::create());
			structured_mixed_response_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:StructuredMixedResponseDomain");
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
		ticpp::Element* child_elem = elem->FirstChildElement("d:DateTimeDomain");
		while (true) {
			date_time_domains.push_back(DateTimeDomain::create());
			date_time_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:DateTimeDomain");
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
