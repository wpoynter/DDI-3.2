#include "code.hpp"

std::list<CodeShPtr> Code::all;

Code::Code() :
Basic() {}

CodeShPtr Code::create() {
	all.push_back(CodeShPtr(new Code()));
	return all.back();
}

void Code::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Code::destroy() {
	destroy(getID());
}

URNShPtr Code::get_urn() {
	return urn;
}
void Code::set_urn(URNShPtr _urn) {
	urn = _urn;
}
CategoryReferencePtrList Code::get_category_references() {
	return category_references;
}
ValuePtrList Code::get_values() {
	return values;
}




void Code::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create();
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:CategoryReference");
		while (true) {
			category_references.push_back(CategoryReference::create());
			category_references.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:CategoryReference");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Value");
		while (true) {
			values.push_back(Value::create());
			values.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Value");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
