#include "selectdimension.hpp"

std::list<SelectDimensionShPtr> SelectDimension::all;

SelectDimension::SelectDimension() :
Basic() {}

SelectDimensionShPtr SelectDimension::create() {
	all.push_back(SelectDimensionShPtr(new SelectDimension()));
	return all.back();
}

void SelectDimension::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void SelectDimension::destroy() {
	destroy(getID());
}

std::string SelectDimension::get_rank() {
	return rank;
}std::string SelectDimension::get_all_value() {
	return all_value;
}std::string SelectDimension::get_specific_value() {
	return specific_value;
}
void SelectDimension::set_rank(std::string _rank) {
	rank = _rank;
}void SelectDimension::set_all_value(std::string _all_value) {
	all_value = _all_value;
}void SelectDimension::set_specific_value(std::string _specific_value) {
	specific_value = _specific_value;
}


void SelectDimension::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "rank", &rank, false);elem->GetAttribute( "allValues", &all_value, false);elem->GetAttribute( "specificValue", &specific_value, false);
	
	
}
