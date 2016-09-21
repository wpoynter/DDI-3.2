#include "responsedomaininmixed.hpp"

std::list<ResponseDomainInMixedShPtr> ResponseDomainInMixed::all;

ResponseDomainInMixed::ResponseDomainInMixed() :
Basic() {}

ResponseDomainInMixedShPtr ResponseDomainInMixed::create() {
	all.push_back(ResponseDomainInMixedShPtr(new ResponseDomainInMixed()));
	return all.back();
}

void ResponseDomainInMixed::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ResponseDomainInMixed::destroy() {
	destroy(getID());
}

CodeDomainPtrList ResponseDomainInMixed::get_code_domains() {
	return code_domains;
}
TextDomainPtrList ResponseDomainInMixed::get_text_domains() {
	return text_domains;
}
NumericDomainPtrList ResponseDomainInMixed::get_numeric_domains() {
	return numeric_domains;
}




void ResponseDomainInMixed::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:CodeDomain");
		while (true) {
			code_domains.push_back(CodeDomain::create());
			code_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:CodeDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:TextDomain");
		while (true) {
			text_domains.push_back(TextDomain::create());
			text_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:TextDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:NumericDomain");
		while (true) {
			numeric_domains.push_back(NumericDomain::create());
			numeric_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:NumericDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
