#ifndef CITATION_HPP
#define	CITATION_HPP

#include "basic.hpp"

#include "title.hpp"
#include "subtitle.hpp"

class Citation;

typedef std::shared_ptr<Citation> CitationShPtr;
typedef std::list<CitationShPtr> CitationPtrList;


class Citation : public Basic {
private:
   
   TitleShPtr title;
   SubTitlePtrList sub_titles;
   
   
public:
	Citation();
	~Citation() {}
	
	//Keep track of all objects 
	static std::list<CitationShPtr> all;
	
	static CitationShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	TitleShPtr get_title();
	void set_title(TitleShPtr);
	
	SubTitlePtrList get_sub_titles();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CITATION_HPP */
