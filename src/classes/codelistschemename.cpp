#include "codelistschemename.hpp"

std::list<CodeListSchemeNameShPtr> CodeListSchemeName::all;
std::string CodeListSchemeName::type = "CodeListSchemeName";

CodeListSchemeName::CodeListSchemeName() :
Basic() {}

CodeListSchemeNameShPtr CodeListSchemeName::create() {
	all.push_back(CodeListSchemeNameShPtr(new CodeListSchemeName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CodeListSchemeNameShPtr CodeListSchemeName::create(BasicWkPtr _parent) {
	auto ptr = CodeListSchemeName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CodeListSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CodeListSchemeName::destroy() {
	destroy(getID());
}

BasicWkPtr CodeListSchemeName::get_parent() {
	return parent;
}

void CodeListSchemeName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CodeListSchemeName::get_type() {
	return type;
}

StringShPtr CodeListSchemeName::get_string() {
	return string;
}
void CodeListSchemeName::set_string(StringShPtr _string) {
	string = _string;
}




void CodeListSchemeName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
