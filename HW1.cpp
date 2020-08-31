
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

class Clock
{
private:
    int seconds, minutes, hours;


public:
    // Override default constructor
    Clock(){
        this->seconds = 0;
        this->minutes = 0;
        this->hours = 12;
    }

    // getters
    int getSeconds()
    {
        return this->seconds;
    }

    int getMinutes()
    {
        return this->minutes;
    }

    int getHours()
    {
        return this->hours;
    }

    // setters
    void setTime(int hours, int minutes, int seconds){
        // verify inputs
        if(hours > 24 || hours < 0){
            throw "Hour must be a value between 0 and 24";
            // time can't go over 24:00:00
            if(hours == 24 && minutes > 0 && seconds > 0){
                throw "Value can't be over 24:00:00";
            }
        }else if (minutes > 60 || minutes < 0)
        {
            throw "Minutes must be a value between 0 and";
        }else if (seconds > 60 || seconds < 0)
        {
            throw "Seconds must be a value between 0 and";
        }

        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        
    }

    // Return AM or PM
    string naTime(){
        if(hours < 12)
        {
            return "AM";
        }else{
            return "PM";
        }
        
    }
    
};
int main(int argc, char const *argv[])
{
    Clock myClock;

    cout << myClock.naTime();
    return 0;
}


