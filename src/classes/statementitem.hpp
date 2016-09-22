#ifndef STATEMENTITEM_HPP
#define	STATEMENTITEM_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "constructname.hpp"
#include "displaytext.hpp"

class StatementItem;

typedef std::shared_ptr<StatementItem> StatementItemShPtr;
typedef std::list<StatementItemShPtr> StatementItemPtrList;


class StatementItem : public Basic {
private:
   
   URNShPtr urn;
   ConstructNamePtrList construct_names;
   DisplayTextPtrList display_texts;
   
   
   BasicWkPtr parent;
public:
	StatementItem();
	~StatementItem() {}
	
	//Keep track of all objects 
	static std::list<StatementItemShPtr> all;
	static std::string type;
	
	static StatementItemShPtr create();
	static StatementItemShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	ConstructNamePtrList get_construct_names();
	DisplayTextPtrList get_display_texts();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* STATEMENTITEM_HPP */
