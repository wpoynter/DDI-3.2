#ifndef CODELISTSCHEME_HPP
#define	CODELISTSCHEME_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "codelistschemename.hpp"
#include "codelist.hpp"

class CodeListScheme;

typedef std::shared_ptr<CodeListScheme> CodeListSchemeShPtr;
typedef std::list<CodeListSchemeShPtr> CodeListSchemePtrList;


class CodeListScheme : public Basic {
private:
   
   URNShPtr urn;
   CodeListSchemeNamePtrList code_list_scheme_names;
   CodeListPtrList code_lists;
   std::string version_date;
   
   BasicWkPtr parent;
public:
	CodeListScheme();
	~CodeListScheme() {}
	
	//Keep track of all objects 
	static std::list<CodeListSchemeShPtr> all;
	static std::string type;
	
	static CodeListSchemeShPtr create();
	static CodeListSchemeShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	CodeListSchemeNamePtrList get_code_list_scheme_names();
	CodeListPtrList get_code_lists();
	
	std::string get_version_date();
	void set_version_date(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CODELISTSCHEME_HPP */
