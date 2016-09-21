#ifndef ATTRIBUTEKEY_HPP
#define	ATTRIBUTEKEY_HPP

#include "basic.hpp"


class AttributeKey;

typedef std::shared_ptr<AttributeKey> AttributeKeyShPtr;
typedef std::list<AttributeKeyShPtr> AttributeKeyPtrList;


class AttributeKey : public Basic {
private:
   
   
   std::string content;
public:
	AttributeKey();
	~AttributeKey() {}
	
	//Keep track of all objects 
	static std::list<AttributeKeyShPtr> all;
	
	static AttributeKeyShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* ATTRIBUTEKEY_HPP */
