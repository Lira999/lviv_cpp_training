#include <sstream>
#include <string>
#include "Teacher.h"

Teacher::Teacher(const int &id, const std::string &name): IRecord(id), IPerson(name) {}

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
