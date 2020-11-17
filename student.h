#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

// D1 class
class Student
{

public:
	const static int numDaysArray = 3;

private:
	string studentID;
	string fName;
	string lName;
	string email;
	int age;
	int numDays[numDaysArray];
	DegreeProgram degreeProgram;

public:
	//D2 
	Student();
	Student(string studentID, string fName, string lName, string email, int age, int numdays[], DegreeProgram degreeProgram);
	~Student(); /*destructor*/

	//D2 getters
	string getstudentID();
	string getfName();
	string getlName();
	string getemail();
	int getage();
	int* getnumDays();
	DegreeProgram getDegreeProgram();

	//D2 setters
	void setstudentID(string id);
	void setfName(string fName);
	void setlName(string lName);
	void setemail(string email);
	void setage(int age);
	void setnumDays(int numDaysArray[]);
	void setDegreeProgram(DegreeProgram dp); 

	static void printHeader();

	//D2.c all externalaccess and changes to any instacne vaiable of "Students" is done using accessor and mutator functions

	//D2.e print student data
	void print(); /*displays 'this' student's data*/	
};