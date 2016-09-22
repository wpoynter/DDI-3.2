#ifndef STRUCTUREDMIXEDGRIDRESPONSEDOMAIN_HPP
#define	STRUCTUREDMIXEDGRIDRESPONSEDOMAIN_HPP

#include "basic.hpp"

#include "gridresponsedomain.hpp"

class StructuredMixedGridResponseDomain;

typedef std::shared_ptr<StructuredMixedGridResponseDomain> StructuredMixedGridResponseDomainShPtr;
typedef std::list<StructuredMixedGridResponseDomainShPtr> StructuredMixedGridResponseDomainPtrList;


class StructuredMixedGridResponseDomain : public Basic {
private:
   
   GridResponseDomainPtrList grid_response_domains;
   
   
   BasicWkPtr parent;
public:
	StructuredMixedGridResponseDomain();
	~StructuredMixedGridResponseDomain() {}
	
	//Keep track of all objects 
	static std::list<StructuredMixedGridResponseDomainShPtr> all;
	static std::string type;
	
	static StructuredMixedGridResponseDomainShPtr create();
	static StructuredMixedGridResponseDomainShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	GridResponseDomainPtrList get_grid_response_domains();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* STRUCTUREDMIXEDGRIDRESPONSEDOMAIN_HPP */
