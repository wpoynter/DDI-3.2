#include "subtitle.hpp"

std::list<SubTitleShPtr> SubTitle::all;
std::string SubTitle::type = "SubTitle";

SubTitle::SubTitle() :
Basic() {}

SubTitleShPtr SubTitle::create() {
	all.push_back(SubTitleShPtr(new SubTitle()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

SubTitleShPtr SubTitle::create(BasicWkPtr _parent) {
	auto ptr = SubTitle::create();
	ptr->set_parent(_parent);
	return ptr;
}

void SubTitle::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void SubTitle::destroy() {
	destroy(getID());
}

BasicWkPtr SubTitle::get_parent() {
	return parent;
}

void SubTitle::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string SubTitle::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
