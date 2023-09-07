#pragma once

#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

class Roster
{
public:
	Roster();
	~Roster();

	void Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void Remove(string studentID);
	void PrintAll();
	void PrintAverageDaysInCourse(string studentID);
	void PrintInvalidEmails();
	void PrintByDegreeProgram(DegreeProgram degreeProgram);
	Student* classRosterArray[5];

private:
	int arrSize;
	Student* newStudent;
};

