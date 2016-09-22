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
   
   
   BasicWkPtr parent;
public:
	Command();
	~Command() {}
	
	//Keep track of all objects 
	static std::list<CommandShPtr> all;
	static std::string type;
	
	static CommandShPtr create();
	static CommandShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	ProgramLanguagePtrList get_program_languages();
	CommandContentPtrList get_command_contents();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* COMMAND_HPP */
