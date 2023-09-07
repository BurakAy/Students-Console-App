#include "roster.h"

Roster::Roster()
{
	this->arrSize = 0;
	Student* classRosterArray = nullptr;
	Student* newStudent = nullptr;
}

Roster::~Roster() 
{
	delete this->newStudent;
}

void Roster::Add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	this->newStudent = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
	
	this->classRosterArray[arrSize] = this->newStudent;
	this->arrSize++;
}

void Roster::Remove(string studentID)
{
	string id;
	bool idNotFound = true;
	int iterator = 0;
	int matchingIndex = 0;

	for (Student* student : this->classRosterArray) {
		id = student->GetStudentID();

		if (studentID == id) {
			matchingIndex = iterator;
			idNotFound = false;

			delete student;
			this->arrSize--;
		}

		iterator++;
	}

	if (idNotFound) {
		cout << "A student with ID: " << studentID << " was not found." << endl;
	}

	if (!idNotFound) {
		for (int i = matchingIndex; i < this->arrSize; ++i)  {
			this->classRosterArray[i] = this->classRosterArray[i + 1];
		}
	}
}

void Roster::PrintInvalidEmails()
{
	for (Student* emailAddress : this->classRosterArray) {
		string email = emailAddress->GetEmail();
		bool hasSpace = false;
		bool hasSpecial = false;

		if (email.find(' ') != string::npos) {
			hasSpace = true;
		}

		if (email.find('@') != string::npos && email.find('.') != string::npos) {
			hasSpecial = true;
		}

		if (hasSpace && hasSpecial || hasSpace && !hasSpecial || !hasSpace && !hasSpecial) {
			cout << email << " - is invalid." << endl;
		}
	}
}

void Roster::PrintAverageDaysInCourse(string studentID)
{
	string id;
	int averageDaysInCourse;

	for (Student* student : this->classRosterArray) {
		id = student->GetStudentID();
		
		if (studentID == id) {
			int days1 = student->GetDaysInCourse(0);
			int days2 = student->GetDaysInCourse(1);
			int days3 = student->GetDaysInCourse(2);

			averageDaysInCourse = (days1 + days2 + days3) / 3;
			cout << "Student ID: " << id << ", average days in course is: " << averageDaysInCourse << endl;
		}
	}
}

void Roster::PrintByDegreeProgram(DegreeProgram degreeProgram)
{
	int studentProgram = 0;

	for (Student* student : this->classRosterArray) {
		int studentProgram = student->GetDegreeProgram();

		if (degreeProgram == studentProgram) {
			student->Print();
		}
	}
}

void Roster::PrintAll()
{
	for (int i = 0; i < this->arrSize; ++i) {
		this->classRosterArray[i]->Print();
	}
}
