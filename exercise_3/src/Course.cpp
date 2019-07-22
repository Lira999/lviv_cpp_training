#include <sstream>
#include <string>
#include "Course.h"

Course::Course(int &id, std::string &name, int &teacher_id): _name{name}, _teacher_id{teacher_id} {
	this -> _id = id;
}

int Course::getId() const {
    return _id;
}

std::string Course::getFormatted() const {
    std::ostringstream  ostringstream;

    ostringstream << _id << "," << _name << "," << _teacher_id;
    return ostringstream.str();
}
