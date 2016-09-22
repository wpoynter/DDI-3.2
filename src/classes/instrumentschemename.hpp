#ifndef INSTRUMENTSCHEMENAME_HPP
#define	INSTRUMENTSCHEMENAME_HPP

#include "basic.hpp"

#include "string.hpp"

class InstrumentSchemeName;

typedef std::shared_ptr<InstrumentSchemeName> InstrumentSchemeNameShPtr;
typedef std::list<InstrumentSchemeNameShPtr> InstrumentSchemeNamePtrList;


class InstrumentSchemeName : public Basic {
private:
   
   StringShPtr string;
   
   
   BasicWkPtr parent;
public:
	InstrumentSchemeName();
	~InstrumentSchemeName() {}
	
	//Keep track of all objects 
	static std::list<InstrumentSchemeNameShPtr> all;
	static std::string type;
	
	static InstrumentSchemeNameShPtr create();
	static InstrumentSchemeNameShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INSTRUMENTSCHEMENAME_HPP */
