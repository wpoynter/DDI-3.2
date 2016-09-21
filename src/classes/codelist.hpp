#ifndef CODELIST_HPP
#define	CODELIST_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "label.hpp"
#include "code.hpp"

class CodeList;

typedef std::shared_ptr<CodeList> CodeListShPtr;
typedef std::list<CodeListShPtr> CodeListPtrList;


class CodeList : public Basic {
private:
   
   URNShPtr urn;
   LabelPtrList labels;
   CodePtrList codes;
   
   
public:
	CodeList();
	~CodeList() {}
	
	//Keep track of all objects 
	static std::list<CodeListShPtr> all;
	
	static CodeListShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	LabelPtrList get_labels();
	CodePtrList get_codes();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CODELIST_HPP */
