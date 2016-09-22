#include "datetimedomain.hpp"

std::list<DateTimeDomainShPtr> DateTimeDomain::all;
std::string DateTimeDomain::type = "DateTimeDomain";

DateTimeDomain::DateTimeDomain() :
Basic() {}

DateTimeDomainShPtr DateTimeDomain::create() {
	all.push_back(DateTimeDomainShPtr(new DateTimeDomain()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

DateTimeDomainShPtr DateTimeDomain::create(BasicWkPtr _parent) {
	auto ptr = DateTimeDomain::create();
	ptr->set_parent(_parent);
	return ptr;
}

void DateTimeDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DateTimeDomain::destroy() {
	destroy(getID());
}

BasicWkPtr DateTimeDomain::get_parent() {
	return parent;
}

void DateTimeDomain::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string DateTimeDomain::get_type() {
	return type;
}

DateFieldFormatPtrList DateTimeDomain::get_date_field_formats() {
	return date_field_formats;
}
DateTypeCodePtrList DateTimeDomain::get_date_type_codes() {
	return date_type_codes;
}
LabelPtrList DateTimeDomain::get_labels() {
	return labels;
}




void DateTimeDomain::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:DateFieldFormat");
		while (true) {
			date_field_formats.push_back(DateFieldFormat::create(shared_from_this()));
			date_field_formats.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:DateFieldFormat");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:DateTypeCode");
		while (true) {
			date_type_codes.push_back(DateTypeCode::create(shared_from_this()));
			date_type_codes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:DateTypeCode");
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
