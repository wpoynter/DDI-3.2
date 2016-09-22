#include "purpose.hpp"

std::list<PurposeShPtr> Purpose::all;
std::string Purpose::type = "Purpose";

Purpose::Purpose() :
Basic() {}

PurposeShPtr Purpose::create() {
	all.push_back(PurposeShPtr(new Purpose()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

PurposeShPtr Purpose::create(BasicWkPtr _parent) {
	auto ptr = Purpose::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Purpose::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Purpose::destroy() {
	destroy(getID());
}

BasicWkPtr Purpose::get_parent() {
	return parent;
}

void Purpose::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Purpose::get_type() {
	return type;
}

ContentPtrList Purpose::get_contents() {
	return contents;
}




void Purpose::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Content");
		while (true) {
			contents.push_back(Content::create(shared_from_this()));
			contents.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Content");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
