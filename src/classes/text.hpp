#ifndef TEXT_HPP
#define	TEXT_HPP

#include "basic.hpp"


class Text;

typedef std::shared_ptr<Text> TextShPtr;
typedef std::list<TextShPtr> TextPtrList;


class Text : public Basic {
private:
   
   
   std::string content;
public:
	Text();
	~Text() {}
	
	//Keep track of all objects 
	static std::list<TextShPtr> all;
	
	static TextShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* TEXT_HPP */
