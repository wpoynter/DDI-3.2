#ifndef RESPONSEDOMAININMIXED_HPP
#define	RESPONSEDOMAININMIXED_HPP

#include "basic.hpp"

#include "codedomain.hpp"
#include "textdomain.hpp"
#include "numericdomain.hpp"

class ResponseDomainInMixed;

typedef std::shared_ptr<ResponseDomainInMixed> ResponseDomainInMixedShPtr;
typedef std::list<ResponseDomainInMixedShPtr> ResponseDomainInMixedPtrList;


class ResponseDomainInMixed : public Basic {
private:
   
   CodeDomainPtrList code_domains;
   TextDomainPtrList text_domains;
   NumericDomainPtrList numeric_domains;
   
   
public:
	ResponseDomainInMixed();
	~ResponseDomainInMixed() {}
	
	//Keep track of all objects 
	static std::list<ResponseDomainInMixedShPtr> all;
	
	static ResponseDomainInMixedShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	CodeDomainPtrList get_code_domains();
	TextDomainPtrList get_text_domains();
	NumericDomainPtrList get_numeric_domains();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* RESPONSEDOMAININMIXED_HPP */
