#ifndef INSTRUMENT_HPP
#define	INSTRUMENT_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "instrumentname.hpp"
#include "controlconstructreference.hpp"

class Instrument;

typedef std::shared_ptr<Instrument> InstrumentShPtr;
typedef std::list<InstrumentShPtr> InstrumentPtrList;


class Instrument : public Basic {
private:
   
   URNShPtr urn;
   InstrumentNamePtrList instrument_names;
   ControlConstructReferencePtrList control_construct_references;
   
   
   BasicWkPtr parent;
public:
	Instrument();
	~Instrument() {}
	
	//Keep track of all objects 
	static std::list<InstrumentShPtr> all;
	static std::string type;
	
	static InstrumentShPtr create();
	static InstrumentShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	InstrumentNamePtrList get_instrument_names();
	ControlConstructReferencePtrList get_control_construct_references();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INSTRUMENT_HPP */
