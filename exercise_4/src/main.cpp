#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <memory>

#include "IRecord.h"
#include "Course.h"
#include "Exam.h"
#include "Student.h"
#include "Teacher.h"
#include "Show.h"

void add_student_to_map(std::istringstream &iss_record, std::vector<std::pair<int, std::unique_ptr<IRecord> > > &container) {
	int id;
	std::string buf, name;
	std::getline(iss_record, buf, ',');
	id = std::stoi(buf);
	std::getline(iss_record, name, ',');
	std::unique_ptr<IRecord> student = std::make_unique<Student>(id, name);
	container.emplace_back(student->getId(), std::move(student));
}

void add_teacher_to_map(std::istringstream &iss_record, std::vector<std::pair<int, std::unique_ptr<IRecord> > > &container) {
	int id;
	std::string buf, name;
	std::getline(iss_record, buf, ',');
	id = std::stoi(buf);
	std::getline(iss_record, name, ',');
	std::unique_ptr<IRecord> teacher = std::make_unique<Teacher>(id, name);
	container.emplace_back(teacher -> getId(), std::move(teacher));
}

void add_course_to_map(std::istringstream &iss_record, std::vector<std::pair<int, std::unique_ptr<IRecord> > > &container) {
	int id, teacher_id;
	std::string buf, name;
	std::getline(iss_record, buf, ',');
	id = std::stoi(buf);
	std::getline(iss_record, name, ',');
	std::getline(iss_record, buf, ',');
	teacher_id = stoi(buf);
	std::unique_ptr<IRecord> course = std::make_unique<Course>(id, name, teacher_id);
	container.emplace_back(course -> getId(), std::move(course));
}

void add_exam_to_map(std::istringstream &iss_record, std::vector<std::pair<int, std::unique_ptr<IRecord> > > &container) {
	int id, course_id, student_id, result;
	std::string buf;
	std::getline(iss_record, buf, ',');
	id = stoi(buf);
	std::getline(iss_record, buf, ',');
	course_id = std::stoi(buf);
	std::getline(iss_record, buf, ',');
	student_id = std::stoi(buf);
	std::getline(iss_record, buf, ',');
	result = std::stoi(buf);
	std::unique_ptr<IRecord> exam = std::make_unique<Exam>(id, course_id, student_id, result);
	container.emplace_back(exam -> getId(), std::move(exam));
}

int main(int args, char **argv) {
	if (args > 1) {
		std::ifstream input_file("./src/records.txt");
		std::string line, marker, command_type, table_name = "";

		std::vector<std::pair<int, std::unique_ptr<IRecord> > > teachers;
		std::vector<std::pair<int, std::unique_ptr<IRecord> > > students;
		std::vector<std::pair<int, std::unique_ptr<IRecord> > > courses;
		std::vector<std::pair<int, std::unique_ptr<IRecord> > > exams;

		if (input_file.is_open()) {
			while (std::getline(input_file, line)) {
				std::istringstream iss_record(line);
				std::getline(iss_record, marker, ',');

				if (marker == "T") {
					add_teacher_to_map(iss_record, teachers);
				} else if (marker == "S") {
					add_student_to_map(iss_record, students);
				} else if (marker == "C") {
					add_course_to_map(iss_record, courses);
				} else if (marker == "E") {
					add_exam_to_map(iss_record, exams);
				}
			}
		} else {
			std::cerr << "Unable to open file." << std::endl;
			return 1;
		}

		std::vector<std::pair<std::string, std::vector<std::pair<int, std::unique_ptr<IRecord> > > > > container;
		sort(teachers.begin(), teachers.end());
		container.emplace_back("TEACHERS", std::move(teachers));
		sort(students.begin(), students.end());
		container.emplace_back("STUDENTS", std::move(students));
		sort(courses.begin(), courses.end());
		container.emplace_back("COURSES", std::move(courses));
		sort(exams.begin(), exams.end());
		container.emplace_back("EXAMS", std::move(exams));

		command_type = argv[1];
		if (args > 2) {
			table_name = argv[2];
		}
		Show command(container, command_type, table_name);
		command.execute();
	}

	return 0;
}
