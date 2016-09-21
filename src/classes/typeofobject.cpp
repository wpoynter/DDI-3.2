#include "typeofobject.hpp"

std::list<TypeOfObjectShPtr> TypeOfObject::all;

TypeOfObject::TypeOfObject() :
Basic() {}

TypeOfObjectShPtr TypeOfObject::create() {
	all.push_back(TypeOfObjectShPtr(new TypeOfObject()));
	return all.back();
}

void TypeOfObject::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void TypeOfObject::destroy() {
	destroy(getID());
}



std::string TypeOfObject::get_content() {
	return content;
}
void TypeOfObject::set_content(std::string _content) {
	content = _content;
}
void TypeOfObject::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
