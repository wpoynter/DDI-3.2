#include "userattributepair.hpp"

std::list<UserAttributePairShPtr> UserAttributePair::all;

UserAttributePair::UserAttributePair() :
Basic() {}

UserAttributePairShPtr UserAttributePair::create() {
	all.push_back(UserAttributePairShPtr(new UserAttributePair()));
	return all.back();
}

void UserAttributePair::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void UserAttributePair::destroy() {
	destroy(getID());
}

AttributeKeyPtrList UserAttributePair::get_attribute_keys() {
	return attribute_keys;
}
AttributeValuePtrList UserAttributePair::get_attribute_values() {
	return attribute_values;
}




void UserAttributePair::read_element(ticpp::Element* elem) {
	
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:AttributeKey");
		while (true) {
			attribute_keys.push_back(AttributeKey::create());
			attribute_keys.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:AttributeKey");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
	try {
		ticpp::Element* child_elem = elem->FirstChildElement("r:AttributeValue");
		while (true) {
			attribute_values.push_back(AttributeValue::create());
			attribute_values.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:AttributeValue");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
