#include "roster.h"
#include "student.h"
#include "degree.h"
#include <string>
#include <iostream>

using namespace std;

string* ParseStudentData(string studentData) {
	string* parsedData = new string[9];
	int arrIndex = 0;
	int position = 0;
	
	while ((position = studentData.find(',')) != string::npos) {
		parsedData[arrIndex] = studentData.substr(0, position);
		if (studentData.rfind(',') != string::npos) {
			parsedData[8] = studentData.substr(studentData.rfind(',') + 1);
		}
		studentData.erase(0, position + 1);
		arrIndex++;
	}
	return parsedData;
}

int main() {
	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language C++" << endl;
	cout << "Student ID: 011268893" << endl;
	cout << "Name: Burak Aydemir" << endl;
	cout << endl;

	Roster classRoster;
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Burak,Aydemir,baydemi@wgu.edu,30,7,6,14,SOFTWARE" };
	
	int studentArraySize = 0;
	for (string i : studentData) {
		studentArraySize += 1;
	}
	
	for (int i = 0; i < studentArraySize; ++i) {
		string* parsedData = new string[9];
		parsedData = ParseStudentData(studentData[i]);

		string studentID = parsedData[0];
		string firstName = parsedData[1];
		string lastName = parsedData[2];
		string emailAddress = parsedData[3];
		int age = stoi(parsedData[4]);
		int daysInCourse1 = stoi(parsedData[5]);
		int daysInCourse2 = stoi(parsedData[6]);
		int daysInCourse3 = stoi(parsedData[7]);
		DegreeProgram degreeProgram;

		if (parsedData[8] == "SECURITY") {
			degreeProgram = DegreeProgram::SECURITY;
		}
		if (parsedData[8] == "NETWORK") {
			degreeProgram = DegreeProgram::NETWORK;
		}
		if (parsedData[8] == "SOFTWARE") {
			degreeProgram = DegreeProgram::SOFTWARE;
		}

		classRoster.Add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
		delete[] parsedData;
	}
	
	classRoster.PrintAll();

	cout << endl;

	classRoster.PrintInvalidEmails();

	cout << endl;

	for (Student* student : classRoster.classRosterArray) {
		string id = student->GetStudentID();
		classRoster.PrintAverageDaysInCourse(id);
	}

	cout << endl;

	classRoster.PrintByDegreeProgram(SOFTWARE);

	classRoster.Remove("A3");

	cout << endl;

	classRoster.PrintAll();
	
	cout << endl;

	classRoster.Remove("A3");

	return 0;
}