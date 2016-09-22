#include "category.hpp"

std::list<CategoryShPtr> Category::all;
std::string Category::type = "Category";

Category::Category() :
Basic() {}

CategoryShPtr Category::create() {
	all.push_back(CategoryShPtr(new Category()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CategoryShPtr Category::create(BasicWkPtr _parent) {
	auto ptr = Category::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Category::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Category::destroy() {
	destroy(getID());
}

BasicWkPtr Category::get_parent() {
	return parent;
}

void Category::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Category::get_type() {
	return type;
}

URNShPtr Category::get_urn() {
	return urn;
}
void Category::set_urn(URNShPtr _urn) {
	urn = _urn;
}
CategoryNamePtrList Category::get_category_names() {
	return category_names;
}
LabelPtrList Category::get_labels() {
	return labels;
}




void Category::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("l:CategoryName");
		while (true) {
			category_names.push_back(CategoryName::create(shared_from_this()));
			category_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:CategoryName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Label");
		while (true) {
			labels.push_back(Label::create(shared_from_this()));
			labels.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Label");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
