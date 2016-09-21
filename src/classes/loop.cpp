#include "loop.hpp"

std::list<LoopShPtr> Loop::all;

Loop::Loop() :
Basic() {}

LoopShPtr Loop::create() {
	all.push_back(LoopShPtr(new Loop()));
	return all.back();
}

void Loop::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Loop::destroy() {
	destroy(getID());
}

URNShPtr Loop::get_urn() {
	return urn;
}
void Loop::set_urn(URNShPtr _urn) {
	urn = _urn;
}
ConstructNamePtrList Loop::get_construct_names() {
	return construct_names;
}
InitialValuePtrList Loop::get_initial_values() {
	return initial_values;
}
LoopWhilePtrList Loop::get_loop_whiles() {
	return loop_whiles;
}
ControlConstructReferencePtrList Loop::get_control_construct_references() {
	return control_construct_references;
}




void Loop::read_element(ticpp::Element* elem) {
	
	
	
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
		ticpp::Element* child_elem = elem->FirstChildElement("d:InitialValue");
		while (true) {
			initial_values.push_back(InitialValue::create());
			initial_values.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:InitialValue");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:LoopWhile");
		while (true) {
			loop_whiles.push_back(LoopWhile::create());
			loop_whiles.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:LoopWhile");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ControlConstructReference");
		while (true) {
			control_construct_references.push_back(ControlConstructReference::create());
			control_construct_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ControlConstructReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
