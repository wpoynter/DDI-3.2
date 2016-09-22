#include "sequence.hpp"

std::list<SequenceShPtr> Sequence::all;
std::string Sequence::type = "Sequence";

Sequence::Sequence() :
Basic() {}

SequenceShPtr Sequence::create() {
	all.push_back(SequenceShPtr(new Sequence()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

SequenceShPtr Sequence::create(BasicWkPtr _parent) {
	auto ptr = Sequence::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Sequence::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Sequence::destroy() {
	destroy(getID());
}

BasicWkPtr Sequence::get_parent() {
	return parent;
}

void Sequence::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Sequence::get_type() {
	return type;
}

URNShPtr Sequence::get_urn() {
	return urn;
}
void Sequence::set_urn(URNShPtr _urn) {
	urn = _urn;
}
ConstructNamePtrList Sequence::get_construct_names() {
	return construct_names;
}
ControlConstructReferencePtrList Sequence::get_control_construct_references() {
	return control_construct_references;
}




void Sequence::read_element(ticpp::Element* elem) {
	
	
	
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
