
/*
Rinat Shteren
Software Engineering
*/
#include "Commander.h"

Commander::Commander(int id, string firstName, string lastName, int num_of_mission, int* P_gradesArry, bool is_combet):PrivateSoldier(id, firstName, lastName, num_of_mission, P_gradesArry)
{
    this->is_combet = is_combet;
}

bool Commander::getCombat()const
{
	return is_combet;
}
void Commander::print()
{
    cout << "commander \n";
    Soldier::print();
    int num_of_mission = this->getNumoperations();
    if (num_of_mission > 0)
    {
        cout << "grades: ";
        for (int i = 0; i < num_of_mission; i++)
            cout << P_gradesArry[i] << " "<<endl;
    }
    cout << "combat: ";

    if (is_combet)
        cout << "yes\n";
    else
        cout << "no \n";
}
string Commander::soldierType()
{
	return "commander";
}

bool Commander::medal()
{
    int num_of_mission = this->getNumoperations();
    if (is_combet)
        if (num_of_mission >= 7)
        {
            int averag = 0;
            for (int i = 0; i < num_of_mission; i++)
            {
                averag += P_gradesArry[i];
            }
            if (averag / num_of_mission > 90)
                return true;
        }
    return false;
}
