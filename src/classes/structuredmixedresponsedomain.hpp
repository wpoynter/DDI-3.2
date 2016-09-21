#ifndef STRUCTUREDMIXEDRESPONSEDOMAIN_HPP
#define	STRUCTUREDMIXEDRESPONSEDOMAIN_HPP

#include "basic.hpp"

#include "responsedomaininmixed.hpp"

class StructuredMixedResponseDomain;

typedef std::shared_ptr<StructuredMixedResponseDomain> StructuredMixedResponseDomainShPtr;
typedef std::list<StructuredMixedResponseDomainShPtr> StructuredMixedResponseDomainPtrList;


class StructuredMixedResponseDomain : public Basic {
private:
   
   ResponseDomainInMixedPtrList response_domain_in_mixeds;
   
   
public:
	StructuredMixedResponseDomain();
	~StructuredMixedResponseDomain() {}
	
	//Keep track of all objects 
	static std::list<StructuredMixedResponseDomainShPtr> all;
	
	static StructuredMixedResponseDomainShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	ResponseDomainInMixedPtrList get_response_domain_in_mixeds();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* STRUCTUREDMIXEDRESPONSEDOMAIN_HPP */
