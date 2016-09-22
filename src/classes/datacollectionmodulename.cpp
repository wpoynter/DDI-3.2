#include "datacollectionmodulename.hpp"

std::list<DataCollectionModuleNameShPtr> DataCollectionModuleName::all;
std::string DataCollectionModuleName::type = "DataCollectionModuleName";

DataCollectionModuleName::DataCollectionModuleName() :
Basic() {}

DataCollectionModuleNameShPtr DataCollectionModuleName::create() {
	all.push_back(DataCollectionModuleNameShPtr(new DataCollectionModuleName()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

DataCollectionModuleNameShPtr DataCollectionModuleName::create(BasicWkPtr _parent) {
	auto ptr = DataCollectionModuleName::create();
	ptr->set_parent(_parent);
	return ptr;
}

void DataCollectionModuleName::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DataCollectionModuleName::destroy() {
	destroy(getID());
}

BasicWkPtr DataCollectionModuleName::get_parent() {
	return parent;
}

void DataCollectionModuleName::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string DataCollectionModuleName::get_type() {
	return type;
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
		string = String::create(shared_from_this());
		string->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
