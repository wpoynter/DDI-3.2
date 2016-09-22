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
   
   
   BasicWkPtr parent;
public:
	Citation();
	~Citation() {}
	
	//Keep track of all objects 
	static std::list<CitationShPtr> all;
	static std::string type;
	
	static CitationShPtr create();
	static CitationShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	TitleShPtr get_title();
	void set_title(TitleShPtr);
	
	SubTitlePtrList get_sub_titles();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CITATION_HPP */
