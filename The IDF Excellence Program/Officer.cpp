/*
Rinat Shteren
Software Engineering
*/
#include "Officer.h"


Officer::Officer(int id, string firstName, string lastName, int num_of_mission, int sociometry_grade) :Soldier(id, firstName, lastName, num_of_mission)
{
	this->sociometry_grade = sociometry_grade;
}

int Officer::GetSoci_grade()const
{
	return sociometry_grade;
}

bool Officer::medal()
{
	if (numOFoperation > 2 && sociometry_grade > 92)
	{
		return true;
	}
	return false;
}

void Officer::print()
{
	cout << "officer \n";
	Soldier::print();
	cout << "sociometric score: " << sociometry_grade << endl;

}

string Officer::soldierType()
{
	return "officer";
}
