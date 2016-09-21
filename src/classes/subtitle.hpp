#ifndef SUBTITLE_HPP
#define	SUBTITLE_HPP

#include "basic.hpp"

#include "string.hpp"

class SubTitle;

typedef std::shared_ptr<SubTitle> SubTitleShPtr;
typedef std::list<SubTitleShPtr> SubTitlePtrList;


class SubTitle : public Basic {
private:
   
   StringShPtr string;
   
   
public:
	SubTitle();
	~SubTitle() {}
	
	//Keep track of all objects 
	static std::list<SubTitleShPtr> all;
	
	static SubTitleShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* SUBTITLE_HPP */
