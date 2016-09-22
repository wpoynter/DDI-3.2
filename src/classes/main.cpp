#include <iostream>

#include "ddiinstance.hpp"
#include "urn.hpp"

int main()
{
	try {
		ticpp::Document doc("ddi.xml");
		doc.LoadFile();
		
		ticpp::Element* elem = doc.FirstChildElement();

		DDIInstanceShPtr instance = DDIInstance::create();
		instance->read_element(elem);
		//instance->set_urn(URN::create());
		//instance->get_urn()->set_content(elem->FirstChildElement()->GetText());
	
		//std::cout << instance->get_urn()->get_content() << std::endl;
		for (URNPtrList::iterator iter = URN::all.begin();
			iter != URN::all.end(); ++iter) {
			if ((*iter)->get_parent().use_count() > 0) {
				BasicShPtr parent = (*iter)->get_parent().lock();
				std::cout << parent->get_type() << std::endl;
			}
		}
	}
	catch( ticpp::Exception& ex )
	{
        std::cerr << ex.what();
	}	
	
	return 0;
}