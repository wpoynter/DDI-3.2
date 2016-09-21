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
   
   
public:
	Title();
	~Title() {}
	
	//Keep track of all objects 
	static std::list<TitleShPtr> all;
	
	static TitleShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* TITLE_HPP */
