#ifndef LOW_HPP
#define	LOW_HPP

#include "basic.hpp"


class Low;

typedef std::shared_ptr<Low> LowShPtr;
typedef std::list<LowShPtr> LowPtrList;


class Low : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	Low();
	~Low() {}
	
	//Keep track of all objects 
	static std::list<LowShPtr> all;
	static std::string type;
	
	static LowShPtr create();
	static LowShPtr create(BasicWkPtr);
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

#endif	/* LOW_HPP */
