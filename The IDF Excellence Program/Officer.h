/*
Rinat Shteren
Software Engineering
*/
#pragma once 
#include <iostream> 
#include "Soldier.h"

using namespace std;

class Officer : public Soldier
{
protected:
	int sociometry_grade;
public:
	Officer(int id1 = 0, string firstName1 = "", string lastName1 = "", int num_of_mission1 = 0, int sociometry_grade1=0);
	bool medal() override;
	void print() override;
	string soldierType() override;
	int GetSoci_grade()const;
};