#ifndef NUMBERRANGE_HPP
#define	NUMBERRANGE_HPP

#include "basic.hpp"

#include "low.hpp"

class NumberRange;

typedef std::shared_ptr<NumberRange> NumberRangeShPtr;
typedef std::list<NumberRangeShPtr> NumberRangePtrList;


class NumberRange : public Basic {
private:
   
   LowPtrList lows;
   
   
   BasicWkPtr parent;
public:
	NumberRange();
	~NumberRange() {}
	
	//Keep track of all objects 
	static std::list<NumberRangeShPtr> all;
	static std::string type;
	
	static NumberRangeShPtr create();
	static NumberRangeShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	LowPtrList get_lows();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* NUMBERRANGE_HPP */
