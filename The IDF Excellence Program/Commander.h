/*
Rinat Shteren
Software Engineering
*/
#pragma once 
#include <iostream>
using namespace std;
#include "PrivateSoldier.h"
class Commander :public PrivateSoldier
{
protected:
	bool is_combet;
public:
	Commander(int id, string firstName, string lastName, int num_of_mission ,int* P_gradesArry,bool is_combet);
	bool getCombat()const;
	virtual void print()override;
	virtual string soldierType()override;
	virtual bool medal()override;
};