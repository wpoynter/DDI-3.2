#include "categoryschemename.hpp"

std::list<CategorySchemeNameShPtr> CategorySchemeName::all;
std::string CategorySchemeName::type = "CategorySchemeName";

CategorySchemeName::CategorySchemeName() :
Basic() {}

CategorySchemeNameShPtr CategorySchemeName::create() {
	all.push_back(CategorySchemeNameShPtr(new CategorySchemeName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CategorySchemeNameShPtr CategorySchemeName::create(BasicWkPtr _parent) {
	auto ptr = CategorySchemeName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CategorySchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CategorySchemeName::destroy() {
	destroy(getID());
}

BasicWkPtr CategorySchemeName::get_parent() {
	return parent;
}

void CategorySchemeName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CategorySchemeName::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
