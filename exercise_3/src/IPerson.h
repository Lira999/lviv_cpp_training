#pragma once

#include <string>

class IPerson {
	public:
		std::string _name;

		virtual std::string getName() const = 0;
		virtual ~IPerson() = default;
};
