#include "griddimension.hpp"

std::list<GridDimensionShPtr> GridDimension::all;
std::string GridDimension::type = "GridDimension";

GridDimension::GridDimension() :
Basic() {}

GridDimensionShPtr GridDimension::create() {
	all.push_back(GridDimensionShPtr(new GridDimension()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

GridDimensionShPtr GridDimension::create(BasicWkPtr _parent) {
	auto ptr = GridDimension::create();
	ptr->set_parent(_parent);
	return ptr;
}

void GridDimension::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void GridDimension::destroy() {
	destroy(getID());
}

BasicWkPtr GridDimension::get_parent() {
	return parent;
}

void GridDimension::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string GridDimension::get_type() {
	return type;
}

CodeDomainPtrList GridDimension::get_code_domains() {
	return code_domains;
}
std::string GridDimension::get_rank() {
	return rank;
}std::string GridDimension::get_display_code() {
	return display_code;
}std::string GridDimension::get_display_label() {
	return display_label;
}
void GridDimension::set_rank(std::string _rank) {
	rank = _rank;
}void GridDimension::set_display_code(std::string _display_code) {
	display_code = _display_code;
}void GridDimension::set_display_label(std::string _display_label) {
	display_label = _display_label;
}


void GridDimension::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "rank", &rank, false);elem->GetAttribute( "displayCode", &display_code, false);elem->GetAttribute( "displayLabel", &display_label, false);
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:CodeDomain");
		while (true) {
			code_domains.push_back(CodeDomain::create(shared_from_this()));
			code_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:CodeDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
