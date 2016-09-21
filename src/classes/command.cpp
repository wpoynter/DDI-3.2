#include "command.hpp"

std::list<CommandShPtr> Command::all;

Command::Command() :
Basic() {}

CommandShPtr Command::create() {
	all.push_back(CommandShPtr(new Command()));
	return all.back();
}

void Command::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void Command::destroy() {
	destroy(getID());
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
			program_languages.push_back(ProgramLanguage::create());
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
			command_contents.push_back(CommandContent::create());
			command_contents.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:CommandContent");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
