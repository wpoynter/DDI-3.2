#include "codedomain.hpp"

std::list<CodeDomainShPtr> CodeDomain::all;

CodeDomain::CodeDomain() :
Basic() {}

CodeDomainShPtr CodeDomain::create() {
	all.push_back(CodeDomainShPtr(new CodeDomain()));
	return all.back();
}

void CodeDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CodeDomain::destroy() {
	destroy(getID());
}

CodeListReferencePtrList CodeDomain::get_code_list_references() {
	return code_list_references;
}




void CodeDomain::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:CodeListReference");
		while (true) {
			code_list_references.push_back(CodeListReference::create());
			code_list_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:CodeListReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
