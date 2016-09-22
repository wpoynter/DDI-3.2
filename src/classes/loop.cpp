#include "loop.hpp"

std::list<LoopShPtr> Loop::all;
std::string Loop::type = "Loop";

Loop::Loop() :
Basic() {}

LoopShPtr Loop::create() {
	all.push_back(LoopShPtr(new Loop()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

LoopShPtr Loop::create(BasicWkPtr _parent) {
	auto ptr = Loop::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Loop::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Loop::destroy() {
	destroy(getID());
}

BasicWkPtr Loop::get_parent() {
	return parent;
}

void Loop::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Loop::get_type() {
	return type;
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
		ticpp::Element* child_elem = elem->FirstChildElement("d:InitialValue");
		while (true) {
			initial_values.push_back(InitialValue::create(shared_from_this()));
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
			loop_whiles.push_back(LoopWhile::create(shared_from_this()));
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
			control_construct_references.push_back(ControlConstructReference::create(shared_from_this()));
			control_construct_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ControlConstructReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
