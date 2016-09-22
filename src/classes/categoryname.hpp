#ifndef CATEGORYNAME_HPP
#define	CATEGORYNAME_HPP

#include "basic.hpp"

#include "string.hpp"

class CategoryName;

typedef std::shared_ptr<CategoryName> CategoryNameShPtr;
typedef std::list<CategoryNameShPtr> CategoryNamePtrList;


class CategoryName : public Basic {
private:
   
   StringShPtr string;
   
   
   BasicWkPtr parent;
public:
	CategoryName();
	~CategoryName() {}
	
	//Keep track of all objects 
	static std::list<CategoryNameShPtr> all;
	static std::string type;
	
	static CategoryNameShPtr create();
	static CategoryNameShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CATEGORYNAME_HPP */
