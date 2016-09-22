#include "numericdomain.hpp"

std::list<NumericDomainShPtr> NumericDomain::all;
std::string NumericDomain::type = "NumericDomain";

NumericDomain::NumericDomain() :
Basic() {}

NumericDomainShPtr NumericDomain::create() {
	all.push_back(NumericDomainShPtr(new NumericDomain()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

NumericDomainShPtr NumericDomain::create(BasicWkPtr _parent) {
	auto ptr = NumericDomain::create();
	ptr->set_parent(_parent);
	return ptr;
}

void NumericDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void NumericDomain::destroy() {
	destroy(getID());
}

BasicWkPtr NumericDomain::get_parent() {
	return parent;
}

void NumericDomain::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string NumericDomain::get_type() {
	return type;
}

NumberRangePtrList NumericDomain::get_number_ranges() {
	return number_ranges;
}
NumericTypeCodePtrList NumericDomain::get_numeric_type_codes() {
	return numeric_type_codes;
}
LabelPtrList NumericDomain::get_labels() {
	return labels;
}




void NumericDomain::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:NumberRange");
		while (true) {
			number_ranges.push_back(NumberRange::create(shared_from_this()));
			number_ranges.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:NumberRange");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:NumericTypeCode");
		while (true) {
			numeric_type_codes.push_back(NumericTypeCode::create(shared_from_this()));
			numeric_type_codes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:NumericTypeCode");
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
