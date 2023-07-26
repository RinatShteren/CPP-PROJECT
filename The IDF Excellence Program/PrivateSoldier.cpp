/*
Rinat Shteren
Software Engineering
*/
#include "PrivateSoldier.h"


PrivateSoldier::PrivateSoldier(int id, string firstName, string lastName, int num_of_mission, int* P_gradesArry1):Soldier(id, firstName, lastName, num_of_mission)
{
    if (P_gradesArry1)
    {
        P_gradesArry = new int[num_of_mission];
        for (int i = 0;i < num_of_mission;i++)
        {
            P_gradesArry[i] = P_gradesArry1[i];
        }
    }
    else
        P_gradesArry = nullptr;
}
PrivateSoldier::~PrivateSoldier()
{
	delete[] P_gradesArry;
}

void PrivateSoldier::print()
{
    cout << "private \n";
	Soldier::print();
    int num_of_mission = this->getNumoperations();
    if (num_of_mission > 0)
    {
        cout << "grades: ";
        for (int i = 0; i < num_of_mission; i++)
            cout << P_gradesArry[i] << " ";
    }
    cout << endl;
}

string PrivateSoldier::soldierType()
{
	return "private";
}

bool PrivateSoldier::medal()
{
    int everage = 0;
    int num_of_mission = this->getNumoperations();
    if (num_of_mission >= 10)
    {
        for (int i = 0; i < num_of_mission; i++)
            everage += P_gradesArry[i];
        if (everage / num_of_mission > 95)
            return true;
    }
    return false;
}


