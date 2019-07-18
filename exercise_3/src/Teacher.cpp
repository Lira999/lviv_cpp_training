#include <stdexcept>
#include <sstream>
#include <string>
#include "Teacher.h"

Teacher::Teacher(std::istringstream &record) {
    std::string buf;
	std::getline(record, buf, ',');
	_id = std::stoi(buf);
	std::getline(record, _name, ',');
}

int Teacher::getId() const {
    return _id;
}

std::string Teacher::getName() const {
    return _name;
}

std::string Teacher::getFormatted() const {
    std::ostringstream  ostringstream;
    ostringstream << _id << "," << _name;
    return ostringstream.str();
}
