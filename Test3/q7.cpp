// Problem 1
class Clock {
    int hour;
    int minute;
    int second;
public:
    bool operator<(Clock otherClock) // Assume 24 hour clock because there is no am/pm time
    {
        int thisTime = (this->hour * 3600) + (this->minute * 60) + this->second;
        int otherTime = (otherClock.hour * 3600) + (otherClock.minute * 60) + otherClock.second;
        return thisTime < otherTime;
    }
};
