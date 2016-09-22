#include "numberrange.hpp"

std::list<NumberRangeShPtr> NumberRange::all;
std::string NumberRange::type = "NumberRange";

NumberRange::NumberRange() :
Basic() {}

NumberRangeShPtr NumberRange::create() {
	all.push_back(NumberRangeShPtr(new NumberRange()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

NumberRangeShPtr NumberRange::create(BasicWkPtr _parent) {
	auto ptr = NumberRange::create();
	ptr->set_parent(_parent);
	return ptr;
}

void NumberRange::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void NumberRange::destroy() {
	destroy(getID());
}

BasicWkPtr NumberRange::get_parent() {
	return parent;
}

void NumberRange::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string NumberRange::get_type() {
	return type;
}

LowPtrList NumberRange::get_lows() {
	return lows;
}




void NumberRange::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Low");
		while (true) {
			lows.push_back(Low::create(shared_from_this()));
			lows.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Low");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
