#include "controlconstructschemename.hpp"

std::list<ControlConstructSchemeNameShPtr> ControlConstructSchemeName::all;
std::string ControlConstructSchemeName::type = "ControlConstructSchemeName";

ControlConstructSchemeName::ControlConstructSchemeName() :
Basic() {}

ControlConstructSchemeNameShPtr ControlConstructSchemeName::create() {
	all.push_back(ControlConstructSchemeNameShPtr(new ControlConstructSchemeName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ControlConstructSchemeNameShPtr ControlConstructSchemeName::create(BasicWkPtr _parent) {
	auto ptr = ControlConstructSchemeName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void ControlConstructSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ControlConstructSchemeName::destroy() {
	destroy(getID());
}

BasicWkPtr ControlConstructSchemeName::get_parent() {
	return parent;
}

void ControlConstructSchemeName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string ControlConstructSchemeName::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
