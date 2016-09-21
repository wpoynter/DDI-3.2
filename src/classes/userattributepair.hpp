#ifndef USERATTRIBUTEPAIR_HPP
#define	USERATTRIBUTEPAIR_HPP

#include "basic.hpp"

#include "attributekey.hpp"
#include "attributevalue.hpp"

class UserAttributePair;

typedef std::shared_ptr<UserAttributePair> UserAttributePairShPtr;
typedef std::list<UserAttributePairShPtr> UserAttributePairPtrList;


class UserAttributePair : public Basic {
private:
   
   AttributeKeyPtrList attribute_keys;
   AttributeValuePtrList attribute_values;
   
   
public:
	UserAttributePair();
	~UserAttributePair() {}
	
	//Keep track of all objects 
	static std::list<UserAttributePairShPtr> all;
	
	static UserAttributePairShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	AttributeKeyPtrList get_attribute_keys();
	AttributeValuePtrList get_attribute_values();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* USERATTRIBUTEPAIR_HPP */
