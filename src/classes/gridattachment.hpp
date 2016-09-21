#ifndef GRIDATTACHMENT_HPP
#define	GRIDATTACHMENT_HPP

#include "basic.hpp"

#include "cellcoordinatesasdefined.hpp"

class GridAttachment;

typedef std::shared_ptr<GridAttachment> GridAttachmentShPtr;
typedef std::list<GridAttachmentShPtr> GridAttachmentPtrList;


class GridAttachment : public Basic {
private:
   
   CellCoordinatesAsDefinedPtrList cell_coordinates_as_defineds;
   
   
public:
	GridAttachment();
	~GridAttachment() {}
	
	//Keep track of all objects 
	static std::list<GridAttachmentShPtr> all;
	
	static GridAttachmentShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	CellCoordinatesAsDefinedPtrList get_cell_coordinates_as_defineds();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* GRIDATTACHMENT_HPP */
