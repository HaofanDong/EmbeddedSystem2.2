//
// Created by 96540 on 2020/11/29.
//

#pragma once

#include "Record.h"
#include "person.h"

#include "Student.h"
#include "Teacher.h"
#include "Date.h"
#include<iostream>
#include<vector> 
#include <regex>

class Admin : public person {
public:
	Admin(string name, int id, string password) : person(name, id, password) {};

	void checkApplication(Record* record);

	void permitApplication(Record* record);

	void cancelApplication(Record* record);

	void changeInfo(Record* record);

	void addUser(Record* record);

	void addStudent(Record* record);

	void addTeacher(Record* record);

	void operationMenu();

	void showAlluser(Record* record);

	int get_user_input();
	bool is_integer(std::string num);
};

