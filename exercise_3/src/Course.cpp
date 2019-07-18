#include <stdexcept>
#include <sstream>
#include <string>
#include "Course.h"

Course::Course(std::istringstream &record) {
    std::string buf;
	std::getline(record, buf, ',');
	_id = std::stoi(buf);
	std::getline(record, _name, ',');
	std::getline(record, buf, ',');
	_teacher_id = std::stoi(buf);
}

int Course::getId() const {
    return _id;
}

std::string Course::getFormatted() const {
    std::ostringstream  ostringstream;
    ostringstream << _id << "," << _name << "," << _teacher_id;
    return ostringstream.str();
}
