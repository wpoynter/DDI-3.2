#include "codelist.hpp"

std::list<CodeListShPtr> CodeList::all;

CodeList::CodeList() :
Basic() {}

CodeListShPtr CodeList::create() {
	all.push_back(CodeListShPtr(new CodeList()));
	return all.back();
}

void CodeList::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CodeList::destroy() {
	destroy(getID());
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
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Label");
		while (true) {
			labels.push_back(Label::create());
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
			codes.push_back(Code::create());
			codes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("l:Code");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
