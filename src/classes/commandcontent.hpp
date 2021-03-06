#ifndef COMMANDCONTENT_HPP
#define	COMMANDCONTENT_HPP

#include "basic.hpp"


class CommandContent;

typedef std::shared_ptr<CommandContent> CommandContentShPtr;
typedef std::list<CommandContentShPtr> CommandContentPtrList;


class CommandContent : public Basic {
private:
   
   
   std::string content;
   BasicWkPtr parent;
public:
	CommandContent();
	~CommandContent() {}
	
	//Keep track of all objects 
	static std::list<CommandContentShPtr> all;
	static std::string type;
	
	static CommandContentShPtr create();
	static CommandContentShPtr create(BasicWkPtr);
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

#endif	/* COMMANDCONTENT_HPP */
