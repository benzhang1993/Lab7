#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include "Course.hpp"
#include <map>
#include <set>


using namespace std;

/*
 * print schedule - outputs course schedule to the screen
 * @param - map: a map containing courses as the key, and an index as the value
 */
void printSchedule(map<Course, int> &map)
{
    /**
     * Compares iteratively if the following courses have conflicting schedule and prints them out
     */
    for(auto i = map.begin(); i != prev(map.end()); ++i) {
        for(auto j = next(i); j != map.end(); ++j) {
            if((j->first.start_time >= i->first.start_time && j->first.start_time <= i->first.finish_time && j->first.day == i->first.day)
                || (j->first.finish_time >= i->first.start_time && j->first.finish_time <= i->first.finish_time && j->first.day == i->first.day)) {
                cout << "CONFLICT" << endl;
                cout << i->first;
                cout << j->first << endl;
            }
        }
    }

    /**
     * Prints the entire course list
     */
    for(auto i = map.begin(); i != map.end(); i++) {
        cout << i->first;
    }
}

int main () {

    /**
     * Creates a map to store courses
     */
    std::map<Course, int> map;

    /**
     * Reads the file and construct courses, then store into map
     */
    ifstream file;
    file.open("../courses.txt");
    string line;
    int key = 0;
    while(getline(file, line)) {
        istringstream iss(line);
        string cname;
        Course::dayOfWeek day;
        char tempDay;
        unsigned int start_time;
        unsigned int end_time;
        iss >> cname;
        iss >> tempDay;
        switch(tempDay) {
            case 'M': day = Course::MON;
                break;
            case 'T': day = Course::TUE;
                break;
            case 'W': day = Course::WED;
                break;
//            case 'Th': day = Course::THUR;
//                break;
            case 'F': day = Course::FRI;
                break;
//            case 'Sat': day = Course::SAT;
//                break;
//            case 'Sun': day = Course::SUN;
//                break;
        }
        iss >> start_time;
        iss >> end_time;
        Course c(cname, day, start_time, end_time);
        pair<std::map<Course, int>::iterator, bool> ret;
        map.insert(pair<Course, int>(c, key++));
    }

    /**
     * Prints the content of the map
     */
    printSchedule(map);

    return 0;
}