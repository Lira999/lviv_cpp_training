#pragma once

#include <string>
#include "IRecord.h"

class Course : public IRecord {
	public:
	    Course(int &id, std::string &name, int &teacher_id);
		int getId() const override;
		std::string getFormatted() const override;
	private:
		std::string _name;
		int _teacher_id;
};
