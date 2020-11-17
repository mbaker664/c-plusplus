#pragma once
#include "student.h"


/* included in main.cpp, may adjust later if needed

const int totStudents = 5;

const string studentData[totStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Mike,Baker,mbak170@wgu.edu,32,60,60,60,SOFTWARE"
};*/

class Roster 
{	


public:
	int lastStudent = -1;
	const static int totStudents = 5;
	Student* classRosterArray[totStudents];
	
	
	void parse(string row);
	void add(string studentID, 
		string fName, 
		string lName, 
		string email, 
		int age, 
		int days1, 
		int days2, 
		int days3, 
		DegreeProgram dp); /*add info*/
	void printAll();
	void printAvgDaysInCourse(string studentID);
	void printInvalidEmails(); /* include '@' and '.' and no spaces*/
	void printByDegreeProgram(DegreeProgram dp); 
	
    void remove(string studentID);  /*find and remove student by ID */
		
	//deconstructor
	~Roster();

};
