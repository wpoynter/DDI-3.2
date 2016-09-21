#ifndef DATETYPECODE_HPP
#define	DATETYPECODE_HPP

#include "basic.hpp"


class DateTypeCode;

typedef std::shared_ptr<DateTypeCode> DateTypeCodeShPtr;
typedef std::list<DateTypeCodeShPtr> DateTypeCodePtrList;


class DateTypeCode : public Basic {
private:
   
   
   std::string content;
public:
	DateTypeCode();
	~DateTypeCode() {}
	
	//Keep track of all objects 
	static std::list<DateTypeCodeShPtr> all;
	
	static DateTypeCodeShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* DATETYPECODE_HPP */
