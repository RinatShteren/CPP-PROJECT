/*
Rinat Shteren
Software Engineering
*/
#pragma once
#include "Soldier.h"
class PrivateSoldier: public Soldier
{
protected:
	int* P_gradesArry;
public:
	PrivateSoldier(int id1 = 0, string firstName1 = "", string lastName1 = "", int num_of_mission1 = 0,int* P_gradesArry1= nullptr);
	~PrivateSoldier();
	virtual void print() override;
	virtual string soldierType()override;
	virtual bool medal()override;
};
