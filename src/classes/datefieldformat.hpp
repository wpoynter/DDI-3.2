#ifndef DATEFIELDFORMAT_HPP
#define	DATEFIELDFORMAT_HPP

#include "basic.hpp"


class DateFieldFormat;

typedef std::shared_ptr<DateFieldFormat> DateFieldFormatShPtr;
typedef std::list<DateFieldFormatShPtr> DateFieldFormatPtrList;


class DateFieldFormat : public Basic {
private:
   
   
   std::string content;
public:
	DateFieldFormat();
	~DateFieldFormat() {}
	
	//Keep track of all objects 
	static std::list<DateFieldFormatShPtr> all;
	
	static DateFieldFormatShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* DATEFIELDFORMAT_HPP */
