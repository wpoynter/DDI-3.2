#ifndef DATACOLLECTION_HPP
#define	DATACOLLECTION_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "datacollectionmodulename.hpp"
#include "controlconstructscheme.hpp"
#include "interviewerinstructionscheme.hpp"
#include "instrumentscheme.hpp"

class DataCollection;

typedef std::shared_ptr<DataCollection> DataCollectionShPtr;
typedef std::list<DataCollectionShPtr> DataCollectionPtrList;


class DataCollection : public Basic {
private:
   
   URNShPtr urn;
   DataCollectionModuleNamePtrList data_collection_module_names;
   ControlConstructSchemePtrList control_construct_schemes;
   InterviewerInstructionSchemePtrList interviewer_instruction_schemes;
   InstrumentSchemePtrList instrument_schemes;
   std::string version_date;
   
   BasicWkPtr parent;
public:
	DataCollection();
	~DataCollection() {}
	
	//Keep track of all objects 
	static std::list<DataCollectionShPtr> all;
	static std::string type;
	
	static DataCollectionShPtr create();
	static DataCollectionShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	DataCollectionModuleNamePtrList get_data_collection_module_names();
	ControlConstructSchemePtrList get_control_construct_schemes();
	InterviewerInstructionSchemePtrList get_interviewer_instruction_schemes();
	InstrumentSchemePtrList get_instrument_schemes();
	
	std::string get_version_date();
	void set_version_date(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* DATACOLLECTION_HPP */
