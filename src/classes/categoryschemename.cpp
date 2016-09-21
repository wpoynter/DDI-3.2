#include "categoryschemename.hpp"

std::list<CategorySchemeNameShPtr> CategorySchemeName::all;

CategorySchemeName::CategorySchemeName() :
Basic() {}

CategorySchemeNameShPtr CategorySchemeName::create() {
	all.push_back(CategorySchemeNameShPtr(new CategorySchemeName()));
	return all.back();
}

void CategorySchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CategorySchemeName::destroy() {
	destroy(getID());
}

StringShPtr CategorySchemeName::get_string() {
	return string;
}
void CategorySchemeName::set_string(StringShPtr _string) {
	string = _string;
}




void CategorySchemeName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
