#include "initialvalue.hpp"

std::list<InitialValueShPtr> InitialValue::all;

InitialValue::InitialValue() :
Basic() {}

InitialValueShPtr InitialValue::create() {
	all.push_back(InitialValueShPtr(new InitialValue()));
	return all.back();
}

void InitialValue::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void InitialValue::destroy() {
	destroy(getID());
}

CommandPtrList InitialValue::get_commands() {
	return commands;
}




void InitialValue::read_element(ticpp::Element* elem) {
	
	
	
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
