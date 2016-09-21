#include "instrumentname.hpp"

std::list<InstrumentNameShPtr> InstrumentName::all;

InstrumentName::InstrumentName() :
Basic() {}

InstrumentNameShPtr InstrumentName::create() {
	all.push_back(InstrumentNameShPtr(new InstrumentName()));
	return all.back();
}

void InstrumentName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InstrumentName::destroy() {
	destroy(getID());
}

StringShPtr InstrumentName::get_string() {
	return string;
}
void InstrumentName::set_string(StringShPtr _string) {
	string = _string;
}




void InstrumentName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
