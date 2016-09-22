#ifndef TEXT_HPP
#define	TEXT_HPP

#include "basic.hpp"


class Text;

typedef std::shared_ptr<Text> TextShPtr;
typedef std::list<TextShPtr> TextPtrList;


class Text : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	Text();
	~Text() {}
	
	//Keep track of all objects 
	static std::list<TextShPtr> all;
	static std::string type;
	
	static TextShPtr create();
	static TextShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* TEXT_HPP */
