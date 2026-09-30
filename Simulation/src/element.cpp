#include "element.h"

namespace Simulation
{
	ElementSimulation::ElementSimulation(Chemistry::Element* element)
	{
		currentElement = element;
		electronState = std::make_unique<int>(1);

		protons.reserve(currentElement->AtNo);
		neutrons.reserve(currentElement->Neutrons);
	}

	void ElementSimulation::update(int n, int l, int m)
	{
	}
}