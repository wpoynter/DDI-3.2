#ifndef BASIC_HPP
#define	BASIC_HPP

#include <list>
#include <memory>
#include <string>

#include "../../lib/ticpp/ticpp.h"

class Basic;
typedef std::shared_ptr<Basic> BasicShPtr;
typedef std::list<BasicShPtr> BasicPtrList;

class Basic : public std::enable_shared_from_this<Basic> {
public:
	Basic();
	virtual ~Basic();
	
	static BasicShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	unsigned int getID() const;
	
	static BasicPtrList all;
	
	virtual void read_element(ticpp::Element*);
	
private:
	unsigned int ID;
	static unsigned int counter;
};

class cleaner {
public:
	cleaner(unsigned int _ID) {
		ID = _ID;
	}
	bool operator()(BasicShPtr obj) {
		return obj->getID() == ID;
	}
	
private:
	unsigned int ID;
};


#endif	/* BASIC_HPP */