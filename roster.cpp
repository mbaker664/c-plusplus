#include "roster.h"

/* parse data for each student */
void Roster::parse(string studentdata) /*parses each row*/
{
	
	int rhs = studentdata.find(","); /* find first comma*/
	string sID = studentdata.substr(0, rhs); /*extract ID before comma*/

	int lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string FN= studentdata.substr(lhs, rhs - lhs); /*first name*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string LN = studentdata.substr(lhs, rhs - lhs); /*last name*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string EM = studentdata.substr(lhs, rhs - lhs); /*email*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int YO = stoi(studentdata.substr(lhs, rhs - lhs)); /*age*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int days1 = stoi(studentdata.substr(lhs, rhs - lhs)); /*days in course 1*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int days2 = stoi(studentdata.substr(lhs, rhs - lhs)); /*days in course 2*/

	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int days3 = stoi(studentdata.substr(lhs, rhs - lhs)); /* days in course 3 */

	lhs = rhs + 1; /* find degree program */
	rhs = studentdata.find(",", lhs);
	DegreeProgram degreeProgram;
	string degreeProgramString = studentdata.substr(lhs, rhs - lhs);
	if (degreeProgramString == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degreeProgramString == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degreeProgramString == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(sID, FN, LN, EM, YO, days1, days2, days3, degreeProgram); /* input each into add method, num days seperately*/
}

void Roster::add(string studentID, string fName, string lName, string email, int age, int days1, int days2, int days3, DegreeProgram dp)
{
	/*add array*/
	int daysarray[3] = { days1,days2,days3 };
	
	classRosterArray[++lastStudent] = new Student(studentID, fName, lName, email, age, daysarray, dp); /*pre-fix because lastStudent = -1 on .h file. may need to adjust with new formula */

}

void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		cout << classRosterArray[i]->getstudentID(); cout << '\t';
		cout << classRosterArray[i]->getfName(); cout << '\t';
		cout << classRosterArray[i]->getlName(); cout << '\t';
		cout << classRosterArray[i]->getemail(); cout << '\t';
		cout << classRosterArray[i]->getage(); cout << '\t';
		cout << "{";
		cout << classRosterArray[i]->getnumDays()[0] << ",";
		cout << classRosterArray[i]->getnumDays()[1] << ",";
		cout << classRosterArray[i]->getnumDays()[2] << "}"; cout <<'\t';
		cout << degreeProgramString[classRosterArray[i]->getDegreeProgram()] << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram dp)
{
	
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		if (Roster::classRosterArray[i]->getDegreeProgram() == dp) classRosterArray[i]->print();	
	}
	cout << std::endl;
}


void Roster::printInvalidEmails()
{
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		string bademail = (classRosterArray[i]->getemail());
		if (bademail.find('@') == string::npos || (bademail.find('.') == string::npos || bademail.find(' ') != string::npos))
		{
			cout << bademail << std::endl;
		}
	}
}



void Roster::printAvgDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		if (this->classRosterArray[i]->getstudentID() == studentID)
		{
			cout << studentID << ":";
			cout << (classRosterArray[i]->getnumDays()[0] + 
				classRosterArray[i]->getnumDays()[1] +
				classRosterArray[i]->getnumDays()[2]) / 3.0 << std::endl;
		}
	}
}


void Roster::remove(string studentID) /*must use student ID as parameter to remove*/ 
{
	bool success = false; 
	for (int i = 0; i <= Roster::lastStudent; i++)
	{
		if (classRosterArray[i]->getstudentID() == studentID)
		{
			success = true; /* found student*/
			if (i < totStudents - 1)
			{
				Student* temp = classRosterArray[i]; /*swap with last book*/
				classRosterArray[i] = classRosterArray[totStudents - 1];
				classRosterArray[totStudents - 1] = temp;
			}
			
			Roster::lastStudent--; /*makes student invisible, but not deleted yet. */
		}
	}
	if (success)
	{
		cout << studentID << " removed." << std::endl << std::endl;
		this->printAll(); /* displays books without the removed one*/
	}
	else cout << studentID << " Not found." << std::endl;

}

Roster::~Roster()
{
	for (int i = 0; i < totStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
