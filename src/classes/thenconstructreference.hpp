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
   TypeOfObjectPtrList type_of_objects;
   
   
public:
	ThenConstructReference();
	~ThenConstructReference() {}
	
	//Keep track of all objects 
	static std::list<ThenConstructReferenceShPtr> all;
	
	static ThenConstructReferenceShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	TypeOfObjectPtrList get_type_of_objects();
	
	
	
	
	
	void read_element(ticpp::Element*);
};

#endif	/* THENCONSTRUCTREFERENCE_HPP */
