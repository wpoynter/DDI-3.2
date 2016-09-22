#ifndef RESPONSEUNIT_HPP
#define	RESPONSEUNIT_HPP

#include "basic.hpp"


class ResponseUnit;

typedef std::shared_ptr<ResponseUnit> ResponseUnitShPtr;
typedef std::list<ResponseUnitShPtr> ResponseUnitPtrList;


class ResponseUnit : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	ResponseUnit();
	~ResponseUnit() {}
	
	//Keep track of all objects 
	static std::list<ResponseUnitShPtr> all;
	static std::string type;
	
	static ResponseUnitShPtr create();
	static ResponseUnitShPtr create(BasicWkPtr);
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

#endif	/* RESPONSEUNIT_HPP */
