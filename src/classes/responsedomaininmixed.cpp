#include "responsedomaininmixed.hpp"

std::list<ResponseDomainInMixedShPtr> ResponseDomainInMixed::all;
std::string ResponseDomainInMixed::type = "ResponseDomainInMixed";

ResponseDomainInMixed::ResponseDomainInMixed() :
Basic() {}

ResponseDomainInMixedShPtr ResponseDomainInMixed::create() {
	all.push_back(ResponseDomainInMixedShPtr(new ResponseDomainInMixed()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ResponseDomainInMixedShPtr ResponseDomainInMixed::create(BasicWkPtr _parent) {
	auto ptr = ResponseDomainInMixed::create();
	ptr->set_parent(_parent);
	return ptr;
}

void ResponseDomainInMixed::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ResponseDomainInMixed::destroy() {
	destroy(getID());
}

BasicWkPtr ResponseDomainInMixed::get_parent() {
	return parent;
}

void ResponseDomainInMixed::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string ResponseDomainInMixed::get_type() {
	return type;
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
			code_domains.push_back(CodeDomain::create(shared_from_this()));
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
			text_domains.push_back(TextDomain::create(shared_from_this()));
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
			numeric_domains.push_back(NumericDomain::create(shared_from_this()));
			numeric_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:NumericDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
