#ifndef DATACOLLECTIONMODULENAME_HPP
#define	DATACOLLECTIONMODULENAME_HPP

#include "basic.hpp"

#include "string.hpp"

class DataCollectionModuleName;

typedef std::shared_ptr<DataCollectionModuleName> DataCollectionModuleNameShPtr;
typedef std::list<DataCollectionModuleNameShPtr> DataCollectionModuleNamePtrList;


class DataCollectionModuleName : public Basic {
private:
   
   StringShPtr string;
   
   
   BasicWkPtr parent;
public:
	DataCollectionModuleName();
	~DataCollectionModuleName() {}
	
	//Keep track of all objects 
	static std::list<DataCollectionModuleNameShPtr> all;
	static std::string type;
	
	static DataCollectionModuleNameShPtr create();
	static DataCollectionModuleNameShPtr create(BasicWkPtr);
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

#endif	/* DATACOLLECTIONMODULENAME_HPP */
