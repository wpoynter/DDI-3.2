#ifndef SELECTDIMENSION_HPP
#define	SELECTDIMENSION_HPP

#include "basic.hpp"


class SelectDimension;

typedef std::shared_ptr<SelectDimension> SelectDimensionShPtr;
typedef std::list<SelectDimensionShPtr> SelectDimensionPtrList;


class SelectDimension : public Basic {
private:
   
   std::string rank;std::string all_value;std::string specific_value;
   
   BasicWkPtr parent;
public:
	SelectDimension();
	~SelectDimension() {}
	
	//Keep track of all objects 
	static std::list<SelectDimensionShPtr> all;
	static std::string type;
	
	static SelectDimensionShPtr create();
	static SelectDimensionShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	std::string get_rank();std::string get_all_value();std::string get_specific_value();
	void set_rank(std::string);void set_all_value(std::string);void set_specific_value(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* SELECTDIMENSION_HPP */
