#include <sstream>
#include <string>
#include "Student.h"

Student::Student(const int &id, const std::string &name): IRecord(id), IPerson(name) {}

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

std::string Student::getPrettyPrinted() const {
    std::ostringstream  ostringstream;
    ostringstream << "ID: " << _id << ", Name: " << _name;
    return ostringstream.str();
}
