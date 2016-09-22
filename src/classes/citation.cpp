#include "citation.hpp"

std::list<CitationShPtr> Citation::all;
std::string Citation::type = "Citation";

Citation::Citation() :
Basic() {}

CitationShPtr Citation::create() {
	all.push_back(CitationShPtr(new Citation()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CitationShPtr Citation::create(BasicWkPtr _parent) {
	auto ptr = Citation::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Citation::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Citation::destroy() {
	destroy(getID());
}

BasicWkPtr Citation::get_parent() {
	return parent;
}

void Citation::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Citation::get_type() {
	return type;
}

TitleShPtr Citation::get_title() {
	return title;
}
void Citation::set_title(TitleShPtr _title) {
	title = _title;
}
SubTitlePtrList Citation::get_sub_titles() {
	return sub_titles;
}




void Citation::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Title");
		title = Title::create(shared_from_this());
		title->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:SubTitle");
		while (true) {
			sub_titles.push_back(SubTitle::create(shared_from_this()));
			sub_titles.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:SubTitle");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
