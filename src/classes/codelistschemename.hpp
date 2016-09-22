#ifndef CODELISTSCHEMENAME_HPP
#define	CODELISTSCHEMENAME_HPP

#include "basic.hpp"

#include "string.hpp"

class CodeListSchemeName;

typedef std::shared_ptr<CodeListSchemeName> CodeListSchemeNameShPtr;
typedef std::list<CodeListSchemeNameShPtr> CodeListSchemeNamePtrList;


class CodeListSchemeName : public Basic {
private:
   
   StringShPtr string;
   
   
   BasicWkPtr parent;
public:
	CodeListSchemeName();
	~CodeListSchemeName() {}
	
	//Keep track of all objects 
	static std::list<CodeListSchemeNameShPtr> all;
	static std::string type;
	
	static CodeListSchemeNameShPtr create();
	static CodeListSchemeNameShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	StringShPtr get_string();
	void set_string(StringShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CODELISTSCHEMENAME_HPP */
