#include "ddiinstance.hpp"

std::list<DDIInstanceShPtr> DDIInstance::all;

DDIInstance::DDIInstance() :
Basic() {}

DDIInstanceShPtr DDIInstance::create() {
	all.push_back(DDIInstanceShPtr(new DDIInstance()));
	return all.back();
}

void DDIInstance::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DDIInstance::destroy() {
	destroy(getID());
}

URNShPtr DDIInstance::get_urn() {
	return urn;
}
void DDIInstance::set_urn(URNShPtr _urn) {
	urn = _urn;
}
CitationPtrList DDIInstance::get_citations() {
	return citations;
}
ResourcePackagePtrList DDIInstance::get_resource_packages() {
	return resource_packages;
}
std::string DDIInstance::get_version_date() {
	return version_date;
}
void DDIInstance::set_version_date(std::string _version_date) {
	version_date = _version_date;
}


void DDIInstance::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "versionDate", &version_date, false);
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Citation");
		while (true) {
			citations.push_back(Citation::create());
			citations.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Citation");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("g:ResourcePackage");
		while (true) {
			resource_packages.push_back(ResourcePackage::create());
			resource_packages.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("g:ResourcePackage");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
