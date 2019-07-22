#include <sstream>
#include <string>
#include "Teacher.h"

Teacher::Teacher(int &id, std::string &name) {
    this -> _id = id;
	this -> _name = name;
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
