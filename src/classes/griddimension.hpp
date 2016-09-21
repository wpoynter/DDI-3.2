#ifndef GRIDDIMENSION_HPP
#define	GRIDDIMENSION_HPP

#include "basic.hpp"

#include "codedomain.hpp"

class GridDimension;

typedef std::shared_ptr<GridDimension> GridDimensionShPtr;
typedef std::list<GridDimensionShPtr> GridDimensionPtrList;


class GridDimension : public Basic {
private:
   
   CodeDomainPtrList code_domains;
   std::string rank;std::string display_code;std::string display_label;
   
public:
	GridDimension();
	~GridDimension() {}
	
	//Keep track of all objects 
	static std::list<GridDimensionShPtr> all;
	
	static GridDimensionShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	CodeDomainPtrList get_code_domains();
	
	std::string get_rank();std::string get_display_code();std::string get_display_label();
	void set_rank(std::string);void set_display_code(std::string);void set_display_label(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* GRIDDIMENSION_HPP */
