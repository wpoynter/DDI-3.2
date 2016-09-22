#include "basic.hpp"

unsigned int Basic::counter = 0;
BasicPtrList Basic::all;
std::string Basic::type = "Basic";

Basic::Basic() {
	counter++;
	ID = counter;
}

Basic::~Basic() {}

BasicShPtr Basic::create() {
	all.push_back(BasicShPtr(new Basic()));
	return all.back();
}

void Basic::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Basic::destroy() {
	destroy(getID());
}

unsigned int Basic::getID() const {
	return ID;
}

std::string Basic::get_type() {
	return type;
}

void Basic::read_element(ticpp::Element*) {}