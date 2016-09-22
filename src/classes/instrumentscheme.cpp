#include "instrumentscheme.hpp"

std::list<InstrumentSchemeShPtr> InstrumentScheme::all;
std::string InstrumentScheme::type = "InstrumentScheme";

InstrumentScheme::InstrumentScheme() :
Basic() {}

InstrumentSchemeShPtr InstrumentScheme::create() {
	all.push_back(InstrumentSchemeShPtr(new InstrumentScheme()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InstrumentSchemeShPtr InstrumentScheme::create(BasicWkPtr _parent) {
	auto ptr = InstrumentScheme::create();
	ptr->set_parent(_parent);
	return ptr;
}

void InstrumentScheme::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InstrumentScheme::destroy() {
	destroy(getID());
}

BasicWkPtr InstrumentScheme::get_parent() {
	return parent;
}

void InstrumentScheme::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string InstrumentScheme::get_type() {
	return type;
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
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InstrumentSchemeName");
		while (true) {
			instrument_scheme_names.push_back(InstrumentSchemeName::create(shared_from_this()));
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
			instruments.push_back(Instrument::create(shared_from_this()));
			instruments.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:Instrument");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
