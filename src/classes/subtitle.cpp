#include "subtitle.hpp"

std::list<SubTitleShPtr> SubTitle::all;

SubTitle::SubTitle() :
Basic() {}

SubTitleShPtr SubTitle::create() {
	all.push_back(SubTitleShPtr(new SubTitle()));
	return all.back();
}

void SubTitle::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void SubTitle::destroy() {
	destroy(getID());
}

StringShPtr SubTitle::get_string() {
	return string;
}
void SubTitle::set_string(StringShPtr _string) {
	string = _string;
}




void SubTitle::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
