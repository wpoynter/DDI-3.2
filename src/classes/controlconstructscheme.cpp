#include "controlconstructscheme.hpp"

std::list<ControlConstructSchemeShPtr> ControlConstructScheme::all;

ControlConstructScheme::ControlConstructScheme() :
Basic() {}

ControlConstructSchemeShPtr ControlConstructScheme::create() {
	all.push_back(ControlConstructSchemeShPtr(new ControlConstructScheme()));
	return all.back();
}

void ControlConstructScheme::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ControlConstructScheme::destroy() {
	destroy(getID());
}

URNShPtr ControlConstructScheme::get_urn() {
	return urn;
}
void ControlConstructScheme::set_urn(URNShPtr _urn) {
	urn = _urn;
}
ControlConstructSchemeNamePtrList ControlConstructScheme::get_control_construct_scheme_names() {
	return control_construct_scheme_names;
}
SequencePtrList ControlConstructScheme::get_sequences() {
	return sequences;
}
StatementItemPtrList ControlConstructScheme::get_statement_items() {
	return statement_items;
}
QuestionConstructPtrList ControlConstructScheme::get_question_constructs() {
	return question_constructs;
}
IfThenElsePtrList ControlConstructScheme::get_if_then_elses() {
	return if_then_elses;
}
LoopPtrList ControlConstructScheme::get_loops() {
	return loops;
}




void ControlConstructScheme::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ControlConstructSchemeName");
		while (true) {
			control_construct_scheme_names.push_back(ControlConstructSchemeName::create());
			control_construct_scheme_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ControlConstructSchemeName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:Sequence");
		while (true) {
			sequences.push_back(Sequence::create());
			sequences.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:Sequence");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:StatementItem");
		while (true) {
			statement_items.push_back(StatementItem::create());
			statement_items.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:StatementItem");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:QuestionConstruct");
		while (true) {
			question_constructs.push_back(QuestionConstruct::create());
			question_constructs.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:QuestionConstruct");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:IfThenElse");
		while (true) {
			if_then_elses.push_back(IfThenElse::create());
			if_then_elses.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:IfThenElse");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:Loop");
		while (true) {
			loops.push_back(Loop::create());
			loops.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:Loop");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
