#include "structuredmixedgridresponsedomain.hpp"

std::list<StructuredMixedGridResponseDomainShPtr> StructuredMixedGridResponseDomain::all;
std::string StructuredMixedGridResponseDomain::type = "StructuredMixedGridResponseDomain";

StructuredMixedGridResponseDomain::StructuredMixedGridResponseDomain() :
Basic() {}

StructuredMixedGridResponseDomainShPtr StructuredMixedGridResponseDomain::create() {
	all.push_back(StructuredMixedGridResponseDomainShPtr(new StructuredMixedGridResponseDomain()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

StructuredMixedGridResponseDomainShPtr StructuredMixedGridResponseDomain::create(BasicWkPtr _parent) {
	auto ptr = StructuredMixedGridResponseDomain::create();
	ptr->set_parent(_parent);
	return ptr;
}

void StructuredMixedGridResponseDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void StructuredMixedGridResponseDomain::destroy() {
	destroy(getID());
}

BasicWkPtr StructuredMixedGridResponseDomain::get_parent() {
	return parent;
}

void StructuredMixedGridResponseDomain::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string StructuredMixedGridResponseDomain::get_type() {
	return type;
}

GridResponseDomainPtrList StructuredMixedGridResponseDomain::get_grid_response_domains() {
	return grid_response_domains;
}




void StructuredMixedGridResponseDomain::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:GridResponseDomain");
		while (true) {
			grid_response_domains.push_back(GridResponseDomain::create(shared_from_this()));
			grid_response_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:GridResponseDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
