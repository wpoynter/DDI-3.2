#ifndef INSTRUMENTNAME_HPP
#define	INSTRUMENTNAME_HPP

#include "basic.hpp"

#include "string.hpp"

class InstrumentName;

typedef std::shared_ptr<InstrumentName> InstrumentNameShPtr;
typedef std::list<InstrumentNameShPtr> InstrumentNamePtrList;


class InstrumentName : public Basic {
private:
   
   StringShPtr string;
   
   
public:
	InstrumentName();
	~InstrumentName() {}
	
	//Keep track of all objects 
	static std::list<InstrumentNameShPtr> all;
	
	static InstrumentNameShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INSTRUMENTNAME_HPP */
