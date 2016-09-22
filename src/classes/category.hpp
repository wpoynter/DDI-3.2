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
   
   
   BasicWkPtr parent;
public:
	Category();
	~Category() {}
	
	//Keep track of all objects 
	static std::list<CategoryShPtr> all;
	static std::string type;
	
	static CategoryShPtr create();
	static CategoryShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	CategoryNamePtrList get_category_names();
	LabelPtrList get_labels();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CATEGORY_HPP */
