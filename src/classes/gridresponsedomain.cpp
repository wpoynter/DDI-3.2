#include "gridresponsedomain.hpp"

std::list<GridResponseDomainShPtr> GridResponseDomain::all;
std::string GridResponseDomain::type = "GridResponseDomain";

GridResponseDomain::GridResponseDomain() :
Basic() {}

GridResponseDomainShPtr GridResponseDomain::create() {
	all.push_back(GridResponseDomainShPtr(new GridResponseDomain()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

GridResponseDomainShPtr GridResponseDomain::create(BasicWkPtr _parent) {
	auto ptr = GridResponseDomain::create();
	ptr->set_parent(_parent);
	return ptr;
}

void GridResponseDomain::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void GridResponseDomain::destroy() {
	destroy(getID());
}

BasicWkPtr GridResponseDomain::get_parent() {
	return parent;
}

void GridResponseDomain::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string GridResponseDomain::get_type() {
	return type;
}

TextDomainPtrList GridResponseDomain::get_text_domains() {
	return text_domains;
}
GridAttachmentPtrList GridResponseDomain::get_grid_attachments() {
	return grid_attachments;
}
NumericDomainPtrList GridResponseDomain::get_numeric_domains() {
	return numeric_domains;
}
CodeDomainPtrList GridResponseDomain::get_code_domains() {
	return code_domains;
}




void GridResponseDomain::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:TextDomain");
		while (true) {
			text_domains.push_back(TextDomain::create(shared_from_this()));
			text_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:TextDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:GridAttachment");
		while (true) {
			grid_attachments.push_back(GridAttachment::create(shared_from_this()));
			grid_attachments.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:GridAttachment");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:NumericDomain");
		while (true) {
			numeric_domains.push_back(NumericDomain::create(shared_from_this()));
			numeric_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:NumericDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:CodeDomain");
		while (true) {
			code_domains.push_back(CodeDomain::create(shared_from_this()));
			code_domains.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:CodeDomain");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
