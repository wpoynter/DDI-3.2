#include "initialvalue.hpp"

std::list<InitialValueShPtr> InitialValue::all;
std::string InitialValue::type = "InitialValue";

InitialValue::InitialValue() :
Basic() {}

InitialValueShPtr InitialValue::create() {
	all.push_back(InitialValueShPtr(new InitialValue()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

InitialValueShPtr InitialValue::create(BasicWkPtr _parent) {
	auto ptr = InitialValue::create();
	ptr->set_parent(_parent);
	return ptr;
}

void InitialValue::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InitialValue::destroy() {
	destroy(getID());
}

BasicWkPtr InitialValue::get_parent() {
	return parent;
}

void InitialValue::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string InitialValue::get_type() {
	return type;
}

CommandPtrList InitialValue::get_commands() {
	return commands;
}




void InitialValue::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Command");
		while (true) {
			commands.push_back(Command::create(shared_from_this()));
			commands.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Command");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
