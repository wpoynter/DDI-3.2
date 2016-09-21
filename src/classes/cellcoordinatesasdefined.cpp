#include "cellcoordinatesasdefined.hpp"

std::list<CellCoordinatesAsDefinedShPtr> CellCoordinatesAsDefined::all;

CellCoordinatesAsDefined::CellCoordinatesAsDefined() :
Basic() {}

CellCoordinatesAsDefinedShPtr CellCoordinatesAsDefined::create() {
	all.push_back(CellCoordinatesAsDefinedShPtr(new CellCoordinatesAsDefined()));
	return all.back();
}

void CellCoordinatesAsDefined::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CellCoordinatesAsDefined::destroy() {
	destroy(getID());
}

SelectDimensionPtrList CellCoordinatesAsDefined::get_select_dimensions() {
	return select_dimensions;
}




void CellCoordinatesAsDefined::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:SelectDimension");
		while (true) {
			select_dimensions.push_back(SelectDimension::create());
			select_dimensions.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:SelectDimension");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
