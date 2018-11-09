#include "Course.hpp"

using namespace std;

/**
 * Default constructor
 * @param title Title of course
 * @param day Day of course
 * @param start_time Start time
 * @param finish_time Finish time
 */
Course::Course (string title, dayOfWeek day, unsigned int start_time, unsigned int finish_time) : title (title), day (day), start_time (start_time), finish_time (finish_time)
{
}

/**
 * Copy constructor for course
 */
Course::Course (const Course & m) : title (m.title), day (m.day), start_time (m.start_time), finish_time (m.finish_time)
{
}

/**
 * Overloaded assignment operator for course
 * @param m course to assign
 * @return the assigned course
 */
Course & Course::operator =(const Course & m) {
    this->title = m.title;
    this->day = m.day;
    this->start_time = m.start_time;
    this->finish_time = m.finish_time;
    return *this;
}

/**
 * Overloaded equality operator, two courses are equal if every attribute are equal
 */
bool Course::operator == (const Course & m) const {
    if (this->title.compare(m.title) == 0 && this->day == m.day && this->start_time == m.start_time &&
        this->finish_time == m.finish_time) {
        return true;
    } else {
        return false;
    }
}

/**
 * Overloaded strict weak ordering operator
 * Courses are ordered in orders of day, start time, finish time, and title
 */
bool Course::operator < (const Course & m) const
{
    if (this->day < m.day) {
        return true;
    }
    else if (this->day > m.day) {
        return false;
    }
    else {
        if (this->start_time < m.start_time) {
            return true;
        }
        else if (this->start_time > m.start_time) {
            return false;
        }
        else {
            if(this->title.compare(m.title) > 0) {
                return true;
            }
            else {
                return false;
            }
        }
    }
}

/**
 * Overloaded insertion operator
 * @param os the output stream
 * @param m Course to output
 * @return the output stream
 */
ostream & operator << (ostream &os, const Course & m)
{
    string day;
    switch(m.day) {
        case 0: day = "MON";
        break;
        case 1: day = "TUE";
        break;
        case 2: day = "WED";
        break;
        case 3: day = "THUR";
        break;
        case 4: day = "FRI";
        break;
        case 5: day = "SAT";
        break;
        case 6: day = "SUN";
        break;
    }
    os << m.title << " " << day << " " << m.start_time << " " << m.finish_time << endl;
    return os;
}