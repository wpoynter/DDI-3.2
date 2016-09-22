#include "gridattachment.hpp"

std::list<GridAttachmentShPtr> GridAttachment::all;
std::string GridAttachment::type = "GridAttachment";

GridAttachment::GridAttachment() :
Basic() {}

GridAttachmentShPtr GridAttachment::create() {
	all.push_back(GridAttachmentShPtr(new GridAttachment()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

GridAttachmentShPtr GridAttachment::create(BasicWkPtr _parent) {
	auto ptr = GridAttachment::create();
	ptr->set_parent(_parent);
	return ptr;
}

void GridAttachment::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void GridAttachment::destroy() {
	destroy(getID());
}

BasicWkPtr GridAttachment::get_parent() {
	return parent;
}

void GridAttachment::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string GridAttachment::get_type() {
	return type;
}

CellCoordinatesAsDefinedPtrList GridAttachment::get_cell_coordinates_as_defineds() {
	return cell_coordinates_as_defineds;
}




void GridAttachment::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:CellCoordinatesAsDefined");
		while (true) {
			cell_coordinates_as_defineds.push_back(CellCoordinatesAsDefined::create(shared_from_this()));
			cell_coordinates_as_defineds.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:CellCoordinatesAsDefined");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
