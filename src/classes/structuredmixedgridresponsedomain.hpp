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
   
   
public:
	StructuredMixedGridResponseDomain();
	~StructuredMixedGridResponseDomain() {}
	
	//Keep track of all objects 
	static std::list<StructuredMixedGridResponseDomainShPtr> all;
	
	static StructuredMixedGridResponseDomainShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	GridResponseDomainPtrList get_grid_response_domains();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* STRUCTUREDMIXEDGRIDRESPONSEDOMAIN_HPP */
