#pragma once

#include <string>

class IPerson {
	public:
		virtual std::string getName() const = 0;
		virtual ~IPerson() = default;
	protected:
		std::string _name;
};
