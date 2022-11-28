#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>
using namespace std;

string FindID(string name, ifstream& infoFS) 
{


	string name1, id;
	while (infoFS >> name1 >> id)
	{
		if (name1 == name)
			return id;
	}
	throw runtime_error("Student ID not found for " + name);

}

string FindName(string ID, ifstream& infoFS) {

	/* Type your code here. */
	string name1, id;
	while (infoFS >> name1 >> id)
	{
		if (id == ID)
			return id;
	}
	throw runtime_error("Student Name not found for " + ID);

}

int main() 
{
	int userChoice;
	string studentName;
	string studentID;

	string studentInfoFileName;
	ifstream studentInfoFS;

	// Read the text file name from user
	cin >> studentInfoFileName;

	// Open the text file
	studentInfoFS.open(studentInfoFileName);

	// Read search option from user. 0: FindID(), 1: FindName()
	cin >> userChoice;

	// FIXME: FindID() and FindName() may throw an Exception.
	// Insert a try/catch statement to catch the exception and output the exception message.
	try 
    {
		if (userChoice == 0) 
    {
			cin >> studentName;
			studentID = FindID(studentName, studentInfoFS);
			cout << studentID << endl;
		}
		else 
    {
			cin >> studentID;
			studentName = FindName(studentID, studentInfoFS);
			cout << studentName << endl;
		}
	}
	catch (runtime_error er)
	{
		cout << er.what() << endl;
	}

	studentInfoFS.close();
	return 0;
}