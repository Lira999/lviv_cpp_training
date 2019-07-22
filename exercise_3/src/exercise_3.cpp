#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>

#include "Course.h"
#include "Exam.h"
#include "Student.h"
#include "Teacher.h"

using namespace std;

void add_course_to_map(istringstream &iss_record, map<int, Course> &courses) {
	int id, teacher_id;
	string buf, name;
	getline(iss_record, buf, ',');
	id = stoi(buf);
	getline(iss_record, name, ',');
	getline(iss_record, buf, ',');
	teacher_id = stoi(buf);
	Course course(id, name, teacher_id);
	courses.insert(pair<int, Course>(course.getId(), course));
}

template <class T>
void add_person_to_map(istringstream &iss_record, map<int, T> &persons_map) {
	int id;
	string buf, name;
	getline(iss_record, buf, ',');
	id = stoi(buf);
	getline(iss_record, name, ',');
	T person(id, name);
	persons_map.insert(pair<int, T>(person.getId(), person));
}

void add_exam_to_map(istringstream &iss_record, map<int, Exam> &exams) {
	int id, course_id, student_id, result;
	string buf;
	getline(iss_record, buf, ',');
	id = stoi(buf);
	getline(iss_record, buf, ',');
	course_id = stoi(buf);
	getline(iss_record, buf, ',');
	student_id = stoi(buf);
	getline(iss_record, buf, ',');
	result = stoi(buf);
	Exam exam(id, course_id, student_id, result);
	exams.insert(pair<int, Exam>(exam.getId(), exam));
}

template <class T>
void write_to_file(const string &file_name, const map<int, T> &records_map){
	ofstream output_file(file_name);
	if(output_file) {
		for(const auto &record : records_map) {
			output_file << record.second.getFormatted() << endl;
		}
	} else {
		cerr << "Unable to create file." << endl;
	}
}

int main() {
	ifstream input_file("./src/records.txt");
	string line, marker;

	map<int, Course> courses;
	map<int, Exam> exams;
	map<int, Student> students;
	map<int, Teacher> teachers;

	if (input_file.is_open()) {
		while (getline(input_file, line)) {
			istringstream iss_record(line);
			getline(iss_record, marker, ',');

			if (marker == "C") {
				add_course_to_map(iss_record, courses);
			} else if (marker == "T") {
				add_person_to_map(iss_record, teachers);
			} else if (marker == "S") {
				add_person_to_map(iss_record, students);
			} else if (marker == "E") {
				add_exam_to_map(iss_record, exams);
			}
		}
	} else {
		cerr << "Unable to open file." << endl;
	}

	write_to_file("./Cources.txt", courses);
	write_to_file("./Exams.txt", exams);
	write_to_file("./Students.txt", students);
	write_to_file("./Teachers.txt", teachers);

	return 0;
}
