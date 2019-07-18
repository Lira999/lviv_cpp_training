#pragma once

#include <string>
#include "IRecord.h"

class Course : public IRecord {
	public:
	    Course(std::istringstream &record);
		int getId() const override;
		std::string getFormatted() const override;
	private:
		int _id;
		std::string _name;
		int _teacher_id;
};
