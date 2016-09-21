#include "codelistschemename.hpp"

std::list<CodeListSchemeNameShPtr> CodeListSchemeName::all;

CodeListSchemeName::CodeListSchemeName() :
Basic() {}

CodeListSchemeNameShPtr CodeListSchemeName::create() {
	all.push_back(CodeListSchemeNameShPtr(new CodeListSchemeName()));
	return all.back();
}

void CodeListSchemeName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CodeListSchemeName::destroy() {
	destroy(getID());
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
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
