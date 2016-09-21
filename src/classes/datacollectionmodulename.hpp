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
   
   
public:
	DataCollectionModuleName();
	~DataCollectionModuleName() {}
	
	//Keep track of all objects 
	static std::list<DataCollectionModuleNameShPtr> all;
	
	static DataCollectionModuleNameShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* DATACOLLECTIONMODULENAME_HPP */
