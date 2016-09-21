#ifndef RESPONSEUNIT_HPP
#define	RESPONSEUNIT_HPP

#include "basic.hpp"


class ResponseUnit;

typedef std::shared_ptr<ResponseUnit> ResponseUnitShPtr;
typedef std::list<ResponseUnitShPtr> ResponseUnitPtrList;


class ResponseUnit : public Basic {
private:
   
   
   std::string content;
public:
	ResponseUnit();
	~ResponseUnit() {}
	
	//Keep track of all objects 
	static std::list<ResponseUnitShPtr> all;
	
	static ResponseUnitShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* RESPONSEUNIT_HPP */
