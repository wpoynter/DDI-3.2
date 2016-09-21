#ifndef CATEGORYSCHEME_HPP
#define	CATEGORYSCHEME_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "categoryschemename.hpp"
#include "category.hpp"

class CategoryScheme;

typedef std::shared_ptr<CategoryScheme> CategorySchemeShPtr;
typedef std::list<CategorySchemeShPtr> CategorySchemePtrList;


class CategoryScheme : public Basic {
private:
   
   URNShPtr urn;
   CategorySchemeNamePtrList category_scheme_names;
   CategoryPtrList categories;
   std::string version_date;
   
public:
	CategoryScheme();
	~CategoryScheme() {}
	
	//Keep track of all objects 
	static std::list<CategorySchemeShPtr> all;
	
	static CategorySchemeShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	CategorySchemeNamePtrList get_category_scheme_names();
	CategoryPtrList get_categories();
	
	std::string get_version_date();
	void set_version_date(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CATEGORYSCHEME_HPP */
