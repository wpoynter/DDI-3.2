#ifndef TEXTDOMAIN_HPP
#define	TEXTDOMAIN_HPP

#include "basic.hpp"

#include "label.hpp"

class TextDomain;

typedef std::shared_ptr<TextDomain> TextDomainShPtr;
typedef std::list<TextDomainShPtr> TextDomainPtrList;


class TextDomain : public Basic {
private:
   
   LabelPtrList labels;
   std::string max_length;
   
public:
	TextDomain();
	~TextDomain() {}
	
	//Keep track of all objects 
	static std::list<TextDomainShPtr> all;
	
	static TextDomainShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	LabelPtrList get_labels();
	
	std::string get_max_length();
	void set_max_length(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* TEXTDOMAIN_HPP */
