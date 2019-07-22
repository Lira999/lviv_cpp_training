#include <sstream>
#include <string>
#include "Exam.h"

Exam::Exam(int &id, int &course_id, int &student_id, int &result):
	_course_id{course_id}, _student_id{student_id}, _result{result} {
		this -> _id = id;
	}

int Exam::getId() const {
    return _id;
}

std::string Exam::getFormatted() const {
    std::ostringstream  ostringstream;
    ostringstream << _id << "," << _course_id << "," << _student_id << "," << _result;
    return ostringstream.str();
}
