#include "purpose.hpp"

std::list<PurposeShPtr> Purpose::all;

Purpose::Purpose() :
Basic() {}

PurposeShPtr Purpose::create() {
	all.push_back(PurposeShPtr(new Purpose()));
	return all.back();
}

void Purpose::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Purpose::destroy() {
	destroy(getID());
}

ContentPtrList Purpose::get_contents() {
	return contents;
}




void Purpose::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Content");
		while (true) {
			contents.push_back(Content::create());
			contents.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Content");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
