#include "questionconstruct.hpp"

std::list<QuestionConstructShPtr> QuestionConstruct::all;

QuestionConstruct::QuestionConstruct() :
Basic() {}

QuestionConstructShPtr QuestionConstruct::create() {
	all.push_back(QuestionConstructShPtr(new QuestionConstruct()));
	return all.back();
}

void QuestionConstruct::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionConstruct::destroy() {
	destroy(getID());
}

URNShPtr QuestionConstruct::get_urn() {
	return urn;
}
void QuestionConstruct::set_urn(URNShPtr _urn) {
	urn = _urn;
}
ConstructNamePtrList QuestionConstruct::get_construct_names() {
	return construct_names;
}
LabelPtrList QuestionConstruct::get_labels() {
	return labels;
}
QuestionReferencePtrList QuestionConstruct::get_question_references() {
	return question_references;
}
ResponseUnitPtrList QuestionConstruct::get_response_units() {
	return response_units;
}




void QuestionConstruct::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ConstructName");
		while (true) {
			construct_names.push_back(ConstructName::create());
			construct_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ConstructName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Label");
		while (true) {
			labels.push_back(Label::create());
			labels.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Label");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:QuestionReference");
		while (true) {
			question_references.push_back(QuestionReference::create());
			question_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:QuestionReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ResponseUnit");
		while (true) {
			response_units.push_back(ResponseUnit::create());
			response_units.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ResponseUnit");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
