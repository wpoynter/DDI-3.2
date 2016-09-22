#include "questionconstruct.hpp"

std::list<QuestionConstructShPtr> QuestionConstruct::all;
std::string QuestionConstruct::type = "QuestionConstruct";

QuestionConstruct::QuestionConstruct() :
Basic() {}

QuestionConstructShPtr QuestionConstruct::create() {
	all.push_back(QuestionConstructShPtr(new QuestionConstruct()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

QuestionConstructShPtr QuestionConstruct::create(BasicWkPtr _parent) {
	auto ptr = QuestionConstruct::create();
	ptr->set_parent(_parent);
	return ptr;
}

void QuestionConstruct::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void QuestionConstruct::destroy() {
	destroy(getID());
}

BasicWkPtr QuestionConstruct::get_parent() {
	return parent;
}

void QuestionConstruct::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string QuestionConstruct::get_type() {
	return type;
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
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ConstructName");
		while (true) {
			construct_names.push_back(ConstructName::create(shared_from_this()));
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
			labels.push_back(Label::create(shared_from_this()));
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
			question_references.push_back(QuestionReference::create(shared_from_this()));
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
			response_units.push_back(ResponseUnit::create(shared_from_this()));
			response_units.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ResponseUnit");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
