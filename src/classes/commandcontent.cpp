#include "commandcontent.hpp"

std::list<CommandContentShPtr> CommandContent::all;
std::string CommandContent::type = "CommandContent";

CommandContent::CommandContent() :
Basic() {}

CommandContentShPtr CommandContent::create() {
	all.push_back(CommandContentShPtr(new CommandContent()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CommandContentShPtr CommandContent::create(BasicWkPtr _parent) {
	auto ptr = CommandContent::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CommandContent::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CommandContent::destroy() {
	destroy(getID());
}

BasicWkPtr CommandContent::get_parent() {
	return parent;
}

void CommandContent::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CommandContent::get_type() {
	return type;
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
