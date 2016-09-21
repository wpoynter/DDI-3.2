#ifndef CODE_HPP
#define	CODE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "categoryreference.hpp"
#include "value.hpp"

class Code;

typedef std::shared_ptr<Code> CodeShPtr;
typedef std::list<CodeShPtr> CodePtrList;


class Code : public Basic {
private:
   
   URNShPtr urn;
   CategoryReferencePtrList category_references;
   ValuePtrList values;
   
   
public:
	Code();
	~Code() {}
	
	//Keep track of all objects 
	static std::list<CodeShPtr> all;
	
	static CodeShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	CategoryReferencePtrList get_category_references();
	ValuePtrList get_values();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* CODE_HPP */
