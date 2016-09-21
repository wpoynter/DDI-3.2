#ifndef RESOURCEPACKAGE_HPP
#define	RESOURCEPACKAGE_HPP

#include "basic.hpp"

#include "urn.hpp"
#include "citation.hpp"
#include "purpose.hpp"
#include "datacollection.hpp"
#include "questionscheme.hpp"
#include "categoryscheme.hpp"
#include "codelistscheme.hpp"

class ResourcePackage;

typedef std::shared_ptr<ResourcePackage> ResourcePackageShPtr;
typedef std::list<ResourcePackageShPtr> ResourcePackagePtrList;


class ResourcePackage : public Basic {
private:
   
   URNShPtr urn;
   CitationPtrList citations;
   PurposePtrList purposes;
   DataCollectionPtrList data_collections;
   QuestionSchemePtrList question_schemes;
   CategorySchemePtrList category_schemes;
   CodeListSchemePtrList code_list_schemes;
   std::string version_date;
   
public:
	ResourcePackage();
	~ResourcePackage() {}
	
	//Keep track of all objects 
	static std::list<ResourcePackageShPtr> all;
	
	static ResourcePackageShPtr create();
	static void destroy(unsigned int _ID);
	virtual void destroy();
	
	//Getters and setters
	
	URNShPtr get_urn();
	void set_urn(URNShPtr);
	
	CitationPtrList get_citations();
	PurposePtrList get_purposes();
	DataCollectionPtrList get_data_collections();
	QuestionSchemePtrList get_question_schemes();
	CategorySchemePtrList get_category_schemes();
	CodeListSchemePtrList get_code_list_schemes();
	
	std::string get_version_date();
	void set_version_date(std::string);
	
	
	void read_element(ticpp::Element*);
};

#endif	/* RESOURCEPACKAGE_HPP */
