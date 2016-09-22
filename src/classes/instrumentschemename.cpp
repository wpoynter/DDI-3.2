#include "instrumentschemename.hpp"

std::list<InstrumentSchemeNameShPtr> InstrumentSchemeName::all;
std::string InstrumentSchemeName::type = "InstrumentSchemeName";

InstrumentSchemeName::InstrumentSchemeName() :
Basic() {}

InstrumentSchemeNameShPtr InstrumentSchemeName::create() {
	all.push_back(InstrumentSchemeNameShPtr(new InstrumentSchemeName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InstrumentSchemeNameShPtr InstrumentSchemeName::create(BasicWkPtr _parent) {
	auto ptr = InstrumentSchemeName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void InstrumentSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InstrumentSchemeName::destroy() {
	destroy(getID());
}

BasicWkPtr InstrumentSchemeName::get_parent() {
	return parent;
}

void InstrumentSchemeName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string InstrumentSchemeName::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
