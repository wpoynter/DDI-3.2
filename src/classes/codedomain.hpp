#ifndef CODEDOMAIN_HPP
#define	CODEDOMAIN_HPP

#include "basic.hpp"

#include "codelistreference.hpp"

class CodeDomain;

typedef std::shared_ptr<CodeDomain> CodeDomainShPtr;
typedef std::list<CodeDomainShPtr> CodeDomainPtrList;


class CodeDomain : public Basic {
private:
   
   CodeListReferencePtrList code_list_references;
   
   
public:
	CodeDomain();
	~CodeDomain() {}
	
	//Keep track of all objects 
	static std::list<CodeDomainShPtr> all;
	
	static CodeDomainShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	CodeListReferencePtrList get_code_list_references();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CODEDOMAIN_HPP */
