#ifndef URN_HPP
#define	URN_HPP

#include "basic.hpp"


class URN;

typedef std::shared_ptr<URN> URNShPtr;
typedef std::list<URNShPtr> URNPtrList;


class URN : public Basic {
private:
   
   
   std::string content;
public:
	URN();
	~URN() {}
	
	//Keep track of all objects 
	static std::list<URNShPtr> all;
	
	static URNShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* URN_HPP */
