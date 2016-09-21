#include "structuredmixedresponsedomain.hpp"

std::list<StructuredMixedResponseDomainShPtr> StructuredMixedResponseDomain::all;

StructuredMixedResponseDomain::StructuredMixedResponseDomain() :
Basic() {}

StructuredMixedResponseDomainShPtr StructuredMixedResponseDomain::create() {
	all.push_back(StructuredMixedResponseDomainShPtr(new StructuredMixedResponseDomain()));
	return all.back();
}

void StructuredMixedResponseDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void StructuredMixedResponseDomain::destroy() {
	destroy(getID());
}

ResponseDomainInMixedPtrList StructuredMixedResponseDomain::get_response_domain_in_mixeds() {
	return response_domain_in_mixeds;
}




void StructuredMixedResponseDomain::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ResponseDomainInMixed");
		while (true) {
			response_domain_in_mixeds.push_back(ResponseDomainInMixed::create());
			response_domain_in_mixeds.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ResponseDomainInMixed");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
