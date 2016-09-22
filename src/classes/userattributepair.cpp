#include "userattributepair.hpp"

std::list<UserAttributePairShPtr> UserAttributePair::all;
std::string UserAttributePair::type = "UserAttributePair";

UserAttributePair::UserAttributePair() :
Basic() {}

UserAttributePairShPtr UserAttributePair::create() {
	all.push_back(UserAttributePairShPtr(new UserAttributePair()));
	all.back()->set_parent(BasicWkPtr());
	return all.back();
}

UserAttributePairShPtr UserAttributePair::create(BasicWkPtr _parent) {
	auto ptr = UserAttributePair::create();
	ptr->set_parent(_parent);
	return ptr;
}

void UserAttributePair::destroy(unsigned int _ID) {
	all.remove_if(cleaner(_ID));
}

void UserAttributePair::destroy() {
	destroy(getID());
}

BasicWkPtr UserAttributePair::get_parent() {
	return parent;
}

void UserAttributePair::set_parent(BasicWkPtr _parent) {
	parent = _parent;
}

std::string UserAttributePair::get_type() {
	return type;
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
			attribute_keys.push_back(AttributeKey::create(shared_from_this()));
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
			attribute_values.push_back(AttributeValue::create(shared_from_this()));
			attribute_values.back()->read_element(child_elem);
			child_elem = child_elem->NextSiblingElement("r:AttributeValue");
		}
	}
	catch( ticpp::Exception& ex )
	{
	}
	
	
}
