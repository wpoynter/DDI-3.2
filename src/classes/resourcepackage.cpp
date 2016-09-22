#include "resourcepackage.hpp"

std::list<ResourcePackageShPtr> ResourcePackage::all;
std::string ResourcePackage::type = "ResourcePackage";

ResourcePackage::ResourcePackage() :
Basic() {}

ResourcePackageShPtr ResourcePackage::create() {
	all.push_back(ResourcePackageShPtr(new ResourcePackage()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

ResourcePackageShPtr ResourcePackage::create(BasicWkPtr _parent) {
	auto ptr = ResourcePackage::create();
	ptr->set_parent(_parent);
	return ptr;
}

void ResourcePackage::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void ResourcePackage::destroy() {
	destroy(getID());
}

BasicWkPtr ResourcePackage::get_parent() {
	return parent;
}

void ResourcePackage::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string ResourcePackage::get_type() {
	return type;
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
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Citation");
		while (true) {
			citations.push_back(Citation::create(shared_from_this()));
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
			purposes.push_back(Purpose::create(shared_from_this()));
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
			data_collections.push_back(DataCollection::create(shared_from_this()));
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
			question_schemes.push_back(QuestionScheme::create(shared_from_this()));
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
			category_schemes.push_back(CategoryScheme::create(shared_from_this()));
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
			code_list_schemes.push_back(CodeListScheme::create(shared_from_this()));
			code_list_schemes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:CodeListScheme");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
