#pragma once

#include <string>
#include "IRecord.h"

class Course : public IRecord {
	public:
	    Course(const int &id, const std::string &name, const int &teacher_id);
		int getId() const override;
		std::string getFormatted() const override;
	private:
		std::string _name;
		int _teacher_id;
};
