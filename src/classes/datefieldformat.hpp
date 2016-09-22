#ifndef DATEFIELDFORMAT_HPP
#define	DATEFIELDFORMAT_HPP

#include "basic.hpp"


class DateFieldFormat;

typedef std::shared_ptr<DateFieldFormat> DateFieldFormatShPtr;
typedef std::list<DateFieldFormatShPtr> DateFieldFormatPtrList;


class DateFieldFormat : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	DateFieldFormat();
	~DateFieldFormat() {}
	
	//Keep track of all objects 
	static std::list<DateFieldFormatShPtr> all;
	static std::string type;
	
	static DateFieldFormatShPtr create();
	static DateFieldFormatShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* DATEFIELDFORMAT_HPP */
