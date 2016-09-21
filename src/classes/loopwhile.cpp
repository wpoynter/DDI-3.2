#include "loopwhile.hpp"

std::list<LoopWhileShPtr> LoopWhile::all;

LoopWhile::LoopWhile() :
Basic() {}

LoopWhileShPtr LoopWhile::create() {
	all.push_back(LoopWhileShPtr(new LoopWhile()));
	return all.back();
}

void LoopWhile::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void LoopWhile::destroy() {
	destroy(getID());
}

CommandPtrList LoopWhile::get_commands() {
	return commands;
}




void LoopWhile::read_element(ticpp::Element* elem) {
	
	
	
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
