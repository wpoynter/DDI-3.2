#include "sequence.hpp"

std::list<SequenceShPtr> Sequence::all;

Sequence::Sequence() :
Basic() {}

SequenceShPtr Sequence::create() {
	all.push_back(SequenceShPtr(new Sequence()));
	return all.back();
}

void Sequence::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Sequence::destroy() {
	destroy(getID());
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
