#include <sstream>
#include <string>
#include "Exam.h"

Exam::Exam(const int &id, const int &course_id, const int &student_id, const int &result):
	IRecord(id), _course_id{course_id}, _student_id{student_id}, _result{result} {}

int Exam::getId() const {
    return _id;
}

std::string Exam::getFormatted() const {
    std::ostringstream  ostringstream;
    ostringstream << _id << "," << _course_id << "," << _student_id << "," << _result;
    return ostringstream.str();
}

std::string Exam::getPrettyPrinted() const {
    std::ostringstream  ostringstream;
    ostringstream << "ID: " << _id << ", CourseID: " << _course_id << ", StudentID: " << _student_id << ", Result: " << _result;
    return ostringstream.str();
}
