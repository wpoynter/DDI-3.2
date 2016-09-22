#include "loopwhile.hpp"

std::list<LoopWhileShPtr> LoopWhile::all;
std::string LoopWhile::type = "LoopWhile";

LoopWhile::LoopWhile() :
Basic() {}

LoopWhileShPtr LoopWhile::create() {
	all.push_back(LoopWhileShPtr(new LoopWhile()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

LoopWhileShPtr LoopWhile::create(BasicWkPtr _parent) {
	auto ptr = LoopWhile::create();
	ptr->set_parent(_parent);
	return ptr;
}

void LoopWhile::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void LoopWhile::destroy() {
	destroy(getID());
}

BasicWkPtr LoopWhile::get_parent() {
	return parent;
}

void LoopWhile::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string LoopWhile::get_type() {
	return type;
}

CommandPtrList LoopWhile::get_commands() {
	return commands;
}




void LoopWhile::read_element(ticpp::Element* elem) {
	
	
	
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
