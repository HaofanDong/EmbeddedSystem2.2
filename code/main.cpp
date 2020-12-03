#include<iostream>
#include<string>
#include <regex>
#include "Student.h"
#include "person.h"
#include "Date.h"
#include "Teacher.h"
#include "Login_function.h"
#include "Admin.h"
#include "Record.h"

using namespace std;

void main_menu();

int get_user_input();

void select_menu_item(int input);

void print_main_menu();

void go_back_to_main_menu();

bool is_integer(std::string num);

void menu_item_1();

void menu_item_2();

void menu_item_3();

void menu_item_4();

int main(int argc, char const* argv[]) {
	main_menu();
	return 0;
}

// init the student and teacher object
Date* date = new Date();
Record* record = new Record();
Student* student1 = new Student("Lang", 123123, "123123", date); // user: Lang; id: 123123, password: 123123 this is a Student
Student* student2 = new Student("Haofan", 222, "bbb", date);
Student* student3 = new Student("Guangchu", 333, "ccc", date);
Teacher* teacher1 = new Teacher("Tom", 444, "ddd");
Teacher* teacher2 = new Teacher("crag", 555, "eee");
Admin* admin1 = new Admin("admin", 123, "123");                  // admin: admin; id: 123 password: 123 this is the admin

void main_menu() {

	// store the student and teacher object
	record->updateRecord(student1);
	record->updateRecord(student2);
	record->updateRecord(student3);
	record->updateRecord(teacher1);
	record->updateRecord(teacher2);  
	record->updateRecord(admin1);

	print_main_menu();
	int input = get_user_input();
	select_menu_item(input);
}

int get_user_input() {
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
			if (input >= 0 && input <= menu_items) {
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

void select_menu_item(int input) {
	switch (input) {
	case 1:
		menu_item_1();
		break;
	case 2:
		menu_item_2();
		break;
	case 3:
		menu_item_3();
		break;
	case 4:
		//menu_item_4();
		exit(1);
	default:
		cout << "You have Logged out." << endl;
		exit(1);
		break;
	}
}

void print_main_menu() {
	std::cout << "\n----- Choose Your Identity -----\n";
	std::cout << "|\t\t\t\t|\n";
	std::cout << "|\t1. Student    \t\t|\n";
	std::cout << "|\t2. Teacher\t\t|\n";
	std::cout << "|\t3. Admin\t\t|\n";
	std::cout << "|\t4. Exit\t\t\t|\n";
	std::cout << "|\t\t\t\t|\n";
	std::cout << "---------------------------------\n";
}

void go_back_to_main() {
	std::string input;
	do {
		std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
		std::cin >> input;
	} while (input != "b" && input != "B");
	main_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
	return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

void menu_item_1() {
	while (1) {
		Student* student = NULL; // creat a student object

		student = login_stu(record);  // login function... return a student object
	Loop:student->operationMenu();
		int select = get_user_input();
		switch (select) {
		case 0:
			cout << "You have Logged out." << endl;
			print_main_menu();
			select_menu_item(get_user_input());
			break;
		case 1:
			student->applyTheLab();
			break;
		case 2:
			student->checkStatus();
			break;
		case 3:
			student->cancelOrder();
			break;
		case 4:
			student->seeAvailable();
			break;
		default:
			cout << "You have Logged out." << endl;
			print_main_menu();
			select_menu_item(get_user_input());
			break;
		}goto Loop;

	}
}
void menu_item_2() {
	while (1) {
		Teacher* teacher = NULL;  // creat a teacher object

		teacher = login_tea(record);  // login function... return a teacher object
	Loop2:teacher->operationMenu();
		int select = get_user_input();
		switch (select) {
		case 0:
			cout << "You have Logged out." << endl;
			print_main_menu();
			select_menu_item(get_user_input());
			break;
		case 1:
			teacher->checkApplication(record->Students);
			break;
		case 2:
			teacher->permitApplication(record->Students);
			break;
		default:
			cout << "You have Logged out." << endl;
			print_main_menu();
			select_menu_item(get_user_input());
			break;
		}goto Loop2;
	}


}
void menu_item_3() {
	while (1) {
		Admin* admin = NULL;  // creat a admin object

		admin = login_admin(record);  // login function... return a admin object
	Loop3:admin->operationMenu();
		int select = get_user_input();
		switch (select) {
		case 0:
			cout << "You have Logged out." << endl;
			print_main_menu();
			select_menu_item(get_user_input());
			break;
		case 1:
			admin->checkApplication(record);
			break;
		case 2:
			admin->permitApplication(record);
			break;
		case 3:
			admin->cancelApplication(record);
			break;
		case 4:
			admin->changeInfo(record);
			break;
		case 5:
			admin->addUser(record);
			break;
		default:
			cout << "You have Logged out." << endl;
			print_main_menu();
			select_menu_item(get_user_input());
			break;
		}goto Loop3;
	}
}
// void menu_item_4() {
//   std::cout << "\n>> Menu 4\n";
//   std::cout << "\nPlease enter 2 integer\n";
//   int a,b;
//   std::cin >>a >>b;
//   std::cout << "the sum of a and b is " << (float)a/b <<std::endl;
//   // you can call a function from here that handles menu 4
//   go_back_to_main();
// }