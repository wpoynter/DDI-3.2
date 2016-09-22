#include "codelist.hpp"

std::list<CodeListShPtr> CodeList::all;
std::string CodeList::type = "CodeList";

CodeList::CodeList() :
Basic() {}

CodeListShPtr CodeList::create() {
	all.push_back(CodeListShPtr(new CodeList()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CodeListShPtr CodeList::create(BasicWkPtr _parent) {
	auto ptr = CodeList::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CodeList::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CodeList::destroy() {
	destroy(getID());
}

BasicWkPtr CodeList::get_parent() {
	return parent;
}

void CodeList::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CodeList::get_type() {
	return type;
}

URNShPtr CodeList::get_urn() {
	return urn;
}
void CodeList::set_urn(URNShPtr _urn) {
	urn = _urn;
}
LabelPtrList CodeList::get_labels() {
	return labels;
}
CodePtrList CodeList::get_codes() {
	return codes;
}




void CodeList::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Label");
		while (true) {
			labels.push_back(Label::create(shared_from_this()));
			labels.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Label");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("l:Code");
		while (true) {
			codes.push_back(Code::create(shared_from_this()));
			codes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:Code");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
