#include "instrumentschemename.hpp"

std::list<InstrumentSchemeNameShPtr> InstrumentSchemeName::all;

InstrumentSchemeName::InstrumentSchemeName() :
Basic() {}

InstrumentSchemeNameShPtr InstrumentSchemeName::create() {
	all.push_back(InstrumentSchemeNameShPtr(new InstrumentSchemeName()));
	return all.back();
}

void InstrumentSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InstrumentSchemeName::destroy() {
	destroy(getID());
}

StringShPtr InstrumentSchemeName::get_string() {
	return string;
}
void InstrumentSchemeName::set_string(StringShPtr _string) {
	string = _string;
}




void InstrumentSchemeName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
