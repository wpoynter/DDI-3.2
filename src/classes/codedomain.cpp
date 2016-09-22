#include "codedomain.hpp"

std::list<CodeDomainShPtr> CodeDomain::all;
std::string CodeDomain::type = "CodeDomain";

CodeDomain::CodeDomain() :
Basic() {}

CodeDomainShPtr CodeDomain::create() {
	all.push_back(CodeDomainShPtr(new CodeDomain()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CodeDomainShPtr CodeDomain::create(BasicWkPtr _parent) {
	auto ptr = CodeDomain::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CodeDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CodeDomain::destroy() {
	destroy(getID());
}

BasicWkPtr CodeDomain::get_parent() {
	return parent;
}

void CodeDomain::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CodeDomain::get_type() {
	return type;
}

CodeListReferencePtrList CodeDomain::get_code_list_references() {
	return code_list_references;
}




void CodeDomain::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:CodeListReference");
		while (true) {
			code_list_references.push_back(CodeListReference::create(shared_from_this()));
			code_list_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:CodeListReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
