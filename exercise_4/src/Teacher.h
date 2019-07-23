#pragma once

#include <string>
#include "IPerson.h"
#include "IRecord.h"

class Teacher : public IPerson, public IRecord {
	public:
		Teacher(const int &id, const std::string &name);
		int getId() const override;
		std::string getName() const override;
		std::string getFormatted() const override;
		std::string getPrettyPrinted() const override;
};
