#include <stdexcept>
#include <sstream>
#include <string>
#include "Student.h"

Student::Student(std::istringstream &record) {
    std::string buf;
	std::getline(record, buf, ',');
	_id = std::stoi(buf);
	std::getline(record, _name, ',');
}

int Student::getId() const {
    return _id;
}

std::string Student::getName() const {
    return _name;
}

std::string Student::getFormatted() const {
    std::ostringstream  ostringstream;
    ostringstream << _id << "," << _name;
    return ostringstream.str();
}
