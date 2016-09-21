#include "title.hpp"

std::list<TitleShPtr> Title::all;

Title::Title() :
Basic() {}

TitleShPtr Title::create() {
	all.push_back(TitleShPtr(new Title()));
	return all.back();
}

void Title::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Title::destroy() {
	destroy(getID());
}

StringShPtr Title::get_string() {
	return string;
}
void Title::set_string(StringShPtr _string) {
	string = _string;
}




void Title::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
