#pragma once

#include <string>
#include "IPerson.h"
#include "IRecord.h"

class Teacher : public IPerson, public IRecord {
	public:Teacher(std::istringstream &record);
		int getId() const override;
		std::string getName() const override;
		std::string getFormatted() const override;
};
