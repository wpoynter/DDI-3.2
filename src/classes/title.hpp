#ifndef TITLE_HPP
#define	TITLE_HPP

#include "basic.hpp"

#include "string.hpp"

class Title;

typedef std::shared_ptr<Title> TitleShPtr;
typedef std::list<TitleShPtr> TitlePtrList;


class Title : public Basic {
private:
   
   StringShPtr string;
   
   
   BasicWkPtr parent;
public:
	Title();
	~Title() {}
	
	//Keep track of all objects 
	static std::list<TitleShPtr> all;
	static std::string type;
	
	static TitleShPtr create();
	static TitleShPtr create(BasicWkPtr);
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

#endif	/* TITLE_HPP */
