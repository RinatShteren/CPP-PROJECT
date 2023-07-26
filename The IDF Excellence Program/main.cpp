/*
Rinat Shteren
Software Engineering

The user interface features a meticulously constructed data structure encompassing various soldier types,
facilitating dynamic insertion, removal, and extraction of specific categories.
*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
#include "Soldier.h"
#include "PrivateSoldier.h"
#include "Commander.h"
#include "Officer.h"

enum option {

	EXIT, // End of the program
	ADD_NEW_SOLDIER, // Adding a new soldier
	DESERVES_MEDAL, // Printing details of all soldiers eligible for a citation
	HIGHEST_SOCIOMETRIC, // Printing the name (last and first) of the soldier with the highest sociometric score
	PRIVATE_MEDAL_COUNT, // Printing the number of rookie soldiers eligible for a citation
	NONCOMBAT_COMMANDER, // Printing names (last and first) of non-combat commanders
	SUPER_SOLDIER, // Printing an appropriate message, is there a soldier who has participated in more than 15 military operations
	REMOVE_OFFICER, // Deleting all officers who have not participated at all in a military operation
};
void add(vector <Soldier*>& v)
{
	int choice, id, numOfOperations, combat, socio;
	string firstName, lastName;
	Soldier* sol;
	cout << "Choose A soldier\n";
	cout << "Enter 1 to add a private\n";
	cout << "Enter 2 to add a commander\n";
	cout << "Enter 3 to add an officer\n";
	cin >> choice;
	cout << "Enter ID, First name, Last name and Number of operations\n";
	cin >> id >> firstName >> lastName >> numOfOperations;
	int* gradesArry = new int[numOfOperations];  //grades array
	if (numOfOperations > 0)
	{
		if (choice == 2 || choice == 1)/*if you are private or commander*/
			{
				cout << "enter " << numOfOperations << " grades\n";
				
				for (int i = 0; i < numOfOperations; i++)
					cin >> gradesArry[i] ;
			}
	}
	if (choice == 1)/*if you are private */
	{
		sol = new PrivateSoldier(id, firstName, lastName, numOfOperations, gradesArry);
		v.push_back(sol);
	}
	if (choice == 2)/*if you are  commander*/
	{
		cout << "enter 1 if the soldier is combat and 0 if not\n";
		cin >> combat;
		sol = new Commander(id, firstName, lastName, numOfOperations, gradesArry, combat);
		v.push_back(sol);
	}
	if (choice == 3)/*if you are private or officer*/
	{
		cout << "enter the sociometric score\n";
		cin >> socio;
		sol = new Officer(id, firstName, lastName, numOfOperations, socio);
		v.push_back(sol);
	}

}
void printMedalList(vector <Soldier*>& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i]->medal())
			v[i]->print();
	}


}
Soldier* highestSociometricScore(vector <Soldier*>& v)
{
	int maximumGRADE = 0;
	vector <Soldier*>::iterator it;
	Soldier* pointerTOmax = NULL;
	for (it = v.begin(); it != v.end(); it++)
	{
		if ((*it)->soldierType() == "officer" )
		{
			if (((Officer*)*it)->GetSoci_grade() > maximumGRADE)/*casting *it to officer for been able to get soci grade*/
			{
				maximumGRADE = ((Officer*)*it)->GetSoci_grade();
				pointerTOmax = *it;
			}
		}
	}
	if (maximumGRADE == 0)
		return NULL;
	return pointerTOmax;
}

int main()
{
	Soldier* s;
	string arr[50];
	vector <Soldier*> v;   // Vector of soldiers
	int op,count=0;
	bool myFLAG = 0;
	vector <Soldier*>::iterator it;
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\" << std::endl;
	cout << "WELCOME!\n" << std::endl;
	cout << "Please choose what you would like to do" << std::endl;
	cout << "0 - Program termination" << std::endl;
	cout << "1 - Adding a new soldier" << std::endl;
	cout << "2 - Printing data of soldiers eligible for commendation" << std::endl;
	cout << "3 - Printing the name (last and first) of the officer with the highest sociometric score" << std::endl;
	cout << "4 - Printing the number of rookie soldiers eligible for citation" << std::endl;
	cout << "5 - Printing names (last and first) of non-combat commanders" << std::endl;
	cout << "6 - Printing a message whether there is any soldier in the list who participated in more than 15 operations" << std::endl;
	cout << "7 - Removing officers from the vector who did not participate in any operations" << std::endl;
	cout << "\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n" << std::endl;
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:add(v);  						
			break;
		case DESERVES_MEDAL:printMedalList(v); 
			break;
		case HIGHEST_SOCIOMETRIC:    
			s = highestSociometricScore(v); 
			cout << "Officer with the highest sociometric score: "<<endl;
			if (s != NULL)
			{
				cout << s->getFirstName() << ' ' << s->getLastName() << endl;
			}
	

			break;
		case PRIVATE_MEDAL_COUNT:  cout << "number of privates that received medals: ";
			for (it = v.begin(); it != v.end(); it++)//Printing the number of rookie soldiers eligible for citation
			{
				if ((*it)->soldierType() == "private")
				{
					if (((PrivateSoldier*)*it)->medal())
					{
						count++;
					}
				}
			} 
				cout <<count<< endl;
			break;
		case NONCOMBAT_COMMANDER: cout << "list of noncombat commanders: ";    //Printing names (last and first) of non-combat commanders
			count = 0;
			for (it = v.begin(); it != v.end(); it++)
			{
				if ((*it)->soldierType() == "commander")
				{
					if (!((Commander*)*it)->getCombat())
					{
						arr[count] = ((Commander*)*it)->getFirstName() + " " + ((Commander*)*it)->getLastName();
						count++;
						
					}
				}
			}
			for (int i = 0;i <= count;i++)
			{
				cout << arr[i];
				cout << " ";
			}
				cout << endl;
			break;
		case SUPER_SOLDIER:
	
			for (int i = 0; i < v.size(); i++)
			{
				if (v[i]->getNumoperations() > 15)
					myFLAG = 1;
			}
			if (myFLAG) 
				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER:
			for (it = v.begin(); it != v.end(); it++)
			{
				if ((*it)->soldierType() == "officer")
				{
					if (((Officer*)*it)->getNumoperations() == 0)
					{
						v.erase(it);
					}
				}
			}
			for (vector <Soldier*>::iterator it = v.begin(); it != v.end(); it++)
			{
				(*it)->print();
			}
				break;
		};
		cout << "\n Please choose what you would like to do" << std::endl;
		cout << "0 - Program termination" << std::endl;
		cout << "1 - Adding a new soldier" << std::endl;
		cout << "2 - Printing data of soldiers eligible for commendation" << std::endl;
		cout << "3 - Printing the name (last and first) of the officer with the highest sociometric score" << std::endl;
		cout << "4 - Printing the number of rookie soldiers eligible for citation" << std::endl;
		cout << "5 - Printing names (last and first) of non-combat commanders" << std::endl;
		cout << "6 - Printing a message whether there is any soldier in the list who participated in more than 15 operations" << std::endl;
		cout << "7 - Removing officers from the vector who did not participate in any operations\n" << std::endl;
		cin >> op;
	}
	return 0;
}

/*
CODE EXEMPLE-

\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
WELCOME!

Please choose what you would like to do
0 - Program termination
1 - Adding a new soldier
2 - Printing data of soldiers eligible for commendation
3 - Printing the name (last and first) of the officer with the highest sociometric score
4 - Printing the number of rookie soldiers eligible for citation
5 - Printing names (last and first) of non-combat commanders
6 - Printing a message whether there is any soldier in the list who participated in more than 15 operations
7 - Removing officers from the vector who did not participate in any operations
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

1
Choose A soldier
Enter 1 to add a private
Enter 2 to add a commander
Enter 3 to add an officer
1
Enter ID, First name, Last name and Number of operations
23232323
avi
cohen
5
enter 5 grades
100
100
89
87
69

 Please choose what you would like to do
0 - Program termination
1 - Adding a new soldier
2 - Printing data of soldiers eligible for commendation
3 - Printing the name (last and first) of the officer with the highest sociometric score
4 - Printing the number of rookie soldiers eligible for citation
5 - Printing names (last and first) of non-combat commanders
6 - Printing a message whether there is any soldier in the list who participated in more than 15 operations
7 - Removing officers from the vector who did not participate in any operations

1
Choose A soldier
Enter 1 to add a private
Enter 2 to add a commander
Enter 3 to add an officer
2
Enter ID, First name, Last name and Number of operations
262657843
shira
shalom
2
enter 2 grades
70
76
enter 1 if the soldier is combat and 0 if not
1

 Please choose what you would like to do
0 - Program termination
1 - Adding a new soldier
2 - Printing data of soldiers eligible for commendation
3 - Printing the name (last and first) of the officer with the highest sociometric score
4 - Printing the number of rookie soldiers eligible for citation
5 - Printing names (last and first) of non-combat commanders
6 - Printing a message whether there is any soldier in the list who participated in more than 15 operations
7 - Removing officers from the vector who did not participate in any operations

4
number of privates that received medals: 0

 Please choose what you would like to do
0 - Program termination
1 - Adding a new soldier
2 - Printing data of soldiers eligible for commendation
3 - Printing the name (last and first) of the officer with the highest sociometric score
4 - Printing the number of rookie soldiers eligible for citation
5 - Printing names (last and first) of non-combat commanders
6 - Printing a message whether there is any soldier in the list who participated in more than 15 operations
7 - Removing officers from the vector who did not participate in any operations

5
list of noncombat commanders:

 Please choose what you would like to do
0 - Program termination
1 - Adding a new soldier
2 - Printing data of soldiers eligible for commendation
3 - Printing the name (last and first) of the officer with the highest sociometric score
4 - Printing the number of rookie soldiers eligible for citation
5 - Printing names (last and first) of non-combat commanders
6 - Printing a message whether there is any soldier in the list who participated in more than 15 operations
7 - Removing officers from the vector who did not participate in any operations

7
private
ID: 23232323
first name: avi
last name: cohen
num operations: 5
grades: 100 100 89 87 69
commander
ID: 262657843
first name: shira
last name: shalom
num operations: 2
grades: 70
76
combat: yes

 Please choose what you would like to do
0 - Program termination
1 - Adding a new soldier
2 - Printing data of soldiers eligible for commendation
3 - Printing the name (last and first) of the officer with the highest sociometric score
4 - Printing the number of rookie soldiers eligible for citation
5 - Printing names (last and first) of non-combat commanders
6 - Printing a message whether there is any soldier in the list who participated in more than 15 operations
7 - Removing officers from the vector who did not participate in any operations



*/