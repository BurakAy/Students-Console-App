#pragma once

#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:
	Student();
	~Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string emailAddress);
	void SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void SetDegreeProgram(DegreeProgram degreeProgram);
	
	string GetStudentID() const;
	string GetFirstName() const;
	string GetLastName() const;
	string GetEmail() const;
	int GetDaysInCourse(int coursePosition) const;
	int GetDegreeProgram() const;

	void Print() const;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;
};

