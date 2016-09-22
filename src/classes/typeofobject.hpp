#ifndef TYPEOFOBJECT_HPP
#define	TYPEOFOBJECT_HPP

#include "basic.hpp"


class TypeOfObject;

typedef std::shared_ptr<TypeOfObject> TypeOfObjectShPtr;
typedef std::list<TypeOfObjectShPtr> TypeOfObjectPtrList;


class TypeOfObject : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	TypeOfObject();
	~TypeOfObject() {}
	
	//Keep track of all objects 
	static std::list<TypeOfObjectShPtr> all;
	static std::string type;
	
	static TypeOfObjectShPtr create();
	static TypeOfObjectShPtr create(BasicWkPtr);
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

#endif	/* TYPEOFOBJECT_HPP */
