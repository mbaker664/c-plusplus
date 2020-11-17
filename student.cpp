#include "student.h"



/*parameterless constructor*/
Student::Student() {
	this->studentID = "";
	this->fName = "";
	this->lName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < numDaysArray; i++) this->numDays[i] = 0;
	
	this->degreeProgram = DegreeProgram::UNDECLARED;
}

/*full constructor*/ 
Student::Student(string studentID, string fName, string lName, string email, int age, int numDays[], DegreeProgram degreeProgram) 
{
	this->studentID = studentID;
	this->fName = fName;
	this->lName = lName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < numDaysArray; i++) this->numDays[i] = numDays[i];
	
	this->degreeProgram = degreeProgram;
}

/*destructor */

Student::~Student() {}

/*getters and setters*/

string Student::getstudentID() { return this->studentID; }
string Student::getfName() { return this->fName; }
string Student::getlName() { return this->lName; }
string Student::getemail() { return this->email; }
int Student::getage() { return this->age; }
int* Student::getnumDays() { return this->numDays; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

void Student::setstudentID(string StudentID) { this->studentID = studentID; }
void Student::setfName(string fName) { this->fName = fName; }
void Student::setlName(string lName) { this->lName = lName; }
void Student::setemail(string email) { this->email = email; }
void Student::setage(int age) { this->age = age; }
void Student::setnumDays(int numDays[]) {
			
	for (int i = 0; i < numDaysArray; i++) this->numDays[i] = numDays[i]; 
}
void Student::setDegreeProgram(DegreeProgram dp) { this->degreeProgram = dp;}


void Student::printHeader()
{
	cout << "Student ID|First Name|Last Name|Email|Age|# Days in course|Degree Program\n";
}

/*print Student Data*/
void Student::print() 
{ 
	cout << this->getstudentID() << '\t';
	cout << this->getfName() << '\t';
	cout << this->getlName() << '\t';
	cout << this->getemail() << '\t';
	cout << this->getage() << '\t';
	cout << this->getnumDays()[0] << ',';
	cout << this->getnumDays()[1] << ',';
	cout << this->getnumDays()[2] << '\t';
	cout << degreeProgramString[this->getDegreeProgram()] << '\n'; /*degree to string */
}

