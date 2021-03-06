#ifndef DDIINSTANCE_HPP
#define	DDIINSTANCE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "citation.hpp"
#include "resourcepackage.hpp"

class DDIInstance;

typedef std::shared_ptr<DDIInstance> DDIInstanceShPtr;
typedef std::list<DDIInstanceShPtr> DDIInstancePtrList;


class DDIInstance : public Basic {
private:
   
   URNShPtr urn;
   CitationPtrList citations;
   ResourcePackagePtrList resource_packages;
   std::string version_date;
   
   BasicWkPtr parent;
public:
	DDIInstance();
	~DDIInstance() {}
	
	//Keep track of all objects 
	static std::list<DDIInstanceShPtr> all;
	static std::string type;
	
	static DDIInstanceShPtr create();
	static DDIInstanceShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	CitationPtrList get_citations();
	ResourcePackagePtrList get_resource_packages();
	
	std::string get_version_date();
	void set_version_date(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* DDIINSTANCE_HPP */
