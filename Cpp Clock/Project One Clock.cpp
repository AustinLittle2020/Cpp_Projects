/*
 * Project_One_Clock.cpp
 *
 * Date: 11/14/2020
 * Author: Austin Little
 */

#include <iostream>
using namespace std;


class timeIn24Hr; // Declaring 24 hour time class

enum AMPM { // enum that tracks 12 hour clock AM/PM

    AM, PM
}ampm;

class time { // Class used to track time (abstract)
public:

    int hour;
    int minute;
    int second;

    // Virtual functions can be overriden by a derived class
    virtual void addHour() = 0;
    virtual void addMinute() = 0;
    virtual void addSecond() = 0;
};

class timeIn12Hr : public time { // 12 hour time class that inherits from time class

public:
    timeIn12Hr(int h, int m, int s) { // takes parameters of hour, minutes, and seconds
                                     // this function helps modify time
        hour = h;
        minute = m;
        second = s;
        ampm = AM;
    }

    void addHour() { // function adds one hour and checks to see if hour needs reset

        if (hour == 11) {
            hour = 0;
            ampm = ampm == AM ? PM : AM;
        }else {
            hour += 1;
        }
    }

    void addMinute() { // functions adds one minute to the clock and resets if needed
                       // If reset, the function to add an hour is called
        if (minute == 59){
            minute = 0;
            addHour();
        }else {
            minute += 1;
        }
    }

    void addSecond() { // function to add one second to the clock
                      // if seconds resets, function to add one minute is called
        if (second == 59){
            second = 0;
            addMinute();
        }else {
            second += 1;
        }
    }
    // friend gives access to all private and protected members
    friend void showTime(const timeIn12Hr&, const timeIn24Hr&);
};

class timeIn24Hr : public time { // 24 hour time class which inherits from time
                                // function helps modify 24 hour time
public:
    timeIn24Hr(int h, int m, int s) {

        hour = h;
        minute = m;
        second = s;
    }

    void addHour() { // function adds hour to clock
        if (hour == 23) { // Resets hour if needed
            hour = 0;
        }else {
            hour += 1;
        }
    }

    void addMinute() { // function adds one minute to the clock

        if (minute == 59) { // Resets minutes and adds 1 hour if needed
            minute = 0;
            addHour();

        }else {
            minute += 1;
        }
    }

    void addSecond() { // function adds 1 second to the clock
                      // resets seconds and adds one minute if needed
        if (second == 59) {
            second = 0;
            addMinute();

        }else {
            second += 1;
        }
    }
    // friend allows access to all private and protected members
    friend void showTime(const timeIn12Hr&, const timeIn24Hr&);
};

void showMenu() { // Creates the menu

    cout << "***************************" << endl;
    cout << "* 1 - Add One Hour        *" << endl;
    cout << "* 2 - Add One Minute      *" << endl;
    cout << "* 3 - Add One Second      *" << endl;
    cout << "* 4 - Exit Program        *" << endl;
    cout << "***************************" << endl;
}

// function shows time for 12 and 24 hour clock
void showTime(const timeIn12Hr& time12, const timeIn24Hr& time24) {

    cout << "*************************** ***************************" << endl;
    cout << "*     12-Hour Clock       * *      24-Hour Clock      *" << endl;
    cout << "*     ";

    if (time12.hour < 10) {
        cout << "0";
        cout << time12.hour << ":";
    }

    if (time12.minute < 10 ) {
        cout << "0";
        cout << time12.minute << ":";
    }

    if (time12.second < 10) {
        cout << "0";
        cout << time12.second;
    }

    if (ampm == AM) {
        cout << " A M";
    }else {
        cout << " P M";
    }

    cout << "        * *         ";

    if (time24.hour < 10) {
        cout << "0";
        cout << time24.hour << ":";
    }

    if (time24.minute < 10) {
        cout << "0";
        cout << time24.minute << ":";
    }

    if (time24.second < 10) {
        cout << "0";
        cout << time24.second;
    }

    cout << "        *" << endl;
    cout << "*************************** ***************************" << endl;

}

// main function
int main() {

    // makes the clocks
    timeIn12Hr timeIn12HrClock(11, 59, 59);
    timeIn24Hr timeIn24HrClock(23, 59, 59);

    showTime(timeIn12HrClock, timeIn24HrClock);

    while (true) {
        showMenu();

        int userChoice;
        cin >> userChoice;

        // allows for user to use the menu and change the clock accordingly

        if (userChoice == 1) {
            timeIn12HrClock.addHour();
            timeIn24HrClock.addHour();

            showTime(timeIn12HrClock, timeIn24HrClock);
            continue;

        }
        else if (userChoice == 2) {
            timeIn12HrClock.addMinute();
            timeIn24HrClock.addMinute();

            showTime(timeIn12HrClock, timeIn24HrClock);
            continue;

        }
        else if (userChoice == 3) {
            timeIn12HrClock.addSecond();
            timeIn24HrClock.addSecond();

            showTime(timeIn12HrClock, timeIn24HrClock);
            continue;

        }
        else if (userChoice == 4) {
            cout << "Exiting program.";
            exit(0); // exit(0) shows the successful termination of a program
            break;

        }else {
            cout << "Error: Choice not valid. Please enter a valid choice." << endl;
            continue;

        }
    }

}




