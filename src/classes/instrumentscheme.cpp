#include "instrumentscheme.hpp"

std::list<InstrumentSchemeShPtr> InstrumentScheme::all;

InstrumentScheme::InstrumentScheme() :
Basic() {}

InstrumentSchemeShPtr InstrumentScheme::create() {
	all.push_back(InstrumentSchemeShPtr(new InstrumentScheme()));
	return all.back();
}

void InstrumentScheme::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InstrumentScheme::destroy() {
	destroy(getID());
}

URNShPtr InstrumentScheme::get_urn() {
	return urn;
}
void InstrumentScheme::set_urn(URNShPtr _urn) {
	urn = _urn;
}
InstrumentSchemeNamePtrList InstrumentScheme::get_instrument_scheme_names() {
	return instrument_scheme_names;
}
InstrumentPtrList InstrumentScheme::get_instruments() {
	return instruments;
}




void InstrumentScheme::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InstrumentSchemeName");
		while (true) {
			instrument_scheme_names.push_back(InstrumentSchemeName::create());
			instrument_scheme_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:InstrumentSchemeName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:Instrument");
		while (true) {
			instruments.push_back(Instrument::create());
			instruments.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:Instrument");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
