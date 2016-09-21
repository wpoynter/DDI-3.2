#ifndef CONTENT_HPP
#define	CONTENT_HPP

#include "basic.hpp"


class Content;

typedef std::shared_ptr<Content> ContentShPtr;
typedef std::list<ContentShPtr> ContentPtrList;


class Content : public Basic {
private:
   
   std::string lang;
   std::string content;
public:
	Content();
	~Content() {}
	
	//Keep track of all objects 
	static std::list<ContentShPtr> all;
	
	static ContentShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	std::string get_lang();
	void set_lang(std::string);
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* CONTENT_HPP */
