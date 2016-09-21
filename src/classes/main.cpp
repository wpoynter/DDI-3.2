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
		for (QuestionItemPtrList::iterator iter = QuestionItem::all.begin();
			iter != QuestionItem::all.end(); ++iter) {
			std::cout << (*iter)->get_question_texts().front()->get_literal_text()->get_text()->get_content() << std::endl;
		}
	}
	catch( ticpp::Exception& ex )
	{
        std::cerr << ex.what();
	}	
	
	return 0;
}