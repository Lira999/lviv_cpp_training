#include <stdexcept>
#include <sstream>
#include <string>
#include "Exam.h"

Exam::Exam(std::istringstream &record) {
    std::string buf;
	std::getline(record, buf, ',');
	_id = std::stoi(buf);
	std::getline(record, buf, ',');
	_course_id = std::stoi(buf);
	std::getline(record, buf, ',');
	_student_id = std::stoi(buf);
	std::getline(record, buf, ',');
	_result = std::stoi(buf);
}

int Exam::getId() const {
    return _id;
}

std::string Exam::getFormatted() const {
    std::ostringstream  ostringstream;
    ostringstream << _id << "," << _course_id << "," << _student_id << "," << _result;
    return ostringstream.str();
}
