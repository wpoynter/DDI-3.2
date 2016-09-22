#ifndef URN_HPP
#define	URN_HPP

#include "basic.hpp"


class URN;

typedef std::shared_ptr<URN> URNShPtr;
typedef std::list<URNShPtr> URNPtrList;


class URN : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	URN();
	~URN() {}
	
	//Keep track of all objects 
	static std::list<URNShPtr> all;
	static std::string type;
	
	static URNShPtr create();
	static URNShPtr create(BasicWkPtr);
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

#endif	/* URN_HPP */
