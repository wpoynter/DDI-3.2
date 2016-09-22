#include "instrumentname.hpp"

std::list<InstrumentNameShPtr> InstrumentName::all;
std::string InstrumentName::type = "InstrumentName";

InstrumentName::InstrumentName() :
Basic() {}

InstrumentNameShPtr InstrumentName::create() {
	all.push_back(InstrumentNameShPtr(new InstrumentName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InstrumentNameShPtr InstrumentName::create(BasicWkPtr _parent) {
	auto ptr = InstrumentName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void InstrumentName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InstrumentName::destroy() {
	destroy(getID());
}

BasicWkPtr InstrumentName::get_parent() {
	return parent;
}

void InstrumentName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string InstrumentName::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
