#include "structuredmixedresponsedomain.hpp"

std::list<StructuredMixedResponseDomainShPtr> StructuredMixedResponseDomain::all;
std::string StructuredMixedResponseDomain::type = "StructuredMixedResponseDomain";

StructuredMixedResponseDomain::StructuredMixedResponseDomain() :
Basic() {}

StructuredMixedResponseDomainShPtr StructuredMixedResponseDomain::create() {
	all.push_back(StructuredMixedResponseDomainShPtr(new StructuredMixedResponseDomain()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

StructuredMixedResponseDomainShPtr StructuredMixedResponseDomain::create(BasicWkPtr _parent) {
	auto ptr = StructuredMixedResponseDomain::create();
	ptr->set_parent(_parent);
	return ptr;
}

void StructuredMixedResponseDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void StructuredMixedResponseDomain::destroy() {
	destroy(getID());
}

BasicWkPtr StructuredMixedResponseDomain::get_parent() {
	return parent;
}

void StructuredMixedResponseDomain::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string StructuredMixedResponseDomain::get_type() {
	return type;
}

ResponseDomainInMixedPtrList StructuredMixedResponseDomain::get_response_domain_in_mixeds() {
	return response_domain_in_mixeds;
}




void StructuredMixedResponseDomain::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ResponseDomainInMixed");
		while (true) {
			response_domain_in_mixeds.push_back(ResponseDomainInMixed::create(shared_from_this()));
			response_domain_in_mixeds.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ResponseDomainInMixed");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
