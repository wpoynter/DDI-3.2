#include "title.hpp"

std::list<TitleShPtr> Title::all;
std::string Title::type = "Title";

Title::Title() :
Basic() {}

TitleShPtr Title::create() {
	all.push_back(TitleShPtr(new Title()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

TitleShPtr Title::create(BasicWkPtr _parent) {
	auto ptr = Title::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Title::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Title::destroy() {
	destroy(getID());
}

BasicWkPtr Title::get_parent() {
	return parent;
}

void Title::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Title::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
