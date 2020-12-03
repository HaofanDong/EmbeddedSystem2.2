//
// Created by 96540 on 2020/11/29.
//

#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

Date::Date() {
    mon = {"Monday","Available","Available"};
    tue = {"Tuesday","Available","Available"};
    wed = {"Wednesday","Available","Available"};
    thur = {"Thursday","Available","Available"};
    fri = {"Friday","Available","Available"};
}

void Date::printData() {
    cout<< "Date" << "\t\t" << "Morning" <<"\t\t"<< "Afternoon"<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<< mon.day << "\t\t"<< mon.morning << "\t\t" << mon.afternoon<< endl;
    cout<< tue.day << "\t\t"<< tue.morning << "\t\t" << tue.afternoon<< endl;
    cout<< wed.day << "\t"<< wed.morning << "\t\t" << wed.afternoon<< endl;
    cout<< thur.day << "\t"<< thur.morning << "\t\t" << thur.afternoon<< endl;
    cout<< fri.day << "\t\t"<< fri.morning << "\t\t" << fri.afternoon<< endl;
};
