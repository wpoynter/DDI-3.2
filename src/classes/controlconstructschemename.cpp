#include "controlconstructschemename.hpp"

std::list<ControlConstructSchemeNameShPtr> ControlConstructSchemeName::all;

ControlConstructSchemeName::ControlConstructSchemeName() :
Basic() {}

ControlConstructSchemeNameShPtr ControlConstructSchemeName::create() {
	all.push_back(ControlConstructSchemeNameShPtr(new ControlConstructSchemeName()));
	return all.back();
}

void ControlConstructSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ControlConstructSchemeName::destroy() {
	destroy(getID());
}

StringShPtr ControlConstructSchemeName::get_string() {
	return string;
}
void ControlConstructSchemeName::set_string(StringShPtr _string) {
	string = _string;
}




void ControlConstructSchemeName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
