
#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"Student.h"
#include "Date.h"
#include "Teacher.h"

class Admin;  //slove the double include problem

class Record
{
public:
	Record();

	Admin* a;
	void updateRecord(Student* stu);  // add the student object to the vector
	void updateRecord(Teacher* tea);  // add the teacher object to the vector
	void updateRecord(Admin* adm);

	int size;

	vector<Student*> Students;  // store the student object
	vector<Teacher*> Teachers;  // store the teacher object
	vector<Admin*> Admins;


	/*map<int, Student> Data;*/

};


