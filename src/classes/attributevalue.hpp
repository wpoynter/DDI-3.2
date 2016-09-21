#ifndef ATTRIBUTEVALUE_HPP
#define	ATTRIBUTEVALUE_HPP

#include "basic.hpp"


class AttributeValue;

typedef std::shared_ptr<AttributeValue> AttributeValueShPtr;
typedef std::list<AttributeValueShPtr> AttributeValuePtrList;


class AttributeValue : public Basic {
private:
   
   
   std::string content;
public:
	AttributeValue();
	~AttributeValue() {}
	
	//Keep track of all objects 
	static std::list<AttributeValueShPtr> all;
	
	static AttributeValueShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* ATTRIBUTEVALUE_HPP */
