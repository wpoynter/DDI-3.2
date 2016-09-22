#ifndef ATTRIBUTEKEY_HPP
#define	ATTRIBUTEKEY_HPP

#include "basic.hpp"


class AttributeKey;

typedef std::shared_ptr<AttributeKey> AttributeKeyShPtr;
typedef std::list<AttributeKeyShPtr> AttributeKeyPtrList;


class AttributeKey : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	AttributeKey();
	~AttributeKey() {}
	
	//Keep track of all objects 
	static std::list<AttributeKeyShPtr> all;
	static std::string type;
	
	static AttributeKeyShPtr create();
	static AttributeKeyShPtr create(BasicWkPtr);
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

#endif	/* ATTRIBUTEKEY_HPP */
