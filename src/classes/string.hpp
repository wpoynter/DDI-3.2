#ifndef STRING_HPP
#define	STRING_HPP

#include "basic.hpp"


class String;

typedef std::shared_ptr<String> StringShPtr;
typedef std::list<StringShPtr> StringPtrList;


class String : public Basic {
private:
   
   std::string lang;
   std::string content;
   BasicWkPtr parent;
public:
	String();
	~String() {}
	
	//Keep track of all objects 
	static std::list<StringShPtr> all;
	static std::string type;
	
	static StringShPtr create();
	static StringShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	std::string get_lang();
	void set_lang(std::string);
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* STRING_HPP */
