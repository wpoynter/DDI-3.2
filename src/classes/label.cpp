#include "label.hpp"

std::list<LabelShPtr> Label::all;
std::string Label::type = "Label";

Label::Label() :
Basic() {}

LabelShPtr Label::create() {
	all.push_back(LabelShPtr(new Label()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

LabelShPtr Label::create(BasicWkPtr _parent) {
	auto ptr = Label::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Label::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Label::destroy() {
	destroy(getID());
}

BasicWkPtr Label::get_parent() {
	return parent;
}

void Label::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Label::get_type() {
	return type;
}

ContentPtrList Label::get_contents() {
	return contents;
}




void Label::read_element(ticpp::Element* elem) {
	
	
	
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
