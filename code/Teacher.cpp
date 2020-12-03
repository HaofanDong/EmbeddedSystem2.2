//
// Created by 96540 on 2020/11/25.
//

#include "Teacher.h"
#include <iostream>
#include "Student.h"

using namespace std;


void Teacher::checkApplication(vector<Student*> Students)
{
	cout << "Name\t" << "Date\t" << "Timeslote\t" << endl;
	for (int i = 0; i < (int)Students.size(); i++) {
		if (Students[i]->status == "Under review") {
			cout << Students[i]->name << "\t" << Students[i]->date << "\t" << Students[i]->timeslot << "\t" << endl;
		}
	}
}

void Teacher::permitApplication(vector<Student*> Students)
{
	string temp;
	cout << "----------------------------------------------------------------------------------" << endl;
	cout << "If you want to permit an application, please enter the name of applicant" << endl;
	cout << "If you want to go back to last menu, please enter back" << endl;
	cout << "----------------------------------------------------------------------------------" << endl;
	while (1) {
		cin >> temp;
		if (temp == "back") {
			break;
		}
		else 
		{

			for (int i = 0; i < (int)Students.size(); i++)
			{
				if (Students[i]->name == temp) 
				{
					if (Students[i]->status == "Under review")
					{
						Students[i]->status = "Verified";
						if (Students[i]->date == "Monday") {
							if (Students[i]->timeslot == "Morning")
								Students[i]->weekday->mon.morning = "Occupy";
							else
								Students[i]->weekday->mon.afternoon = "Occupy";
						}
						else if (Students[i]->date == "Tuesday") {
							if (Students[i]->timeslot == "Morning")
								Students[i]->weekday->tue.morning = "Occupy";
							else
								Students[i]->weekday->tue.afternoon = "Occupy";
						}
						else if (Students[i]->date == "Wednesday") {
							if (Students[i]->timeslot == "Morning")
								Students[i]->weekday->wed.morning = "Occupy";
							else
								Students[i]->weekday->wed.afternoon = "Occupy";
						}
						else if (Students[i]->date == "Thursday") {
							if (Students[i]->timeslot == "Morning")
								Students[i]->weekday->thur.morning = "Occupy";
							else
								Students[i]->weekday->thur.afternoon = "Occupy";
						}
						else if (Students[i]->date == "Friday") {
							if (Students[i]->timeslot == "Morning")
								Students[i]->weekday->fri.morning = "Occupy";
							else
								Students[i]->weekday->fri.afternoon = "Occupy";
						}
						cout << "Application verified" << endl;
						cout << "----------------------------------------------------------------------------------" << endl;
						cout << "If you want to permit an application, please enter the name of applicant" << endl;
						cout << "If you want to go back to last menu, please enter back" << endl;
						cout << "----------------------------------------------------------------------------------" << endl;
						break;
					}
					else
					{
						cout << "----------------------------------------------------------------------------------" << endl;
						cout << "This student does not apply for the lab" << endl;
						cout << "If you want to go back to last menu, please enter back" << endl;
						cout << "----------------------------------------------------------------------------------" << endl;
						break;
					}
				}

				else 
				{
					if (i != (int)Students.size() - 1) 
					{
						continue;
					}
					else
					{
						cout << "There is no student named " << temp << endl;
						cout << "----------------------------------------------------------------------------------" << endl;
						cout << "If you want to permit an application, please enter the name of applicant" << endl;
						cout << "If you want to go back to last menu, please enter back" << endl;
						cout << "----------------------------------------------------------------------------------" << endl;
						break;
					}
				}
			}

			



		}
	}
}

void Teacher::operationMenu()
{
	cout << "Welcome " << this->name << "  using this system!" << endl;
	cout << " ----------------------------------\n";
	cout << "|                                  |\n";
	cout << "|          1.Check Application     |\n";
	cout << "|                                  |\n";
	cout << "|          2.Permit Application    |\n";
	cout << "|                                  |\n";
	cout << "|          0.Quit                  |\n";
	cout << "|                                  |\n";
	cout << " ----------------------------------\n";
	cout << "Press number from 0-2 to continue : " << endl;
}
