#ifndef CELLCOORDINATESASDEFINED_HPP
#define	CELLCOORDINATESASDEFINED_HPP

#include "basic.hpp"

#include "selectdimension.hpp"

class CellCoordinatesAsDefined;

typedef std::shared_ptr<CellCoordinatesAsDefined> CellCoordinatesAsDefinedShPtr;
typedef std::list<CellCoordinatesAsDefinedShPtr> CellCoordinatesAsDefinedPtrList;


class CellCoordinatesAsDefined : public Basic {
private:
   
   SelectDimensionPtrList select_dimensions;
   
   
public:
	CellCoordinatesAsDefined();
	~CellCoordinatesAsDefined() {}
	
	//Keep track of all objects 
	static std::list<CellCoordinatesAsDefinedShPtr> all;
	
	static CellCoordinatesAsDefinedShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	SelectDimensionPtrList get_select_dimensions();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CELLCOORDINATESASDEFINED_HPP */
