#include "resourcepackage.hpp"

std::list<ResourcePackageShPtr> ResourcePackage::all;

ResourcePackage::ResourcePackage() :
Basic() {}

ResourcePackageShPtr ResourcePackage::create() {
	all.push_back(ResourcePackageShPtr(new ResourcePackage()));
	return all.back();
}

void ResourcePackage::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ResourcePackage::destroy() {
	destroy(getID());
}

URNShPtr ResourcePackage::get_urn() {
	return urn;
}
void ResourcePackage::set_urn(URNShPtr _urn) {
	urn = _urn;
}
CitationPtrList ResourcePackage::get_citations() {
	return citations;
}
PurposePtrList ResourcePackage::get_purposes() {
	return purposes;
}
DataCollectionPtrList ResourcePackage::get_data_collections() {
	return data_collections;
}
QuestionSchemePtrList ResourcePackage::get_question_schemes() {
	return question_schemes;
}
CategorySchemePtrList ResourcePackage::get_category_schemes() {
	return category_schemes;
}
CodeListSchemePtrList ResourcePackage::get_code_list_schemes() {
	return code_list_schemes;
}
std::string ResourcePackage::get_version_date() {
	return version_date;
}
void ResourcePackage::set_version_date(std::string _version_date) {
	version_date = _version_date;
}


void ResourcePackage::read_element(ticpp::Element* elem) {
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
		ticpp::Element* child_elem = elem->FirstChildElement("r:Purpose");
		while (true) {
			purposes.push_back(Purpose::create());
			purposes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Purpose");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:DataCollection");
		while (true) {
			data_collections.push_back(DataCollection::create());
			data_collections.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:DataCollection");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:QuestionScheme");
		while (true) {
			question_schemes.push_back(QuestionScheme::create());
			question_schemes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:QuestionScheme");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("l:CategoryScheme");
		while (true) {
			category_schemes.push_back(CategoryScheme::create());
			category_schemes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:CategoryScheme");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("l:CodeListScheme");
		while (true) {
			code_list_schemes.push_back(CodeListScheme::create());
			code_list_schemes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:CodeListScheme");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
