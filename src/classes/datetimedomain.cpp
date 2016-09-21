#include "datetimedomain.hpp"

std::list<DateTimeDomainShPtr> DateTimeDomain::all;

DateTimeDomain::DateTimeDomain() :
Basic() {}

DateTimeDomainShPtr DateTimeDomain::create() {
	all.push_back(DateTimeDomainShPtr(new DateTimeDomain()));
	return all.back();
}

void DateTimeDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DateTimeDomain::destroy() {
	destroy(getID());
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
			date_field_formats.push_back(DateFieldFormat::create());
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
			date_type_codes.push_back(DateTypeCode::create());
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
			labels.push_back(Label::create());
			labels.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Label");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
