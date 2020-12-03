//
// Created by 96540 on 2020/11/29.
//

#include "Admin.h"
#include <iostream>

using namespace std;

// show the students who are applying
void Admin::checkApplication(Record* record)
{
	cout << "Name\t" << "Date\t" << "Time slot\t" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	for(auto i : record->Students )
		if (i->status == "Under review") {
			cout << i->name << "\t" << i->date << "\t" << i->timeslot << "\t" << endl;
		}
	cout << "------------------------------------------------------------------------" << endl;
}

void Admin::permitApplication(Record* record)
{
	checkApplication(record); // show who is apply the lab
	cout << "------------------------------------------------------------------------" << endl;
	cout << "If you want to permit an application, please enter the name of applicant" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cin >> name;

	// find the input in the Students vector
	for (auto i : record->Students)
	{
		if (i->name == name)
		{
			//set the student's status
			if (i->status == "Under review")
			{
				i->status = "Verified";
				cout << "-----------------------" << endl;
				cout << "Application verified" << endl;
				cout << "-----------------------" << endl;
				// change the time slot
				if (i->date == "Monday") {
					if (i->timeslot == "Morning")
						i->weekday->mon.morning = "Occupy";
					else
						i->weekday->mon.afternoon = "Occupy";
				}
				else if (i->date == "Tuesday") {
					if (i->timeslot == "Morning")
						i->weekday->tue.morning = "Occupy";
					else
						i->weekday->tue.afternoon = "Occupy";
				}
				else if (i->date == "Wednesday") {
					if (i->timeslot == "Morning")
						i->weekday->wed.morning = "Occupy";
					else
						i->weekday->wed.afternoon = "Occupy";
				}
				else if (i->date == "Thursday") {
					if (i->timeslot == "Morning")
						i->weekday->thur.morning = "Occupy";
					else
						i->weekday->thur.afternoon = "Occupy";
				}
				else if (i->date == "Friday") {
					if (i->timeslot == "Morning")
						i->weekday->fri.morning = "Occupy";
					else
						i->weekday->fri.afternoon = "Occupy";
				}

				cout << "If you want to permit another applications, please enter back to the Operation Menu" << endl;
				cout << "-------------------------------------------------------------------------------------" << endl;
				cin >> name;
				if (name == "back")
				{
					break;
				}
			}
			else
			{
				cout << "This student does not apply for the lab" << endl;
				break;
			}
		}
		// if input does not match with any Student
		if (i == record->Students.back())
		{
			cout << "There is no student named " << name << endl;
			cout << "Please enter back to the Operation Menu" << endl;
			cout << "----------------------------------------" << endl;
			cin >> name;
			if (name == "back")
			{
				break;
			}			
		}
	}
}

void Admin::cancelApplication(Record* record)
{
	string name;

    //show the booked student
	cout << "Name\t" << "Date\t" << "Time slot\t" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	for (auto i : record->Students)
		if (i->status == "Verified") {
			cout << i->name << "\t" << i->date << "\t" << i->timeslot << "\t" << endl;
		}
	cout << "------------------------------------------------------------------------" << endl; 

	cout << "------------------------------------------------------------------------" << endl;
	cout << "If you want to cancel an application, please enter the name of applicant" << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cin >> name;

	for (auto i : record->Students)
	{
		if (i->name == name)
		{	
			if (i->status == "Verified")
			{
				i->status = "None";// set student's status to the default

				// set the lab's status to the available
				if (i->date == "Monday") {
					if (i->timeslot == "Morning")
						i->weekday->mon.morning = "Available";
					else
						i->weekday->mon.afternoon = "Available";
				}
				else if (i->date == "Tuesday") {
					if (i->timeslot == "Morning")
						i->weekday->tue.morning = "Available";
					else
						i->weekday->tue.afternoon = "Available";
				}
				else if (i->date == "Wednesday") {
					if (i->timeslot == "Morning")
						i->weekday->wed.morning = "Available";
					else
						i->weekday->wed.afternoon = "Available";
				}
				else if (i->date == "Thursday") {
					if (i->timeslot == "Morning")
						i->weekday->thur.morning = "Available";
					else
						i->weekday->thur.afternoon = "Available";
				}
				else if (i->date == "Friday") {
					if (i->timeslot == "Morning")
						i->weekday->fri.morning = "Available";
					else
						i->weekday->fri.afternoon = "Available";
				}

				cout << "-----------------------" << endl;
				cout << "Application canceled" << endl;
				cout << "-----------------------" << endl;
				cout << "If you want to cancel another applications, please enter back to the Operation Menu" << endl;
				cout << "-------------------------------------------------------------------------------------" << endl;
				cin >> name;
				if (name == "back")
				{
					break;
				}
			}
			else
			{
				cout << "This student does not apply for the lab" << endl;
				break;
			}
		}
		// if there is no student match with the input
		if (i == record->Students.back())
		{
			cout << "There is no student named " << name << endl;
			cout << "Please enter back to the Operation Menu" << endl;
			cout << "-----------------------------------------" << endl;
			cin >> name;
			if (name == "back")
			{
				break;
			}
		}
	}
	
}

void Admin::changeInfo(Record* record)
{
	string name;
	string password;
	bool stage = true; // flag for the search
	showAlluser(record);  // show all user's information

	cout << "----------------------------------------------------------------------------" << endl;
	cout << "If you want to change someone's information, please enter the name of people" << endl;
	cout << "----------------------------------------------------------------------------" << endl;
	cin >> name;

	// find the name in Student vector and Teacher vector
	for (auto i : record->Students)
	{
		if (name == i->name)
		{
			cout << "Please enter the new password for this people" << endl;
			cin >> password;
			i->changPassword(password);
			stage = false;
			cout << "----------------------------" << endl;
			cout << "You have changed " << name << "'s password" << endl;
			cout << "----------------------------" << endl;
			cout << "If you want to change some else, please enter back to the Operation Menu" << endl;
			cout << "-------------------------------------------------------------------------------------" << endl;
			cin >> name;
			if (name == "back")
			{
				break;
			}
			break;
			break;
		}
	}

	if (stage)
	{
		for (auto i : record->Teachers)
		{
			if (name == i->name)
			{
				cout << "Please enter the new password for this people" << endl;
				cin >> password;
				i->changPassword(password);
				cout << "----------------------------" << endl;
				cout << "You have changed "<< name<< "'s password" << endl;
				cout << "----------------------------" << endl;
				cout << "If you want to change someone else, please enter back to the Operation Menu" << endl;
				cout << "-------------------------------------------------------------------------------------" << endl;
				cin >> name;
				if (name == "back")
				{
					break;
				}
				break;
			}
			// if the input does not match with either two vector
			if (i == record->Teachers.back())
			{
				cout << "There is no people named " << name << endl;
				cout << "Please enter back to the Operation Menu" << endl;
				cout << "-----------------------------------------" << endl;
				cin >> name;
				if (name == "back")
				{
					break;
				}
			}
		}
	}



	
}

void Admin::addUser(Record* record)
{
	cout << "--------------------------------" << endl;
	cout << "Please enter the new user's role" << endl;
	cout << "--------------------------------" << endl;
	cout << "1.---------Teacher--------------" << endl;
	cout << "2.---------Student--------------" << endl;
	cout << "Please enter the number" << endl;
	int temp = get_user_input();
	switch (temp) {
	case 1:
		this->addTeacher(record);
		cout << "You have successfully add a Teacher! " << endl;
		cout << "-------------------------------------" << endl;
		break;
	case 2:
		this->addStudent(record);
		cout << "You have successfully add a Student! " << endl;
		cout << "-------------------------------------" << endl;
		break;
	default:
		cout << "Please enter a reasonable number from 1 to 5. " << endl;
		operationMenu(); break;
	}

}

void Admin::addStudent(Record* record)
{
	string name;
	string password;
	int id;
	Date* weekday;
	
	cout << "-------------------------------------" << endl;
	cout << "Please enter the new student's name:" << endl;
	cin >> name;
	cout << "-------------------------------------" << endl;
	cout << "Please enter the new student's id:" << endl;
	cin >> id;
	cout << "-------------------------------------" << endl;
	cout << "Please enter the new student's password:" << endl;
	cin >> password;
	cout << "-------------------------------------" << endl;
	weekday = record->Students.at(0)->weekday;
	Student* newStudent = new Student(name, id, password , weekday);
	record->Students.push_back(newStudent);
}

void Admin::addTeacher(Record* record)
{
	string name;
	string password;
	int id;

	cout << "-------------------------------------" << endl;
	cout << "Please enter the new teacher's name:" << endl;
	cin >> name;
	cout << "-------------------------------------" << endl;
	cout << "Please enter the new teacher's id:" << endl;
	cin >> id;
	cout << "-------------------------------------" << endl;
	cout << "Please enter the new teacher's password:" << endl;
	cin >> password;
	cout << "-------------------------------------" << endl;
	Teacher* newTeacher = new Teacher(name, id, password);
	record->Teachers.push_back(newTeacher);
}


void Admin::operationMenu()
{
	cout << "Welcome " << this->name << "  using this system!" << endl;
	cout << " ----------------------------------\n";
	cout << "|                                  |\n";
	cout << "|        1.Check Application       |\n";
	cout << "|                                  |\n";
	cout << "|        2.Permit Application      |\n";
	cout << "|                                  |\n";
	cout << "|        3.Cancel Application      |\n";
	cout << "|                                  |\n";
	cout << "|        4.Change user's password  |\n";
	cout << "|                                  |\n";
	cout << "|        5.Add User                |\n";
	cout << "|                                  |\n";
	cout << "|        0.Quit                    |\n";
	cout << " ----------------------------------\n";
	cout << "Press number from 0-5 to continue : " << endl;
}

void Admin::showAlluser(Record* record)
{
	cout << "Student" << endl;
	cout << "------------------------------------------" << endl;
	cout << "id" << "\t\t" << "name" << "\t\t" << "password" << endl;
	cout << "------------------------------------------" << endl;
	for (auto i : record->Students)
	{
		cout << i->id << "\t\t"<< i->name << "\t\t" << i->getPassword() <<endl;
	}
	cout << "------------------------------------------" << endl;
	cout << "Teacher" << endl;
	cout << "------------------------------------------" << endl;
	cout << "id" << "\t\t" << "name" << "\t\t" << "password" << endl;
	for (auto i : record->Teachers)
	{
		cout << i->id << "\t\t" << i->name << "\t\t" << i->getPassword() << endl;
	}
	cout << "------------------------------------------" << endl;
}

int Admin::get_user_input()
{
	int input;
	std::string input_string;
	bool valid_input = false;
	int menu_items = 5;

	do {
		std::cout << "\nSelect item: ";
		std::cin >> input_string;
		valid_input = is_integer(input_string);
		// if input is not an integer, print an error message
		if (valid_input == false) {
			std::cout << "Enter an integer!\n";
		}
		else {  // if it is an int, check whether in range
			input = std::stoi(input_string);  // convert to int
			if (input >= 1 && input <= menu_items) {
				valid_input = true;
			}
			else {
				std::cout << "Invalid menu item!\n";
				valid_input = false;
			}
		}
	} while (valid_input == false);

	return input;
}

bool Admin::is_integer(std::string num)
{
	return std::regex_match(num, std::regex("[+-]?[0-9]+"));
	return false;
}
