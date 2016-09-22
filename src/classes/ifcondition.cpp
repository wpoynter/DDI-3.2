#include "ifcondition.hpp"

std::list<IfConditionShPtr> IfCondition::all;
std::string IfCondition::type = "IfCondition";

IfCondition::IfCondition() :
Basic() {}

IfConditionShPtr IfCondition::create() {
	all.push_back(IfConditionShPtr(new IfCondition()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

IfConditionShPtr IfCondition::create(BasicWkPtr _parent) {
	auto ptr = IfCondition::create();
	ptr->set_parent(_parent);
	return ptr;
}

void IfCondition::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void IfCondition::destroy() {
	destroy(getID());
}

BasicWkPtr IfCondition::get_parent() {
	return parent;
}

void IfCondition::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string IfCondition::get_type() {
	return type;
}

CommandPtrList IfCondition::get_commands() {
	return commands;
}




void IfCondition::read_element(ticpp::Element* elem) {
	
	
	
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
