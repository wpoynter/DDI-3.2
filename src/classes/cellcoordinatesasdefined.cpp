#include "cellcoordinatesasdefined.hpp"

std::list<CellCoordinatesAsDefinedShPtr> CellCoordinatesAsDefined::all;
std::string CellCoordinatesAsDefined::type = "CellCoordinatesAsDefined";

CellCoordinatesAsDefined::CellCoordinatesAsDefined() :
Basic() {}

CellCoordinatesAsDefinedShPtr CellCoordinatesAsDefined::create() {
	all.push_back(CellCoordinatesAsDefinedShPtr(new CellCoordinatesAsDefined()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

CellCoordinatesAsDefinedShPtr CellCoordinatesAsDefined::create(BasicWkPtr _parent) {
	auto ptr = CellCoordinatesAsDefined::create();
	ptr->set_parent(_parent);
	return ptr;
}

void CellCoordinatesAsDefined::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void CellCoordinatesAsDefined::destroy() {
	destroy(getID());
}

BasicWkPtr CellCoordinatesAsDefined::get_parent() {
	return parent;
}

void CellCoordinatesAsDefined::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string CellCoordinatesAsDefined::get_type() {
	return type;
}

SelectDimensionPtrList CellCoordinatesAsDefined::get_select_dimensions() {
	return select_dimensions;
}




void CellCoordinatesAsDefined::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:SelectDimension");
		while (true) {
			select_dimensions.push_back(SelectDimension::create(shared_from_this()));
			select_dimensions.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:SelectDimension");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
