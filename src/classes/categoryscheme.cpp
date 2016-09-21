#include "categoryscheme.hpp"

std::list<CategorySchemeShPtr> CategoryScheme::all;

CategoryScheme::CategoryScheme() :
Basic() {}

CategorySchemeShPtr CategoryScheme::create() {
	all.push_back(CategorySchemeShPtr(new CategoryScheme()));
	return all.back();
}

void CategoryScheme::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CategoryScheme::destroy() {
	destroy(getID());
}

URNShPtr CategoryScheme::get_urn() {
	return urn;
}
void CategoryScheme::set_urn(URNShPtr _urn) {
	urn = _urn;
}
CategorySchemeNamePtrList CategoryScheme::get_category_scheme_names() {
	return category_scheme_names;
}
CategoryPtrList CategoryScheme::get_categories() {
	return categories;
}
std::string CategoryScheme::get_version_date() {
	return version_date;
}
void CategoryScheme::set_version_date(std::string _version_date) {
	version_date = _version_date;
}


void CategoryScheme::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "versionDate", &version_date, false);
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("l:CategorySchemeName");
		while (true) {
			category_scheme_names.push_back(CategorySchemeName::create());
			category_scheme_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:CategorySchemeName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("l:Category");
		while (true) {
			categories.push_back(Category::create());
			categories.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:Category");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
