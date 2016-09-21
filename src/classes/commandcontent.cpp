#include "commandcontent.hpp"

std::list<CommandContentShPtr> CommandContent::all;

CommandContent::CommandContent() :
Basic() {}

CommandContentShPtr CommandContent::create() {
	all.push_back(CommandContentShPtr(new CommandContent()));
	return all.back();
}

void CommandContent::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CommandContent::destroy() {
	destroy(getID());
}



std::string CommandContent::get_content() {
	return content;
}
void CommandContent::set_content(std::string _content) {
	content = _content;
}
void CommandContent::read_element(ticpp::Element* elem) {
	
	elem->GetText(&content, false);
	
}
