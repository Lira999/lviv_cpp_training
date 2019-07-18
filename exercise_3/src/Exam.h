#pragma once

#include <string>
#include "IRecord.h"

class Exam : public IRecord {
	public:
		Exam(std::istringstream &record);
		int getId() const override;
		std::string getFormatted() const override;
	private:
		int _course_id;
		int _student_id;
		int _result;
};
