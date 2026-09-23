#pragma once

#include <array>
#include <string>
#include <cmath>

namespace Chemistry
{
	class Element
	{
	public:
        Element(std::string symbol, int atNo, float mass);
        Element(const Element& other);

		std::string Symbol;

		int AtNo;
		int Neutrons;
		int Electrons;
		float Mass;
	};

	extern std::array<Element, 118> Elements;
};