#include "instrument.hpp"

std::list<InstrumentShPtr> Instrument::all;

Instrument::Instrument() :
Basic() {}

InstrumentShPtr Instrument::create() {
	all.push_back(InstrumentShPtr(new Instrument()));
	return all.back();
}

void Instrument::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Instrument::destroy() {
	destroy(getID());
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
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InstrumentName");
		while (true) {
			instrument_names.push_back(InstrumentName::create());
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
			control_construct_references.push_back(ControlConstructReference::create());
			control_construct_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ControlConstructReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
