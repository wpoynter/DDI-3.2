#ifndef GRIDRESPONSEDOMAIN_HPP
#define	GRIDRESPONSEDOMAIN_HPP

#include "basic.hpp"

#include "textdomain.hpp"
#include "gridattachment.hpp"
#include "numericdomain.hpp"
#include "codedomain.hpp"

class GridResponseDomain;

typedef std::shared_ptr<GridResponseDomain> GridResponseDomainShPtr;
typedef std::list<GridResponseDomainShPtr> GridResponseDomainPtrList;


class GridResponseDomain : public Basic {
private:
   
   TextDomainPtrList text_domains;
   GridAttachmentPtrList grid_attachments;
   NumericDomainPtrList numeric_domains;
   CodeDomainPtrList code_domains;
   
   
   BasicWkPtr parent;
public:
	GridResponseDomain();
	~GridResponseDomain() {}
	
	//Keep track of all objects 
	static std::list<GridResponseDomainShPtr> all;
	static std::string type;
	
	static GridResponseDomainShPtr create();
	static GridResponseDomainShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	TextDomainPtrList get_text_domains();
	GridAttachmentPtrList get_grid_attachments();
	NumericDomainPtrList get_numeric_domains();
	CodeDomainPtrList get_code_domains();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* GRIDRESPONSEDOMAIN_HPP */
