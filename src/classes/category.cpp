#include "category.hpp"

std::list<CategoryShPtr> Category::all;

Category::Category() :
Basic() {}

CategoryShPtr Category::create() {
	all.push_back(CategoryShPtr(new Category()));
	return all.back();
}

void Category::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Category::destroy() {
	destroy(getID());
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
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("l:CategoryName");
		while (true) {
			category_names.push_back(CategoryName::create());
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
			labels.push_back(Label::create());
			labels.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Label");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
