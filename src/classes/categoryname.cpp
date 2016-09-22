#include "categoryname.hpp"

std::list<CategoryNameShPtr> CategoryName::all;
std::string CategoryName::type = "CategoryName";

CategoryName::CategoryName() :
Basic() {}

CategoryNameShPtr CategoryName::create() {
	all.push_back(CategoryNameShPtr(new CategoryName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CategoryNameShPtr CategoryName::create(BasicWkPtr _parent) {
	auto ptr = CategoryName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CategoryName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CategoryName::destroy() {
	destroy(getID());
}

BasicWkPtr CategoryName::get_parent() {
	return parent;
}

void CategoryName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CategoryName::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
