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
   
   
public:
	CategorySchemeName();
	~CategorySchemeName() {}
	
	//Keep track of all objects 
	static std::list<CategorySchemeNameShPtr> all;
	
	static CategorySchemeNameShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CATEGORYSCHEMENAME_HPP */
