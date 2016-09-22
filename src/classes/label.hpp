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
   
   
   BasicWkPtr parent;
public:
	Label();
	~Label() {}
	
	//Keep track of all objects 
	static std::list<LabelShPtr> all;
	static std::string type;
	
	static LabelShPtr create();
	static LabelShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	ContentPtrList get_contents();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* LABEL_HPP */
