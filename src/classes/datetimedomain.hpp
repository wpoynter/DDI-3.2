#ifndef DATETIMEDOMAIN_HPP
#define	DATETIMEDOMAIN_HPP

#include "basic.hpp"

#include "datefieldformat.hpp"
#include "datetypecode.hpp"
#include "label.hpp"

class DateTimeDomain;

typedef std::shared_ptr<DateTimeDomain> DateTimeDomainShPtr;
typedef std::list<DateTimeDomainShPtr> DateTimeDomainPtrList;


class DateTimeDomain : public Basic {
private:
   
   DateFieldFormatPtrList date_field_formats;
   DateTypeCodePtrList date_type_codes;
   LabelPtrList labels;
   
   
   BasicWkPtr parent;
public:
	DateTimeDomain();
	~DateTimeDomain() {}
	
	//Keep track of all objects 
	static std::list<DateTimeDomainShPtr> all;
	static std::string type;
	
	static DateTimeDomainShPtr create();
	static DateTimeDomainShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	DateFieldFormatPtrList get_date_field_formats();
	DateTypeCodePtrList get_date_type_codes();
	LabelPtrList get_labels();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* DATETIMEDOMAIN_HPP */
