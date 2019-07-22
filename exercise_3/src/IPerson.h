#pragma once

#include <string>

class IPerson {
	public:
		IPerson(const std::string &id);
		virtual std::string getName() const = 0;
		virtual ~IPerson() = default;
	protected:
		std::string _name;
};
