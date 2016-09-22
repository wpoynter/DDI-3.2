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
   
   
   BasicWkPtr parent;
public:
	GridAttachment();
	~GridAttachment() {}
	
	//Keep track of all objects 
	static std::list<GridAttachmentShPtr> all;
	static std::string type;
	
	static GridAttachmentShPtr create();
	static GridAttachmentShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	CellCoordinatesAsDefinedPtrList get_cell_coordinates_as_defineds();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* GRIDATTACHMENT_HPP */
