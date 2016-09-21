#ifndef CONSTRUCTNAME_HPP
#define	CONSTRUCTNAME_HPP

#include "basic.hpp"

#include "string.hpp"

class ConstructName;

typedef std::shared_ptr<ConstructName> ConstructNameShPtr;
typedef std::list<ConstructNameShPtr> ConstructNamePtrList;


class ConstructName : public Basic {
private:
   
   StringShPtr string;
   
   
public:
	ConstructName();
	~ConstructName() {}
	
	//Keep track of all objects 
	static std::list<ConstructNameShPtr> all;
	
	static ConstructNameShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CONSTRUCTNAME_HPP */
