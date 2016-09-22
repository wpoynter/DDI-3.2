#include "codelistscheme.hpp"

std::list<CodeListSchemeShPtr> CodeListScheme::all;
std::string CodeListScheme::type = "CodeListScheme";

CodeListScheme::CodeListScheme() :
Basic() {}

CodeListSchemeShPtr CodeListScheme::create() {
	all.push_back(CodeListSchemeShPtr(new CodeListScheme()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CodeListSchemeShPtr CodeListScheme::create(BasicWkPtr _parent) {
	auto ptr = CodeListScheme::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CodeListScheme::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CodeListScheme::destroy() {
	destroy(getID());
}

BasicWkPtr CodeListScheme::get_parent() {
	return parent;
}

void CodeListScheme::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CodeListScheme::get_type() {
	return type;
}

URNShPtr CodeListScheme::get_urn() {
	return urn;
}
void CodeListScheme::set_urn(URNShPtr _urn) {
	urn = _urn;
}
CodeListSchemeNamePtrList CodeListScheme::get_code_list_scheme_names() {
	return code_list_scheme_names;
}
CodeListPtrList CodeListScheme::get_code_lists() {
	return code_lists;
}
std::string CodeListScheme::get_version_date() {
	return version_date;
}
void CodeListScheme::set_version_date(std::string _version_date) {
	version_date = _version_date;
}


void CodeListScheme::read_element(ticpp::Element* elem) {
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
		ticpp::Element* child_elem = elem->FirstChildElement("l:CodeListSchemeName");
		while (true) {
			code_list_scheme_names.push_back(CodeListSchemeName::create(shared_from_this()));
			code_list_scheme_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:CodeListSchemeName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("l:CodeList");
		while (true) {
			code_lists.push_back(CodeList::create(shared_from_this()));
			code_lists.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:CodeList");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
