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
   
   
   BasicWkPtr parent;
public:
	ConstructName();
	~ConstructName() {}
	
	//Keep track of all objects 
	static std::list<ConstructNameShPtr> all;
	static std::string type;
	
	static ConstructNameShPtr create();
	static ConstructNameShPtr create(BasicWkPtr);
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

#endif	/* CONSTRUCTNAME_HPP */
