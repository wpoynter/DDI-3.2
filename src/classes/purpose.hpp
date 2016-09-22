#ifndef PURPOSE_HPP
#define	PURPOSE_HPP

#include "basic.hpp"

#include "content.hpp"

class Purpose;

typedef std::shared_ptr<Purpose> PurposeShPtr;
typedef std::list<PurposeShPtr> PurposePtrList;


class Purpose : public Basic {
private:
   
   ContentPtrList contents;
   
   
   BasicWkPtr parent;
public:
	Purpose();
	~Purpose() {}
	
	//Keep track of all objects 
	static std::list<PurposeShPtr> all;
	static std::string type;
	
	static PurposeShPtr create();
	static PurposeShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	ContentPtrList get_contents();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* PURPOSE_HPP */
