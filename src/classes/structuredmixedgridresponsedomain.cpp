#include "structuredmixedgridresponsedomain.hpp"

std::list<StructuredMixedGridResponseDomainShPtr> StructuredMixedGridResponseDomain::all;

StructuredMixedGridResponseDomain::StructuredMixedGridResponseDomain() :
Basic() {}

StructuredMixedGridResponseDomainShPtr StructuredMixedGridResponseDomain::create() {
	all.push_back(StructuredMixedGridResponseDomainShPtr(new StructuredMixedGridResponseDomain()));
	return all.back();
}

void StructuredMixedGridResponseDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void StructuredMixedGridResponseDomain::destroy() {
	destroy(getID());
}

GridResponseDomainPtrList StructuredMixedGridResponseDomain::get_grid_response_domains() {
	return grid_response_domains;
}




void StructuredMixedGridResponseDomain::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:GridResponseDomain");
		while (true) {
			grid_response_domains.push_back(GridResponseDomain::create());
			grid_response_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:GridResponseDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
