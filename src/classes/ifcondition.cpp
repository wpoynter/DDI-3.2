#include "ifcondition.hpp"

std::list<IfConditionShPtr> IfCondition::all;

IfCondition::IfCondition() :
Basic() {}

IfConditionShPtr IfCondition::create() {
	all.push_back(IfConditionShPtr(new IfCondition()));
	return all.back();
}

void IfCondition::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void IfCondition::destroy() {
	destroy(getID());
}

CommandPtrList IfCondition::get_commands() {
	return commands;
}




void IfCondition::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Command");
		while (true) {
			commands.push_back(Command::create());
			commands.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Command");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
