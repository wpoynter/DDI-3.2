#ifndef INSTRUMENTSCHEME_HPP
#define	INSTRUMENTSCHEME_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "instrumentschemename.hpp"
#include "instrument.hpp"

class InstrumentScheme;

typedef std::shared_ptr<InstrumentScheme> InstrumentSchemeShPtr;
typedef std::list<InstrumentSchemeShPtr> InstrumentSchemePtrList;


class InstrumentScheme : public Basic {
private:
   
   URNShPtr urn;
   InstrumentSchemeNamePtrList instrument_scheme_names;
   InstrumentPtrList instruments;
   
   
   BasicWkPtr parent;
public:
	InstrumentScheme();
	~InstrumentScheme() {}
	
	//Keep track of all objects 
	static std::list<InstrumentSchemeShPtr> all;
	static std::string type;
	
	static InstrumentSchemeShPtr create();
	static InstrumentSchemeShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	InstrumentSchemeNamePtrList get_instrument_scheme_names();
	InstrumentPtrList get_instruments();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* INSTRUMENTSCHEME_HPP */
