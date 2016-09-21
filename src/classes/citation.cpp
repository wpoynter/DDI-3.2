#include "citation.hpp"

std::list<CitationShPtr> Citation::all;

Citation::Citation() :
Basic() {}

CitationShPtr Citation::create() {
	all.push_back(CitationShPtr(new Citation()));
	return all.back();
}

void Citation::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Citation::destroy() {
	destroy(getID());
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
		title = Title::create();
		title->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:SubTitle");
		while (true) {
			sub_titles.push_back(SubTitle::create());
			sub_titles.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:SubTitle");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
