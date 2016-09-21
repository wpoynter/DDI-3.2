#include "gridattachment.hpp"

std::list<GridAttachmentShPtr> GridAttachment::all;

GridAttachment::GridAttachment() :
Basic() {}

GridAttachmentShPtr GridAttachment::create() {
	all.push_back(GridAttachmentShPtr(new GridAttachment()));
	return all.back();
}

void GridAttachment::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void GridAttachment::destroy() {
	destroy(getID());
}

CellCoordinatesAsDefinedPtrList GridAttachment::get_cell_coordinates_as_defineds() {
	return cell_coordinates_as_defineds;
}




void GridAttachment::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:CellCoordinatesAsDefined");
		while (true) {
			cell_coordinates_as_defineds.push_back(CellCoordinatesAsDefined::create());
			cell_coordinates_as_defineds.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:CellCoordinatesAsDefined");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
