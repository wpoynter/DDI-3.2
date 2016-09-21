#ifndef NUMERICTYPECODE_HPP
#define	NUMERICTYPECODE_HPP

#include "basic.hpp"


class NumericTypeCode;

typedef std::shared_ptr<NumericTypeCode> NumericTypeCodeShPtr;
typedef std::list<NumericTypeCodeShPtr> NumericTypeCodePtrList;


class NumericTypeCode : public Basic {
private:
   
   
   std::string content;
public:
	NumericTypeCode();
	~NumericTypeCode() {}
	
	//Keep track of all objects 
	static std::list<NumericTypeCodeShPtr> all;
	
	static NumericTypeCodeShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	
	
	std::string get_content();
	void set_content(std::string);
	void read_element(ticpp::Element*);
};

#endif	/* NUMERICTYPECODE_HPP */
