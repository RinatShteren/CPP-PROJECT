/*
Rinat Shteren
Software Engineering
*/
#pragma once
#include <iostream>
using namespace std;
class Soldier
{
protected:
	int id;
	string FirstName;
	string LastName;
	int numOFoperation;
public:
	Soldier(int id1 = 0, string firstName1 = "", string lastName1 = "", int num_of_mission1 = 0) :
		id(id1), FirstName(firstName1), LastName(lastName1), numOFoperation(num_of_mission1) {};
	virtual void print()=0;
	virtual string soldierType()=0;
	virtual bool medal()=0;
	string getFirstName();
	string getLastName();
	int getNumoperations();
};