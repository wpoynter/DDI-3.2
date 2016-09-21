#include "datacollectionmodulename.hpp"

std::list<DataCollectionModuleNameShPtr> DataCollectionModuleName::all;

DataCollectionModuleName::DataCollectionModuleName() :
Basic() {}

DataCollectionModuleNameShPtr DataCollectionModuleName::create() {
	all.push_back(DataCollectionModuleNameShPtr(new DataCollectionModuleName()));
	return all.back();
}

void DataCollectionModuleName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DataCollectionModuleName::destroy() {
	destroy(getID());
}

StringShPtr DataCollectionModuleName::get_string() {
	return string;
}
void DataCollectionModuleName::set_string(StringShPtr _string) {
	string = _string;
}




void DataCollectionModuleName::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:String");
		string = String::create();
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
