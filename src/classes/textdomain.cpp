#include "textdomain.hpp"

std::list<TextDomainShPtr> TextDomain::all;

TextDomain::TextDomain() :
Basic() {}

TextDomainShPtr TextDomain::create() {
	all.push_back(TextDomainShPtr(new TextDomain()));
	return all.back();
}

void TextDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void TextDomain::destroy() {
	destroy(getID());
}

LabelPtrList TextDomain::get_labels() {
	return labels;
}
std::string TextDomain::get_max_length() {
	return max_length;
}
void TextDomain::set_max_length(std::string _max_length) {
	max_length = _max_length;
}


void TextDomain::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "maxLength", &max_length, false);
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:Label");
		while (true) {
			labels.push_back(Label::create());
			labels.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:Label");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
