#ifndef THENCONSTRUCTREFERENCE_HPP
#define	THENCONSTRUCTREFERENCE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "typeofobject.hpp"

class ThenConstructReference;

typedef std::shared_ptr<ThenConstructReference> ThenConstructReferenceShPtr;
typedef std::list<ThenConstructReferenceShPtr> ThenConstructReferencePtrList;


class ThenConstructReference : public Basic {
private:
   
   URNShPtr urn;
   TypeOfObjectShPtr type_of_object;
   
   
   BasicWkPtr parent;
public:
	ThenConstructReference();
	~ThenConstructReference() {}
	
	//Keep track of all objects 
	static std::list<ThenConstructReferenceShPtr> all;
	static std::string type;
	
	static ThenConstructReferenceShPtr create();
	static ThenConstructReferenceShPtr create(BasicWkPtr);
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	BasicWkPtr get_parent();
	void set_parent(BasicWkPtr);
	
	std::string get_type();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	
	TypeOfObjectShPtr get_type_of_object();
	void set_type_of_object(TypeOfObjectShPtr);
	
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* THENCONSTRUCTREFERENCE_HPP */
