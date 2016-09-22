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
   
   
   BasicWkPtr parent;
public:
	InstrumentName();
	~InstrumentName() {}
	
	//Keep track of all objects 
	static std::list<InstrumentNameShPtr> all;
	static std::string type;
	
	static InstrumentNameShPtr create();
	static InstrumentNameShPtr create(BasicWkPtr);
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

#endif	/* INSTRUMENTNAME_HPP */
