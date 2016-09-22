#ifndef CATEGORYSCHEMENAME_HPP
#define	CATEGORYSCHEMENAME_HPP

#include "basic.hpp"

#include "string.hpp"

class CategorySchemeName;

typedef std::shared_ptr<CategorySchemeName> CategorySchemeNameShPtr;
typedef std::list<CategorySchemeNameShPtr> CategorySchemeNamePtrList;


class CategorySchemeName : public Basic {
private:
   
   StringShPtr string;
   
   
   BasicWkPtr parent;
public:
	CategorySchemeName();
	~CategorySchemeName() {}
	
	//Keep track of all objects 
	static std::list<CategorySchemeNameShPtr> all;
	static std::string type;
	
	static CategorySchemeNameShPtr create();
	static CategorySchemeNameShPtr create(BasicWkPtr);
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

#endif	/* CATEGORYSCHEMENAME_HPP */
