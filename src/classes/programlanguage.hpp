#ifndef PROGRAMLANGUAGE_HPP
#define	PROGRAMLANGUAGE_HPP

#include "basic.hpp"


class ProgramLanguage;

typedef std::shared_ptr<ProgramLanguage> ProgramLanguageShPtr;
typedef std::list<ProgramLanguageShPtr> ProgramLanguagePtrList;


class ProgramLanguage : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	ProgramLanguage();
	~ProgramLanguage() {}
	
	//Keep track of all objects 
	static std::list<ProgramLanguageShPtr> all;
	static std::string type;
	
	static ProgramLanguageShPtr create();
	static ProgramLanguageShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* PROGRAMLANGUAGE_HPP */
