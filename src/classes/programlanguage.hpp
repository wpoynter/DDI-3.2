#ifndef PROGRAMLANGUAGE_HPP
#define	PROGRAMLANGUAGE_HPP

#include "basic.hpp"


class ProgramLanguage;

typedef std::shared_ptr<ProgramLanguage> ProgramLanguageShPtr;
typedef std::list<ProgramLanguageShPtr> ProgramLanguagePtrList;


class ProgramLanguage : public Basic {
private:
   
   
   std::string content;
public:
	ProgramLanguage();
	~ProgramLanguage() {}
	
	//Keep track of all objects 
	static std::list<ProgramLanguageShPtr> all;
	
	static ProgramLanguageShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* PROGRAMLANGUAGE_HPP */
