class Clock {
private:
    int hour;
    int min;
    int sec;
public:
    int getHour() { return hour; }
    int getMin()  { return min; }
    int getSec()  { return sec; }

ostream &operator<<(ostream &strm, const Clock &time)
{
    int printHour;
    string amPM;
    amPM = "AM";
    if(hour < 12)
    {
        printhour = hour - 12;
        amPM = "PM"
    }
    
    strm << setfill('0') << setw(2) << printHour << ":";
    strm << setfill('0') << setw(2) << getMin() << ":";
    strm << setfill('0') << setw(2) << getSec() << amPM <<endl;
    return strm;
}
};