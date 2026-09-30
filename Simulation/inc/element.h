#pragma once
#include "nucleus/neutron.h"
#include "nucleus/proton.h"

#include "electron/probability.h"

#include <elements/elements.h>

#include <memory>
#include <vector>

namespace Simulation
{
	class ElementSimulation
	{
	public:
		ElementSimulation(Chemistry::Element* element);
		~ElementSimulation() = default;

		void update(int n, int l, int m);

		Chemistry::Element* currentElement;
	private:
		std::vector<int> protons;
		std::vector<int> neutrons;
		std::unique_ptr<int> electronState;
	};
};