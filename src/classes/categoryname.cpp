#include "categoryname.hpp"

std::list<CategoryNameShPtr> CategoryName::all;

CategoryName::CategoryName() :
Basic() {}

CategoryNameShPtr CategoryName::create() {
	all.push_back(CategoryNameShPtr(new CategoryName()));
	return all.back();
}

void CategoryName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CategoryName::destroy() {
	destroy(getID());
}

StringShPtr CategoryName::get_string() {
	return string;
}
void CategoryName::set_string(StringShPtr _string) {
	string = _string;
}




void CategoryName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
