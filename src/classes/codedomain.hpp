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
   
   
   BasicWkPtr parent;
public:
	CodeDomain();
	~CodeDomain() {}
	
	//Keep track of all objects 
	static std::list<CodeDomainShPtr> all;
	static std::string type;
	
	static CodeDomainShPtr create();
	static CodeDomainShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	CodeListReferencePtrList get_code_list_references();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CODEDOMAIN_HPP */
