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
   
   
   BasicWkPtr parent;
public:
	StructuredMixedResponseDomain();
	~StructuredMixedResponseDomain() {}
	
	//Keep track of all objects 
	static std::list<StructuredMixedResponseDomainShPtr> all;
	static std::string type;
	
	static StructuredMixedResponseDomainShPtr create();
	static StructuredMixedResponseDomainShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	ResponseDomainInMixedPtrList get_response_domain_in_mixeds();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* STRUCTUREDMIXEDRESPONSEDOMAIN_HPP */
