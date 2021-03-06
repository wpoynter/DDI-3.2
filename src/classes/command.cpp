#include "command.hpp"

std::list<CommandShPtr> Command::all;
std::string Command::type = "Command";

Command::Command() :
Basic() {}

CommandShPtr Command::create() {
	all.push_back(CommandShPtr(new Command()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CommandShPtr Command::create(BasicWkPtr _parent) {
	auto ptr = Command::create();
	ptr->set_parent(_parent);
	return ptr;
}

void Command::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Command::destroy() {
	destroy(getID());
}

BasicWkPtr Command::get_parent() {
	return parent;
}

void Command::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string Command::get_type() {
	return type;
}

ProgramLanguagePtrList Command::get_program_languages() {
	return program_languages;
}
CommandContentPtrList Command::get_command_contents() {
	return command_contents;
}




void Command::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:ProgramLanguage");
		while (true) {
			program_languages.push_back(ProgramLanguage::create(shared_from_this()));
			program_languages.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:ProgramLanguage");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:CommandContent");
		while (true) {
			command_contents.push_back(CommandContent::create(shared_from_this()));
			command_contents.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:CommandContent");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
