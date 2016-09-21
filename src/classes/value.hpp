#ifndef VALUE_HPP
#define	VALUE_HPP

#include "basic.hpp"


class Value;

typedef std::shared_ptr<Value> ValueShPtr;
typedef std::list<ValueShPtr> ValuePtrList;


class Value : public Basic {
private:
   
   
   std::string content;
public:
	Value();
	~Value() {}
	
	//Keep track of all objects 
	static std::list<ValueShPtr> all;
	
	static ValueShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* VALUE_HPP */
