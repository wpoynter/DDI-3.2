#ifndef NUMERICDOMAIN_HPP
#define	NUMERICDOMAIN_HPP

#include "basic.hpp"

#include "numberrange.hpp"
#include "numerictypecode.hpp"
#include "label.hpp"

class NumericDomain;

typedef std::shared_ptr<NumericDomain> NumericDomainShPtr;
typedef std::list<NumericDomainShPtr> NumericDomainPtrList;


class NumericDomain : public Basic {
private:
   
   NumberRangePtrList number_ranges;
   NumericTypeCodePtrList numeric_type_codes;
   LabelPtrList labels;
   
   
   BasicWkPtr parent;
public:
	NumericDomain();
	~NumericDomain() {}
	
	//Keep track of all objects 
	static std::list<NumericDomainShPtr> all;
	static std::string type;
	
	static NumericDomainShPtr create();
	static NumericDomainShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	NumberRangePtrList get_number_ranges();
	NumericTypeCodePtrList get_numeric_type_codes();
	LabelPtrList get_labels();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* NUMERICDOMAIN_HPP */
