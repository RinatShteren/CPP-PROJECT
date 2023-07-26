/*
Rinat Shteren 
Software Engineering

*/
#include "Soldier.h"

void Soldier:: print()
{
	cout << "ID: " << id << "\n";
	cout << "first name: " << FirstName << endl;
	cout << "last name: " << LastName << endl;
	cout << "num operations: " << numOFoperation << endl;
 }

string Soldier::getFirstName()
{
	return FirstName;
}

string Soldier::getLastName()
{
	return LastName;
}

int Soldier::getNumoperations()
{
	return numOFoperation;
}

