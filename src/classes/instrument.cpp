#include "instrument.hpp"

std::list<InstrumentShPtr> Instrument::all;
std::string Instrument::type = "Instrument";

Instrument::Instrument() :
Basic() {}

InstrumentShPtr Instrument::create() {
	all.push_back(InstrumentShPtr(new Instrument()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InstrumentShPtr Instrument::create(BasicWkPtr _parent) {
	auto ptr = Instrument::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Instrument::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Instrument::destroy() {
	destroy(getID());
}

BasicWkPtr Instrument::get_parent() {
	return parent;
}

void Instrument::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Instrument::get_type() {
	return type;
}

URNShPtr Instrument::get_urn() {
	return urn;
}
void Instrument::set_urn(URNShPtr _urn) {
	urn = _urn;
}
InstrumentNamePtrList Instrument::get_instrument_names() {
	return instrument_names;
}
ControlConstructReferencePtrList Instrument::get_control_construct_references() {
	return control_construct_references;
}




void Instrument::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InstrumentName");
		while (true) {
			instrument_names.push_back(InstrumentName::create(shared_from_this()));
			instrument_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:InstrumentName");
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
