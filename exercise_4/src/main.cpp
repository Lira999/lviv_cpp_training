#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <vector>
#include <memory>

#include "IRecord.h"
#include "Course.h"
#include "Exam.h"
#include "Student.h"
#include "Teacher.h"
#include "CommandHandler.h"

using namespace std;

void add_student_to_map(istringstream &iss_record, map<int, shared_ptr<IRecord> > &container) {
	int id;
	string buf, name;
	getline(iss_record, buf, ',');
	id = stoi(buf);
	getline(iss_record, name, ',');
	shared_ptr<IRecord> student = make_shared<Student>(id, name);
	container.insert(pair<int, shared_ptr<IRecord> >(student -> getId(), student));
}

void add_teacher_to_map(istringstream &iss_record, map<int, shared_ptr<IRecord> > &container) {
	int id;
	string buf, name;
	getline(iss_record, buf, ',');
	id = stoi(buf);
	getline(iss_record, name, ',');
	shared_ptr<IRecord> teacher = make_shared<Teacher>(id, name);
	container.insert(pair<int, shared_ptr<IRecord> >(teacher -> getId(), teacher));
}

void add_course_to_map(istringstream &iss_record, map<int, shared_ptr<IRecord> > &container) {
	int id, teacher_id;
	string buf, name;
	getline(iss_record, buf, ',');
	id = stoi(buf);
	getline(iss_record, name, ',');
	getline(iss_record, buf, ',');
	teacher_id = stoi(buf);
	shared_ptr<IRecord> course = make_shared<Course>(id, name, teacher_id);
	container.insert(pair<int, shared_ptr<IRecord> >(course -> getId(), course));
}

void add_exam_to_map(istringstream &iss_record, map<int, shared_ptr<IRecord> > &container) {
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
	shared_ptr<IRecord> exam = make_shared<Exam>(id, course_id, student_id, result);
	container.insert(pair<int, shared_ptr<IRecord> >(exam -> getId(), exam));
}

void write_to_file(const string &file_name, const map<int, shared_ptr<IRecord> > &records_map){
	ofstream output_file(file_name);
	if(output_file) {
		for(const auto &record: records_map) {
			output_file << record.second -> getFormatted() << endl;
		}
	} else {
		cerr << "Unable to create file." << endl;
	}
}

int main(int args, char **argv) {
	if (args > 1) {
		ifstream input_file("./src/records.txt");
		string line, marker, command_type, table_name = "";

		map<int, shared_ptr<IRecord> > teachers;
		map<int, shared_ptr<IRecord> > students;
		map<int, shared_ptr<IRecord> > courses;
		map<int, shared_ptr<IRecord> > exams;

		if (input_file.is_open()) {
			while (getline(input_file, line)) {
				istringstream iss_record(line);
				getline(iss_record, marker, ',');

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
			cerr << "Unable to open file." << endl;
		}

		map<string, map<int, shared_ptr<IRecord> > > container;
		container.insert(pair<string, map<int, shared_ptr<IRecord> > >("TEACHERS", teachers));
		container.insert(pair<string, map<int, shared_ptr<IRecord> > >("STUDENTS", students));
		container.insert(pair<string, map<int, shared_ptr<IRecord> > >("COURSES", courses));
		container.insert(pair<string, map<int, shared_ptr<IRecord> > >("EXAMS", exams));

		command_type = argv[1];
		if (args > 2) {
			table_name = argv[2];
		}
		CommandHandler command(container, command_type, table_name);
		command.execute();

		write_to_file("./Cources.txt", courses);
		write_to_file("./Exams.txt", exams);
		write_to_file("./Students.txt", students);
		write_to_file("./Teachers.txt", teachers);
	}

	return 0;
}
