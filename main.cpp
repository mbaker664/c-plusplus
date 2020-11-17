#include "roster.h"
#include "student.h"
using namespace std;

int main() 
{
	cout << "C867 - Scripting and Programming - Applications" << " " << "C++" << std::endl;
	cout << "Michael Baker" << std::endl;
	cout << "#000972417" << std::endl << std::endl;

	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Mike,Baker,mbak170@wgu.edu,32,20,30,40,SOFTWARE"
	};

	const int totStudents = 5;
	
	Roster roster;

	for (int i = 0; i < totStudents; i++) roster.parse(studentData[i]);
	
	cout << "All Students: " << std::endl;
	roster.printAll();
	cout << std::endl;

    cout << "Displaying students with invalid email addresses: " << std::endl;
	roster.printInvalidEmails();
	cout << std::endl;

	cout << "Displaying average number of days of each student: " << endl;
	for (int i = 0; i < totStudents; i++)
    {
	roster.printAvgDaysInCourse(roster.classRosterArray[i]->getstudentID());
    }

	cout << std::endl;

	/*The following loop will print all degrees by degree program
	
	for (int i = 1; i < 4; i++) 
	{
		cout << "Students by degree program: " << degreeProgramString[i] << std::endl;
		roster.printByDegreeProgram((DegreeProgram)i);
	}
	*/

	cout << "Students in the Software degree program: " << std::endl;
	roster.printByDegreeProgram(SOFTWARE);

	cout << "Removing student ID A3:" << std::endl;
	roster.remove("A3");
	cout << std::endl;

	cout << "Removing student ID A3:" << std::endl;
	roster.remove("A3");
	cout << std::endl;

	system("pause");
	return 0;

}






