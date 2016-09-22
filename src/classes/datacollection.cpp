#include "datacollection.hpp"

std::list<DataCollectionShPtr> DataCollection::all;
std::string DataCollection::type = "DataCollection";

DataCollection::DataCollection() :
Basic() {}

DataCollectionShPtr DataCollection::create() {
	all.push_back(DataCollectionShPtr(new DataCollection()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

DataCollectionShPtr DataCollection::create(BasicWkPtr _parent) {
	auto ptr = DataCollection::create();
	ptr->set_parent(_parent);
	return ptr;
}

void DataCollection::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void DataCollection::destroy() {
	destroy(getID());
}

BasicWkPtr DataCollection::get_parent() {
	return parent;
}

void DataCollection::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string DataCollection::get_type() {
	return type;
}

URNShPtr DataCollection::get_urn() {
	return urn;
}
void DataCollection::set_urn(URNShPtr _urn) {
	urn = _urn;
}
DataCollectionModuleNamePtrList DataCollection::get_data_collection_module_names() {
	return data_collection_module_names;
}
ControlConstructSchemePtrList DataCollection::get_control_construct_schemes() {
	return control_construct_schemes;
}
InterviewerInstructionSchemePtrList DataCollection::get_interviewer_instruction_schemes() {
	return interviewer_instruction_schemes;
}
InstrumentSchemePtrList DataCollection::get_instrument_schemes() {
	return instrument_schemes;
}
std::string DataCollection::get_version_date() {
	return version_date;
}
void DataCollection::set_version_date(std::string _version_date) {
	version_date = _version_date;
}


void DataCollection::read_element(ticpp::Element* elem) {
	elem->GetAttribute( "versionDate", &version_date, false);
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:URN");
		urn = URN::create(shared_from_this());
		urn->read_element(child_elem);
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:DataCollectionModuleName");
		while (true) {
			data_collection_module_names.push_back(DataCollectionModuleName::create(shared_from_this()));
			data_collection_module_names.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:DataCollectionModuleName");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:ControlConstructScheme");
		while (true) {
			control_construct_schemes.push_back(ControlConstructScheme::create(shared_from_this()));
			control_construct_schemes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:ControlConstructScheme");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InterviewerInstructionScheme");
		while (true) {
			interviewer_instruction_schemes.push_back(InterviewerInstructionScheme::create(shared_from_this()));
			interviewer_instruction_schemes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:InterviewerInstructionScheme");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("d:InstrumentScheme");
		while (true) {
			instrument_schemes.push_back(InstrumentScheme::create(shared_from_this()));
			instrument_schemes.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("d:InstrumentScheme");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
