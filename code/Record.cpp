#include "Record.h"
#include "Date.h"
#include "Admin.h"

Record::Record() {
	size = 0;
}
void Record::updateRecord(Student* stu)
{
	Students.push_back(stu);
	size++;
}

void Record::updateRecord(Teacher* tea)
{
	Teachers.push_back(tea);
	size++;
}

void Record::updateRecord(Admin* adm)
{
	Admins.push_back(adm);
	size++;
}

