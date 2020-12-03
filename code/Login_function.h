#pragma once
#include "Student.h"
#include "Record.h"
#include "Teacher.h"
#include "Admin.h"

Student* login_stu(Record* students);

Teacher* login_tea(Record* teachers);

Admin* login_admin(Record* admins);
