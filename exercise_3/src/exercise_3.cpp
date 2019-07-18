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

template <class T>
void add_record_to_map(istringstream &iss_record, map<int, T> &records_map) {
	T class_object(iss_record);
	records_map.insert(pair<int, T>(class_object.getId(), class_object));
}

template <class T>
void write_to_file(const string &file_name, map<int, T> &records_map){
	ofstream output_file(file_name);
	if(output_file) {
		for(auto &record : records_map) {
			output_file << record.second.getFormatted() << endl;
		}
		output_file.close();
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
				add_record_to_map(iss_record, courses);
			} else if (marker == "E") {
				add_record_to_map(iss_record, exams);
			} else if (marker == "S") {
				add_record_to_map(iss_record, students);
			} else if (marker == "T") {
				add_record_to_map(iss_record, teachers);
			}

		}
		input_file.close();
	} else {
		cerr << "Unable to open file." << endl;
	}

	write_to_file("./Cources.txt", courses);
	write_to_file("./Exams.txt", exams);
	write_to_file("./Students.txt", students);
	write_to_file("./Teachers.txt", teachers);

	return 0;
}
