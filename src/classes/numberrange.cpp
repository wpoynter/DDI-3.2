#include "numberrange.hpp"

std::list<NumberRangeShPtr> NumberRange::all;

NumberRange::NumberRange() :
Basic() {}

NumberRangeShPtr NumberRange::create() {
	all.push_back(NumberRangeShPtr(new NumberRange()));
	return all.back();
}

void NumberRange::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void NumberRange::destroy() {
	destroy(getID());
}

LowPtrList NumberRange::get_lows() {
	return lows;
}




void NumberRange::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Low");
		while (true) {
			lows.push_back(Low::create());
			lows.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Low");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
