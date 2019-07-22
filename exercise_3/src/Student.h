#pragma once

#include <string>
#include "IPerson.h"
#include "IRecord.h"

class Student : public IPerson, public IRecord {
	public:
		Student(int &id, std::string &name);
		int getId() const override;
		std::string getName() const override;
		std::string getFormatted() const override;

};
