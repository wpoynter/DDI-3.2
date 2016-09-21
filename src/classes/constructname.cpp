#include "constructname.hpp"

std::list<ConstructNameShPtr> ConstructName::all;

ConstructName::ConstructName() :
Basic() {}

ConstructNameShPtr ConstructName::create() {
	all.push_back(ConstructNameShPtr(new ConstructName()));
	return all.back();
}

void ConstructName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ConstructName::destroy() {
	destroy(getID());
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
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
