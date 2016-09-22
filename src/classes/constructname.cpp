#include "constructname.hpp"

std::list<ConstructNameShPtr> ConstructName::all;
std::string ConstructName::type = "ConstructName";

ConstructName::ConstructName() :
Basic() {}

ConstructNameShPtr ConstructName::create() {
	all.push_back(ConstructNameShPtr(new ConstructName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ConstructNameShPtr ConstructName::create(BasicWkPtr _parent) {
	auto ptr = ConstructName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void ConstructName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ConstructName::destroy() {
	destroy(getID());
}

BasicWkPtr ConstructName::get_parent() {
	return parent;
}

void ConstructName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string ConstructName::get_type() {
	return type;
}

StringShPtr ConstructName::get_string() {
	return string;
}
void ConstructName::set_string(StringShPtr _string) {
	string = _string;
}




void ConstructName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
