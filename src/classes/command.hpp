#ifndef COMMAND_HPP
#define	COMMAND_HPP

#include "basic.hpp"

#include "programlanguage.hpp"
#include "commandcontent.hpp"

class Command;

typedef std::shared_ptr<Command> CommandShPtr;
typedef std::list<CommandShPtr> CommandPtrList;


class Command : public Basic {
private:
   
   ProgramLanguagePtrList program_languages;
   CommandContentPtrList command_contents;
   
   
public:
	Command();
	~Command() {}
	
	//Keep track of all objects 
	static std::list<CommandShPtr> all;
	
	static CommandShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	ProgramLanguagePtrList get_program_languages();
	CommandContentPtrList get_command_contents();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* COMMAND_HPP */
