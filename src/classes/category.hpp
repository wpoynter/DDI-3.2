#ifndef CATEGORY_HPP
#define	CATEGORY_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "categoryname.hpp"
#include "label.hpp"

class Category;

typedef std::shared_ptr<Category> CategoryShPtr;
typedef std::list<CategoryShPtr> CategoryPtrList;


class Category : public Basic {
private:
   
   URNShPtr urn;
   CategoryNamePtrList category_names;
   LabelPtrList labels;
   
   
public:
	Category();
	~Category() {}
	
	//Keep track of all objects 
	static std::list<CategoryShPtr> all;
	
	static CategoryShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	CategoryNamePtrList get_category_names();
	LabelPtrList get_labels();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CATEGORY_HPP */
