#ifndef CONTROLCONSTRUCTSCHEMENAME_HPP
#define	CONTROLCONSTRUCTSCHEMENAME_HPP

#include "basic.hpp"

#include "string.hpp"

class ControlConstructSchemeName;

typedef std::shared_ptr<ControlConstructSchemeName> ControlConstructSchemeNameShPtr;
typedef std::list<ControlConstructSchemeNameShPtr> ControlConstructSchemeNamePtrList;


class ControlConstructSchemeName : public Basic {
private:
   
   StringShPtr string;
   
   
public:
	ControlConstructSchemeName();
	~ControlConstructSchemeName() {}
	
	//Keep track of all objects 
	static std::list<ControlConstructSchemeNameShPtr> all;
	
	static ControlConstructSchemeNameShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CONTROLCONSTRUCTSCHEMENAME_HPP */
