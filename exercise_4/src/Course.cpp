#include <sstream>
#include <string>
#include "Course.h"

Course::Course(const int &id, const std::string &name, const int &teacher_id):
	IRecord(id), _name{name}, _teacher_id{teacher_id} {}

int Course::getId() const {
    return _id;
}

std::string Course::getFormatted() const {
    std::ostringstream  ostringstream;

    ostringstream << _id << "," << _name << "," << _teacher_id;
    return ostringstream.str();
}

std::string Course::getPrettyPrinted() const {
    std::ostringstream  ostringstream;

    ostringstream << "ID: " << _id << ", Name: " << _name << ", TeacherID: " << _teacher_id;
    return ostringstream.str();
}
