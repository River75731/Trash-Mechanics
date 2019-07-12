#include "Windows.h"
#include "../Command/CommandList.h"
void Windows::test()
{
	onCreatePolyTriggered(); // assume a trigger
}

void Windows::onCreatePolyData(const Poly & poly)
{

//	createPolyCommand->set_parameters( // create command parameter from data, then set command parameter
	//	std::static_pointer_cast<Parameter, PolyParameter>(std::shared_ptr<PolyParameter>(new PolyParameter(poly))));

	createPolyCommand->pass(); //pass to ViewModel

}

void Windows::onCreatePolyTriggered()
{
	Poly poly(std::vector<Vec>{Vec(10, 10), Vec(100, 100), Vec(100, 10)}); //test
	onCreatePolyData(poly);
}
