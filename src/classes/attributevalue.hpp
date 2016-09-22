#ifndef ATTRIBUTEVALUE_HPP
#define	ATTRIBUTEVALUE_HPP

#include "basic.hpp"


class AttributeValue;

typedef std::shared_ptr<AttributeValue> AttributeValueShPtr;
typedef std::list<AttributeValueShPtr> AttributeValuePtrList;


class AttributeValue : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	AttributeValue();
	~AttributeValue() {}
	
	//Keep track of all objects 
	static std::list<AttributeValueShPtr> all;
	static std::string type;
	
	static AttributeValueShPtr create();
	static AttributeValueShPtr create(BasicWkPtr);
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

#endif	/* ATTRIBUTEVALUE_HPP */
