#include <sstream>
#include <string>
#include "Student.h"

Student::Student(int &id, std::string &name) {
    this -> _id = id;
	this -> _name = name;
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
