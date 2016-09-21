#ifndef LABEL_HPP
#define	LABEL_HPP

#include "basic.hpp"

#include "content.hpp"

class Label;

typedef std::shared_ptr<Label> LabelShPtr;
typedef std::list<LabelShPtr> LabelPtrList;


class Label : public Basic {
private:
   
   ContentPtrList contents;
   
   
public:
	Label();
	~Label() {}
	
	//Keep track of all objects 
	static std::list<LabelShPtr> all;
	
	static LabelShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	ContentPtrList get_contents();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* LABEL_HPP */
