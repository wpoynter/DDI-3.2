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
   
   
   BasicWkPtr parent;
public:
	CellCoordinatesAsDefined();
	~CellCoordinatesAsDefined() {}
	
	//Keep track of all objects 
	static std::list<CellCoordinatesAsDefinedShPtr> all;
	static std::string type;
	
	static CellCoordinatesAsDefinedShPtr create();
	static CellCoordinatesAsDefinedShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	SelectDimensionPtrList get_select_dimensions();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CELLCOORDINATESASDEFINED_HPP */
