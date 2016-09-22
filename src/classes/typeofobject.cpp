#include "typeofobject.hpp"

std::list<TypeOfObjectShPtr> TypeOfObject::all;
std::string TypeOfObject::type = "TypeOfObject";

TypeOfObject::TypeOfObject() :
Basic() {}

TypeOfObjectShPtr TypeOfObject::create() {
	all.push_back(TypeOfObjectShPtr(new TypeOfObject()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

TypeOfObjectShPtr TypeOfObject::create(BasicWkPtr _parent) {
	auto ptr = TypeOfObject::create();
	ptr->set_parent(_parent);
	return ptr;
}

void TypeOfObject::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void TypeOfObject::destroy() {
	destroy(getID());
}

BasicWkPtr TypeOfObject::get_parent() {
	return parent;
}

void TypeOfObject::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string TypeOfObject::get_type() {
	return type;
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
