#include "label.hpp"

std::list<LabelShPtr> Label::all;

Label::Label() :
Basic() {}

LabelShPtr Label::create() {
	all.push_back(LabelShPtr(new Label()));
	return all.back();
}

void Label::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Label::destroy() {
	destroy(getID());
}

ContentPtrList Label::get_contents() {
	return contents;
}




void Label::read_element(ticpp::Element* elem) {
	
	
	
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
